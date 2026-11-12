
#include "equipmentRequest.h"
#include "events.h"
#include <iostream>
#include <vector>
using namespace std;

void printLogin()
{
    cout << "Welcome to the Smart Campus Event & Facility Booking System!\n";
    string user, pass;
    for (int i = 0; i < 3; ++i)
    {
        cout << "Please enter your username: ";
        getline(cin, user);
        cout << "\nPlease enter your password: ";
        getline(cin, pass);
        // if (userExists && passCorrect)
        //{
        cout << "\nSuccessfully logged in.\n";
        break;
        //}
    }
}
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
void viewFacilities()
{
    // FIXME
}
void viewReservations()
{
    // FIXME
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
    // FIXME
}

int main()
{
    int choice = 0;

    // Variable Declaration
    // Basic testing input to verify system function
    vector<Events> events;
    events.push_back(Events(1, "Craft Night", "Painting and embroidery", 50, "RSO"));
    events.push_back(Events(2, "AI Lecture", "Previous student speaks on AI in workforce", 150, "Faculty"));
    events.push_back(Events(3, "Concert", "Local band plays original songs", 200, "SUB"));

    vector<EquipmentRequest> requests;
    requests.push_back(EquipmentRequest(1, "Ladder", 1));
    requests.push_back(EquipmentRequest(2, "Lights", 5));

    printLogin();
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
            viewFacilities();
            break;
        case 3:
            viewReservations();
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