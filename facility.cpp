#include "facility.h"
#include "reservation.h"
#include <iostream>

// Constructor implementation
Facility::Facility(int facilityID, const std::string &name, const std::string &location, int capacity, const std::string &description, bool approved) : facilityID(facilityID),
                                                                                                                                                        facilityName(name),
                                                                                                                                                        location(location),
                                                                                                                                                        capacity(capacity),
                                                                                                                                                        description(description),
                                                                                                                                                        approved(approved) {}

// Check the availability
bool Facility::checkAvailability(std::time_t start, std::time_t end) const
{
    if (!approved || start >= end)
    {
        return false;
    }

    // Create a viewable schedule
    std::vector<Reservation> schedule = viewSchedule();
    for (auto &res : schedule)
    {
        // Overlap if requested start was before existing end & requested end was after existing start
        if (start < res.endTime && end > res.startTime)
        {
            return false;
        }
    }

    return true;
}

// Update the details
void Facility::updateDetails()
{
    std::cout << "Updating details for facility " << facilityName << ":\n";

    std::cin.ignore(10000, '\n');

    std::cout << "Enter the new name for this facility: ";
    std::getline(std::cin, facilityName);

    std::cout << "\nEnter the new location (currently at " << location << "): ";
    std::getline(std::cin, location);

    std::cout << "\nEnter the new capacity (currently at " << capacity << "): ";
    int newCap;
    std::cin >> newCap;
    setCapacity(newCap);

    std::cin.ignore(10000, '\n');

    std::cout << "\nEnter new description (currently described as \"" << description << "\"): ";
    std::getline(std::cin, description);

    std::cout << "\nIs this facility approved? (1 for Yes, 0 for No): ";
    int appInput;
    if (std::cin >> appInput)
    {
        approved = (appInput == 1);
    }

    std::cout << "Facility details for " << facilityName << " have been successfully updated.\n";
}

// Retrieve list of reservations
std::vector<Reservation> Facility::viewSchedule() const
{
    std::vector<Reservation> schedule;
    // Still gotta fetch and populate reservations associated with this particular id
    // Example for now
    std::time_t now = std::time(nullptr);
    // Brand new object via emplace_back
    schedule.emplace_back(607, facilityID, now + 3600, now + 10800, now);
    return schedule;
}

// Get/Set

std::string Facility::getLocation() const
{
    return location;
}

void Facility::setLocation(const std::string &newLocation)
{
    location = newLocation;
}

int Facility::getCapacity() const
{
    return capacity;
}

void Facility::setCapacity(int newCapacity)
{
    if (newCapacity >= 0)
    {
        capacity = newCapacity;
    }
}

std::string Facility::getDescription() const
{
    return description;
}

void Facility::setDescription(const std::string &newDescription)
{
    description = newDescription;
}
