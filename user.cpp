
#include "user.h"
#include <iostream>
using namespace std;

User::User(int id, string n, string e, string password, string r) {
    userId = id;
    name = n;
    email = e;
    passwordHash = password;
    role = r;
    loggedIn = false;
}

bool User::login(string e, string password) {
    if (e == email && password == passwordHash) {
        loggedIn = true;
        cout << "Successfully logged in.\n";
        return true;
    }
    cout << "Incorrect email or password.\n";
    return false;
}

void User::logout() {
    loggedIn = false;
    cout << "Logged out.\n";
}

void User::updateProfile(string newName, string newEmail) {
    name = newName;
    email = newEmail;
    cout << "Profile updated.\n";
}

vector<Reservation> User::viewReservations() {
    for (int i = 0; i < (int)reservations.size(); i++) {
        cout << "Reservation ID: " << reservations[i].reservationId << endl;
        cout << "Facility ID: " << reservations[i].facilityId << endl;
    }
    if (reservations.empty()) {
        cout << "No reservations found.\n";
    }
    return reservations;
}

void User::addReservation(Reservation reservation) {
    reservations.push_back(reservation);
}
