//
// Created by kolos on 7/23/20.
//

#include "SerialConnection.h"


SerialConnection::SerialConnection(CraftState& craftState,
               const std::string &interfaceFilePath,
               int baudRate,
               bool startWorker,
               int parityBit,
               int stopBits,
               int hardwareFlowControl,
               int bitsPerByte) : craftState(craftState){

    fileDescriptor = open(interfaceFilePath.c_str(), O_RDWR);

    if (fileDescriptor < 0) {
        std::cout << "Error " << errno << " from open: " << strerror(errno) << std::endl;
    }

    //  Create configuration structure
    struct termios2 tty;
    memset(&tty, 0, sizeof tty);

//      Read in existing settings, and handle any error
//    if(tcgetattr(fileDescriptor, &tty) != 0) {
//        std::cout << "Error " << errno << " from tcgetattr: " << strerror(errno) << std::endl;
//    }

    errno = 0;
    if(ioctl(fileDescriptor, TCGETS2, &tty)){
        std::cerr << "Error" << errno << "from ioctl TCGETS2: " << strerror(errno) << std::endl;
    }


    //  Parity bit:
    if(parityBit == 0){
        tty.c_cflag &= ~PARENB; // Clear parity bit, disabling parity (most common)
    }else{
        tty.c_cflag |= PARENB;  // Set parity bit, enabling parity
    }

    //  Number of stop bits:
    if(stopBits == 0){
        tty.c_cflag &= ~CSTOPB; // Clear stop field, only one stop bit used in communication (most common)
    }else{
        tty.c_cflag |= CSTOPB;  // Set stop field, two stop bits used in communication
    }


    //  Number Of Bits Per Byte:
    switch (bitsPerByte) {
        case 5:
            tty.c_cflag |= CS5; // 5 bits per byte
            break;
        case 6:
            tty.c_cflag |= CS6; // 6 bits per byte
            break;
        case 7:
            tty.c_cflag |= CS7; // 7 bits per byte
            break;
        default:
            tty.c_cflag |= CS8; // 8 bits per byte (most common)
            break;
    }

    //  Flow Control:
    if(hardwareFlowControl == 0){
        tty.c_cflag &= ~CRTSCTS; // Disable RTS/CTS hardware flow control (most common)
    }else{
        tty.c_cflag |= CRTSCTS;  // Enable RTS/CTS hardware flow control
    }



    //  Modem-specific signal lines:
    tty.c_cflag |= CREAD | CLOCAL; // Turn on READ & ignore ctrl lines (CLOCAL = 1)

    //  Disabling Canonical Mode:
    tty.c_lflag &= ~ICANON;

    //  Echo
    tty.c_lflag &= ~ECHO; // Disable echo
    tty.c_lflag &= ~ECHOE; // Disable erasure
    tty.c_lflag &= ~ECHONL; // Disable new-line echo

    //  Disable Signal Chars
    tty.c_lflag &= ~ISIG; // Disable interpretation of INTR, QUIT and SUSP

    // Disable software flow control:
    tty.c_iflag &= ~(IXON | IXOFF | IXANY); // Turn off s/w flow ctrl

    //  Disable Special Handling Of Bytes On Receive
    tty.c_iflag &= ~(IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL); // Disable any special handling of received bytes

    //  Disable any special handling of output chars/bytes:
    tty.c_oflag &= ~OPOST; // Prevent special interpretation of output bytes (e.g. newline chars)
    tty.c_oflag &= ~ONLCR; // Prevent conversion of newline to carriage return/line feed
    // tty.c_oflag &= ~OXTABS; // Prevent conversion of tabs to spaces (NOT PRESENT IN LINUX)
    // tty.c_oflag &= ~ONOEOT; // Prevent removal of C-d chars (0x004) in output (NOT PRESENT IN LINUX)


//    An important point to note is that VTIME means slightly different things depending on what VMIN is. When VMIN is 0,
//    VTIME specifies a time-out from the startThread of the read() call. But when VMIN is > 0, VTIME specifies the time-out
//    from the startThread of the first received character.
//
//    VMIN = 0, VTIME = 0: No blocking, return immediately with what is available
//
//    VMIN > 0, VTIME = 0: This will make read() always wait for bytes (exactly how many is determined by VMIN), so
//    read() could block indefinitely.
//
//    VMIN = 0, VTIME > 0: This is a blocking read of any number chars with a maximum timeout (given by VTIME). read()
//    will block until either any amount of data is available, or the timeout occurs. This happens to be my favourite
//    mode (and the one I use the most).
//
//    VMIN > 0, VTIME > 0: Block until either VMIN characters have been received, or VTIME after first character has
//    elapsed. Note that the timeout for VTIME does not begin until the first character is received.
//
//    VMIN and VTIME are both defined as the type cc_t, which I have always seen be an alias for unsigned char (1 byte).
//    This puts an upper limit on the number of VMIN characters to be 255 and the maximum timeout of 25.5 seconds
//    (255 deciseconds).
//
//    “Returning as soon as any data is received” does not mean you will only get 1 byte at a time. Depending on the OS
//    latency, serial port speed, hardware buffers and many other things you have no direct control over, you may
//    receive any number of bytes.
//
//    For example, if we wanted to wait for up to 1s, returning as soon as any data was received, we could use:

    tty.c_cc[VTIME] = 10;    // Wait for up to 1s (10 deciseconds), returning as soon as any data is received.
    tty.c_cc[VMIN] = 0;


    //  Baud Rate
    tty.c_cflag &= ~CBAUD;
    tty.c_cflag |= BOTHER;
    tty.c_ispeed = baudRate;
    tty.c_ospeed = baudRate;

//    tty.c_ispeed = tty.c_ospeed = baudRate;

//    // Specifying a custom baud rate when using GNU C
//    cfsetispeed(&tty, baudRate);
//    cfsetospeed(&tty, baudRate);


    // Save tty settings, also checking for error
//    if (tcsetattr(fileDescriptor, TCSANOW, &tty) != 0) {
//        std::cout << "Error " << errno << " from tcsetattr: " << strerror(errno) << std::endl;
//    }

    if(ioctl(fileDescriptor, TCSETS2, &tty)){
        std::cerr << "Error" << errno << "from ioctl TCSETS2: " << strerror(errno) << std::endl;
    }


    if(startWorker) { startThread(); }
}


SerialConnection::~SerialConnection() {
    stopThread();
    workerThread.join();
}


//  TODO:: Remove deprecated read() method.
//std::string SerialConnection::read() {
//
//    // Allocate memory for read buffer, set size according to your needs
//    char read_buf [1024];
//    memset(&read_buf, '\0', sizeof(read_buf));
//
//    // Read bytes. The behaviour of read() (e.g. does it block? how long does it block for?) depends on the configuration
//    // settings above, specifically VMIN and VTIME
//
//    int n = ::read(fileDescriptor, &read_buf, sizeof(read_buf));
//    // n is the number of bytes read. n may be 0 if no bytes were received, and can also be negative to signal an error.
//
//    if(n < 0){
//        std::cout << "Error " << errno << " from read: " << strerror(errno) << std::endl;
//    }
//
//
//
//    std::string returnString(read_buf);
//
//    return returnString;
//}


std::string SerialConnection::readSerialLine() const {

    char newChar = '\0';
    std::string incomingString;

    while(newChar != '\n'){
        int n = ::read(fileDescriptor, (void *) &newChar, 1);

        if(n == 1){
            incomingString += newChar;
        }

        if(n < 0){
            std::cout << "Error " << errno << " from read: " << strerror(errno) << std::endl;
        }
    }
    return incomingString;
}



void SerialConnection::read() {
    std::string incomingString = readSerialLine();
    craftState.getSerialData().record(incomingString);
}


void SerialConnection::close() const {
    ::close(fileDescriptor);
}


void SerialConnection::write(const std::string& writeString) const {
    int count = ::write(fileDescriptor, writeString.c_str(), writeString.length());
    if (count < 0) {
        std::cout << "Error " << errno << " from write: " << strerror(errno) << std::endl;
    }
}

bool SerialConnection::startThread() {
    if(threadRunning) { return false; }

    workerThread = std::thread(&SerialConnection::workerFunction, this);
    threadRunning = true;

    return true;
}

bool SerialConnection::stopThread() {

    threadRunning = false;

    return true;
}

void SerialConnection::workerFunction() {
    while(threadRunning){ read(); }
}

CraftState &SerialConnection::getCraftState() const {
    return craftState;
}

void SerialConnection::setCraftState(CraftState &craftState) {
    SerialConnection::craftState = craftState;
}





