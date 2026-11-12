
#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include "reservation.h"
using namespace std;

class User {
private:
    string email;
    string passwordHash;
    bool loggedIn;
    vector<Reservation> reservations;

public:
    int userId;
    string name;
    string role;

    User(int id, string n, string e, string password, string r);
    bool login(string e, string password);
    void logout();
    void updateProfile(string newName, string newEmail);
    vector<Reservation> viewReservations();
    void addReservation(Reservation reservation);
};

#endif
