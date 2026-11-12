#include "equipmentRequest.h"
#include <iostream>
using namespace std;

EquipmentRequest::EquipmentRequest(int id, string name, int num)
{
    requestId = id;
    equipmentName = name;
    quantity = num;
    status = "pending";
    approved = false;
}

EquipmentRequest::~EquipmentRequest()
{
}

void EquipmentRequest::modifyRequest()
{
    cout << "\nWhat would you like to modify?\n";
    cout << "1. Equipment Name\n";
    cout << "2. Quantity\n";
    cout << "3. Exit\n";
    int choice, num;
    string name;
    cin >> choice;
    switch (choice)
    {
    case 1:
        cout << "Enter new name: \n";
        getline(cin, name);
        equipmentName = name;
        cout << "Successfully updated to " << name << endl;
        break;
    case 2:
        cout << "Enter new quantity: \n";
        cin >> num;
        quantity = num;
        cout << "Successfully updated to " << num << endl;
        break;
    default:
        break;
    }
}
void EquipmentRequest::cancelRequest()
{
    status = "cancelled";
    approved = false;
}
void EquipmentRequest::viewRequest()
{
    cout << "\nEquipment Request (" << requestId << ")\n";
    cout << "Equipment Name: " << equipmentName << endl;
    cout << "Quantity: " << quantity << endl;
    cout << "Status: " << status << endl;
}
void EquipmentRequest::approve()
{
    status = "approved";
    approved = true;
}
void EquipmentRequest::reject()
{
    status = "rejected";
    approved = false;
}