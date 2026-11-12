
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
        cout << "Please enter your password: ";
        getline(cin, pass);
        // if (userExists && passCorrect)
        //{
        cout << "Successfully logged in.\n";
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
}
void viewSupport()
{
    // FIXME
}

int main()
{
    int choice;

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