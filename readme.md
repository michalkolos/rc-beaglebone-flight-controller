# Flight controller for a fixed wing UAV based on the Beaglebone Blue SBC

## Current status:
* Implemented reading Sbus frames from RC radio receiver connected to one of the UART 
interfaces.
* Reading GPS position data by parsing NMEA messages sent through UART by a GPS module.


## Software dependencies:
[Robot Control library](http://www.strawsondesign.com/docs/librobotcontrol/group___servo.html#gabcde569afc59522a776c00a3cf38de7f) 
must be installed on the Beaglebone board.

## Build info:
In order for the servo controlls to work, controller nedds to have root privileges.

## Used hardware:
* [Beaglebone blue](https://beagleboard.org/p/products/beaglebone-blue)
* [Beitian BS-880](http://www.sz-beitian.com/ProductsDetail?product_id=921) GPS module
* [FrSky X4R](https://www.frsky-rc.com/product/x4r/) RC radio receiver

<br/>
<br/>

## Connecting to RC radio:
Radio receiver module can be connected through a serial communication interface 
called SBUS that provides multiple channels of analogue communication from the ground.
It is similar to the standard UART, but with some key differences:
* logic levels inverted,
* non standard baud rate of 100 000,
* 1 start bit,
* 1 Even parity bit,
* 2 Stop bits,
* 8 Data bits.

#### SBUS protocol:
A single SBUS message is 25 bytes long and consists of the following bytes:
* Byte[0]: SBUS Header, 0x0F (00001111b)
* Byte[1-22]: 16 servo channels, 11 bits per servo channel (total 22 bytes)
* Byte[23]:
  * Bit 7: digital channel 17 (0x80)
  * Bit 6: digital channel 18 (0x40)
  * Bit 5: frame lost (0x20)
  * Bit 4: failsafe activated (0x10)
  * Bit 0 - 3: n/a
* Byte[24]: SBUS End Byte, 0x00 (00000000b)

Each byte is composed of 8 bits with IDs as follows [7 6 5 4 3 2 1 0] where bit 0 is the least significant bit. The data of the 16 channels are distributed onto the 22 data bytes starting with the least significant bit of channel 1 as follows (using the notation CHANNEL.BIT_ID):

* data byte 0: [1.7 1.6 1.5 1.4 1.3 1.2 1.1 1.0]

* data byte 1: [2.4 2.3 2.2 2.1 2.0 1.10 1.9 1.8]

* data byte 2: [3.1 3.0 2.10 2.9 2.8 2.7 2.6 2.5]

* data byte 3: ...

The digital channels and flag bytes is composed as:

- flag byte: [0 0 0 0 failsafe frame_lost ch18 ch17]

[More information](https://github.com/bolderflight/SBUS/)
<br/>
<br/>

### Connecting GPS module:
GPS unit communicates through UART interface, sending serialized messages using
NMEA protocol.

[More information](http://aprs.gids.nl/nmea/)
 
