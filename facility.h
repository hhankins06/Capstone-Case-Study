#ifndef FACILITY_H
#define FACILITY_H

#include <string>
#include <vector>
#include <ctime>

// Bring reservation class in
class Reservation;

class Facility
{
private:
    std::string location;
    int capacity;
    std::string description;

public:
    int facilityID;
    std::string facilityName;
    bool approved;

    // Constructor
    Facility(int facilityID, const std::string& name, const std::string& location, int capacity, const std::string& description, bool approved);

    // Methods
    bool checkAvailability(std::time_t start, std::time_t end) const;
    void updateDetails();
    std::vector<Reservation> viewSchedule() const;

    // Getters/setters for the private attributes -- location, capacity, and description
    std::string getLocation() const;
    void setLocation(const std::string& newLocation);

    int getCapacity() const;
    void setCapacity(int newCapacity);

    std::string getDescription() const;
    void setDescription(const std::string& newDescription);
};

#endif // FACILITY_H