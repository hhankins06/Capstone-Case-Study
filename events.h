#ifndef EVENTS_H
#define EVENTS_H

#include <string>

class Events
{
private:
        int eventId;
        std::string title;
        std::string description;
        int expectedAttendance;
        std::string eventType;
        bool approved;

        void updateDetails();
        bool validateRequirements();

public:
        Events(int id, std::string title, std::string description, int expectedAttendance, std::string eventType);
        ~Events();
        void updateDetails();
        bool validateRequirements();
        void viewEvent();
};

#endif