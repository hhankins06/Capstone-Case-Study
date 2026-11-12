#include "events.h"
#include <iostream>
using namespace std;

Events::Events(int id, std::string title, std::string description, int expectedAttendance, std::string eventType) : eventId(id), title(title), description(description), expectedAttendance(expectedAttendance), eventType(eventType), approved(false)
{

}

Events::~Events()
{
}

void Events::updateDetails(std::string newTitle, std::string newDescription, int newExpectedAttendance, std::string newEventType)
{
    cout << "Updating event details for event ID: " << eventId << endl;

    if (newTitle.empty())
    {
        cout << "Update failed: Title cannot be empty." << endl;
        return;
    } 

    if (newDescription.empty())
    {
        cout << "Update failed: Description cannot be empty." << endl;
        return;
    }

    if (newExpectedAttendance <= 0)
    {
        cout << "Update failed: Expected attendance must be greater than zero." << endl;
        return;
    }

    if (newEventType.empty())
    {
        cout << "Update failed: Event type cannot be empty." << endl;
        return;
    }

    title = newTitle;
    description = newDescription;
    expectedAttendance = newExpectedAttendance;
    eventType = newEventType;

    cout << "Event details updated successfully." << endl;
    cout << "New Title: " << title << endl;
    cout << "New Description: " << description << endl;
    cout << "New Expected Attendance: " << expectedAttendance << endl;
    cout << "New Event Type: " << eventType << endl;
}

bool Events::validateRequirements()
{
    return true;
}

void Events::viewEvent()
{
    cout << "\nEvent (" << eventId << ")\n";
    cout << "Title: " << title << endl;
    cout << "Description: " << description << endl;
    cout << "Expected Attendance: " << expectedAttendance << endl;
    cout << "Event Type: " << eventType << endl;
}