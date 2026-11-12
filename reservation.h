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
    bool approved;

public:
    int reservationId;
    int facilityId;
    std::string status;
    std::time_t startTime;
    std::time_t endTime;

    //Constructor and Destructor
    Reservation(int id, int facId, std::time_t start, std::time_t end, std::time_t created);
    ~Reservation();

    //Functions
    void submit();
    void modify();
    void cancel();
    void updateStatus();
};


#endif