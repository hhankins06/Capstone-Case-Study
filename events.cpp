#include "events.h"
#include <iostream>
using namespace std;

Events::Events(int id, std::string title, std::string description, int expectedAttendance, std::string eventType)
{
    eventId = id;
    title = title;
    description = description;
    expectedAttendance = expectedAttendance;
    eventType = eventType;
    approved = false;
}

Events::~Events()
{
}

void Events::updateDetails()
{
    cout << "Updated event details for event ID: " << eventId << endl;

    cout << "New Title: " << title << endl;
    cout << "New Description: " << description << endl;
    cout << "New Expected Attendance: " << expectedAttendance << endl;
    cout << "New Event Type: " << eventType << endl;
}

bool Events::validateRequirements()
{
    return true;
}