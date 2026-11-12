#include <iostream>
#include <iomanip>
#include <ctime>
#include "Facility.h"
#include "Reservation.h"

void printFacilityInfo(Facility& facility) 
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
    std::tm* tm_info = std::localtime(&t);
    std::strftime(buffer, 26, "%Y-%m-%d %H:%M", tm_info);
    return std::string(buffer);
}

int main() 
{
    // Sample facility
    Facility lab(505, "AM Lab", "Electrical Engineering Building, 5th Floor", 35, "This facility combines music and electricity, with guitars to utilize.", true);

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
                    for (auto& res : schedule) 
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

    return 0;
}
