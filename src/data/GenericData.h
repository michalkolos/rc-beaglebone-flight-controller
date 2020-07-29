//
// Created by kolos on 7/22/20.
//

#ifndef RC_BEAGLEBONE_FLIGHT_CONTROLLER_GENERICDATA_H
#define RC_BEAGLEBONE_FLIGHT_CONTROLLER_GENERICDATA_H

#include <string>
#include <mutex>

class GenericData {
private:
    std::string tag = "";

protected:
    std::mutex accessMutex;

public:
    GenericData() = default;
    GenericData(GenericData& orgData);
    explicit GenericData(std::string tag);

    const std::string &getTag() const;

    void setTag(const std::string &tag);
    std::string toString() const;

};

#endif //RC_BEAGLEBONE_FLIGHT_CONTROLLER_GENERICDATA_H
