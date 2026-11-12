#include "events.h"
#include <iostream>
using namespace std;

Events::Events(int id, std::string title, std::string description, int expectedAttendance, std::string eventType) : eventId(id), title(title), description(description), expectedAttendance(expectedAttendance), eventType(eventType), approved(false)
{

}

Events::~Events()
{
}

void Events::updateDetails()
{
    std::string newTitle;
    std::string newDescription;
    int newExpectedAttendance;
    std::string newEventType;

    std::cin.ignore(10000, '\n'); // Ignore the rest of the line

    cout << "Updating event details for event ID: " << eventId << endl;

    cout << "Enter your new details below:" << endl;

    cout << "Enter the new title for this event: ";
    std::getline(std::cin, newTitle);

    cout << "Enter the new description for this event: ";
    std::getline(std::cin, newDescription);

    cout << "Enter the new expected attendance for this event: ";
    std::cin >> newExpectedAttendance;

    // VSCODE filled in the following lines to handle input errors :L

    std::cin.clear(); // Clear the error flag
    std::cin.ignore(10000, '\n'); // Ignore the rest of the line

    cout << "Enter the new event type for this event: ";
    std::getline(std::cin, newEventType);

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
    if (title.empty() || description.empty() || expectedAttendance <= 0 || eventType.empty())
    {
        cout << "Event validation failed: One or more required fields are missing or invalid." << endl;
        return false;
    }
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