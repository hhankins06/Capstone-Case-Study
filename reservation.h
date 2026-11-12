#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>
#include <ctime>

class Reservation 
{
public:
    int reservationId;
    int facilityId;
    std::time_t startTime;
    std::time_t endTime;

    Reservation(int id, int facId, std::time_t start, std::time_t end): 
        reservationId(id), 
        facilityId(facId), 
        startTime(start), 
        endTime(end) {}
};

#endif // RESERVATION_H
