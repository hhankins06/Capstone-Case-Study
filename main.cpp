
#include "equipmentRequest.h"
#include "events.h"
#include "user.h"
#include "facility.h"
#include "reservation.h"
#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

void printMenu()
{
    cout << "=======================\n";
    cout << "       MENU\n";
    cout << "=======================\n\n";
    cout << "1. View Events\n";
    cout << "2. View Facilities\n";
    cout << "3. View Reservations\n";
    cout << "4. View Equipment Requests\n";
    cout << "5. View Support Requests\n";
    cout << "6. Quit\n";
}
void viewEvents(vector<Events> &events)
{
    for (int i = 0; i < events.size(); ++i)
    {
        events[i].viewEvent();
    }
    cout << "Please select one of the following options:\n";
    cout << "1. Return to Menu\n";
    cout << "2. Update event details\n";
    cout << "3. Validate event requirements\n";
    int choice, id;
    cin >> choice;
    switch (choice)
    {
    case (1):
        return;
    case (2):
        cout << "Enter event ID number: ";
        cin >> id;
        events[id - 1].updateDetails();
        break;
    case (3):
        cout << "Enter event ID number: ";
        cin >> id;
        if (events[id - 1].validateRequirements())
        {
            cout << "Event requirements are valid." << endl;
        }
        else
        {
            cout << "Event requirements are not valid." << endl;
        }
        break;
    }
}
void printFacilityInfo(Facility &facility)
{
    std::cout << "Facility ID : " << facility.facilityID << "\n";
    std::cout << "Name        : " << facility.facilityName << "\n";
    std::cout << "Location    : " << facility.getLocation() << "\n";
    std::cout << "Capacity    : " << facility.getCapacity() << " people\n";
    std::cout << "Description : " << facility.getDescription() << "\n";
    std::cout << "Approved    : " << (facility.approved ? "Yes" : "No") << "\n";
}

std::string formatTime(std::time_t t)
{
    char buffer[26];
    std::tm *tm_info = std::localtime(&t);
    std::strftime(buffer, 26, "%Y-%m-%d %H:%M", tm_info);
    return std::string(buffer);
}
void viewFacilities(Facility &lab)
{
    int choice = 0;

    while (choice != 5)
    {
        std::cout << "S&T Facility Management\n";
        std::cout << "1. View Facility Details\n";
        std::cout << "2. Update Facility Details\n";
        std::cout << "3. View Current Schedule\n";
        std::cout << "4. Check Availability\n";
        std::cout << "5. Exit\n";
        std::cout << "Please select an option: ";

        if (!(std::cin >> choice))
        {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Sorry, this input is invalid. Please enter a number 1-5.\n";
            continue;
        }

        switch (choice)
        {
        case 1:
            printFacilityInfo(lab);
            break;

        case 2:
            lab.updateDetails();
            break;

        case 3:
        {
            std::cout << "\nSchedule for " << lab.facilityName << "\n";
            std::vector<Reservation> schedule = lab.viewSchedule();
            if (schedule.empty())
            {
                std::cout << "No reservations found.\n";
            }
            else
            {
                for (auto &res : schedule)
                {
                    std::cout << "Booking #" << res.reservationId << " has been reserved from " << formatTime(res.startTime) << " to " << formatTime(res.endTime) << "\n";
                }
            }
            break;
        }

        case 4:
        {
            int startOffsetHours, durationHours;
            std::cout << "Enter the start time in terms of hours from now: ";
            std::cin >> startOffsetHours;
            std::cout << "Enter duration in hours: ";
            std::cin >> durationHours;

            // 3600 seconds per hour -- which is how this one worksss
            std::time_t now = std::time(nullptr);
            std::time_t reqStart = now + (startOffsetHours * 3600);
            std::time_t reqEnd = reqStart + (durationHours * 3600);

            std::cout << "Checking window: " << formatTime(reqStart) << " -> " << formatTime(reqEnd) << "...\n";

            if (lab.checkAvailability(reqStart, reqEnd))
            {
                std::cout << "This facility is available!\n";
            }
            else
            {
                std::cout << "Unfortunately, this facility is unavailable.\n";
            }
            break;
        }

        case 5:
            std::cout << "Exiting!\n";
            break;

        default:
            std::cout << "Invalid option. Try again.\n";
        }
    }
}
void viewReservations(vector<Reservation> &reservations)
{
    for (int i = 0; i < reservations.size(); ++i)
    {
        reservations[i].viewReservation();
    }

    cout << "Please select one of the following options:\n";
    cout << "1. Return to Menu\n";
    cout << "2. Modify reservation\n";
    cout << "3. Cancel reservation\n";
    cout << "4. Update reservation status\n";

    int choice, id;
    cin >> choice;

    switch (choice)
    {
    case 1:
        return;
    case 2:
        cout << "Enter reservation ID number: ";
        cin >> id;
        reservations[id - 1].modify();
        break;
    case 3:
        cout << "Enter reservation ID number: ";
        cin >> id;
        reservations[id - 1].cancel();
        break;
    case 4:
        cout << "Enter reservation ID number: ";
        cin >> id;
        reservations[id - 1].updateStatus();
        break;
    }
}
void viewEquipment(vector<EquipmentRequest> &requests)
{
    for (int i = 0; i < requests.size(); ++i)
    {
        requests[i].viewRequest();
    }
    cout << "Please select one of the following options:\n";
    cout << "1. Return to Menu\n";
    cout << "2. Modify request\n";
    cout << "3. Cancel request\n";
    cout << "4. Approve request\n";
    cout << "5. Reject request\n";
    int choice, id;
    cin >> choice;
    switch (choice)
    {
    case (1):
        return;
    case (2):
        cout << "Enter request ID number: ";
        cin >> id;
        requests[id - 1].modifyRequest();
        break;
    case (3):
        cout << "Enter request ID number: ";
        cin >> id;
        requests[id - 1].cancelRequest();
        break;
    case (4):
        cout << "Enter request ID number: ";
        cin >> id;
        requests[id - 1].approve();
        break;
    case (5):
        cout << "Enter request ID number: ";
        cin >> id;
        requests[id - 1].reject();
        break;
    }
}
void viewSupport()
{
    // FIXME: Sophia
}

int main()
{
    int choice = 0;

    // Variable Declaration
    // Basic testing input to verify system function
    User user1(1, "John Doe", "johndoe@mst.edu", "123", "student");

    vector<Events> events;
    events.push_back(Events(1, "Craft Night", "Painting and embroidery", 50, "RSO"));
    events.push_back(Events(2, "AI Lecture", "Previous student speaks on AI in workforce", 150, "Faculty"));
    events.push_back(Events(3, "Concert", "Local band plays original songs", 200, "SUB"));

    vector<EquipmentRequest> requests;
    requests.push_back(EquipmentRequest(1, "Ladder", 1));
    requests.push_back(EquipmentRequest(2, "Lights", 5));

    Facility lab(505, "AM Lab", "Electrical Engineering Building, 5th Floor", 35, "This facility combines music and electricity, with guitars to utilize.", true);

    time_t now = time(nullptr);
    vector<Reservation> reservations;
    reservations.push_back(Reservation(1, 101, now, now + 3600, now));
    reservations.push_back(Reservation(2, 102, now + 86400, now + 93600, now));

    cout << "Welcome to the Smart Campus Event & Facility Booking System!\n";
    string email, pass;
    bool loggedIn = false;
    for (int i = 0; i < 3; ++i)
    {
        cout << "Please enter your email: ";
        getline(cin, email);
        cout << "\nPlease enter your password: ";
        getline(cin, pass);
        if (user1.login(email, pass))
        {
            loggedIn = true;
            break;
        }
        cout << "\nIncorrect username or password.\n";
    }
    if (!loggedIn)
    {
        cout << "You have exceeded 3 password attempts.\n";
        exit(0);
    }

    while (choice != 6)
    {
        printMenu();
        cin >> choice;
        switch (choice)
        {
        case 1:
            viewEvents(events);
            break;
        case 2:
            viewFacilities(lab);
            break;
        case 3:
            viewReservations(reservations);
            break;
        case 4:
            viewEquipment(requests);
            break;
        case 5:
            viewSupport();
            break;
        case 6:
            exit(0);
            break;
        default:
            break;
        }
    }
}