// This is the header file for reservation.cpp

#ifndef RESERVATION_H

#define RESERVATION_H

#include <string>
#include <ctime>

//Class declaration
class Reservation
{
private:
    std::time_t createdAt;
    int reservationId;
    int facilityId;
    bool approved;

public:
    std::string status;
    std::time_t startTime;
    std::time_t endTime;

    //Constructor and Destructor
    Reservation(std::time_t createdAt, int reservationId, int facilityId, std::string status, std::time_t startTime, std::time_t endTime);
    ~Reservation();

    //Functions
    void submit();
    void modify();
    void cancel();
    void updateStatus();
};


#endif