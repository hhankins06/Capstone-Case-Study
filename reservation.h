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
    Reservation(int id, int facId, std::time_t start, std::time_t end);
    ~Reservation();

    //Functions
    void submit();
    void modify();
    void cancel();
    void updateStatus();
};


#endif