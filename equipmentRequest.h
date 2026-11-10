#ifndef EQUIP_REQUEST_H
#define EQUIP_REQUEST_H

#include <string>

class EquipmentRequest
{
private:
    // Member Variables
    int requestId;
    std::string equipmentName;
    int quantity;
    std::string status;
    bool approved;

public:
    EquipmentRequest(int id, std::string name, int num);
    ~EquipmentRequest();
    void modifyRequest();
    void cancelRequest();
    void viewRequest();
    void approve();
    void reject();
};

#endif