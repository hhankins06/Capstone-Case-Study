// supportRequest.cpp, this file references supportRequest.h

#include <iostream>
#include <string>
#include "supportRequest.h"

using namespace std;

//Constructor
SupportRequest::SupportRequest(int id)
{
	supportID = id;
	status = "pending";
}

//Destructor
SupportRequest::~SupportRequest()
{
}

// Create new support request
void SupportRequest::requestSupport()
{
	cout << "To create a new support request, you will need to create a unique support ID number and describe the nature of your problem and the type of support it requires. Respond to each prompt as it appears.\n";
	
	int id;
	std::string desc;
	std::string type;

	cout << "Please input the support ID for your request as an integer:\n";
	cin >> id;
	supportId = id;

	cout << "Please describe your problem succinctly:\n";
	cin >> desc;
	description = desc;

	cout << "Please describe the type of support you are requesting for your problem: \n";
	cin >> type;
	supportType = type;

	status = "pending";

	cout << "Your support request has been created!\n";
}


// Update status of a request
void SupportRequest::updateStatus()
{
	cout << "Has this request been completed? (y/n)\n";
	char val;
	cin >> val;
	if (val == 'y' || val == 'Y')
	{
		cout << "Request has been completed!\n";
		status = "completed";
	}
	else
	{
		cout << "Has this request been rejected? (y/n)\n";
		char val;
		cin >> val;
		cin >> val;
		if (val == 'y' || val == 'Y')
		{
			cout << "Request has been rejected.\n";
			status = "rejected";
		}
	}
}

// Cancel a request
void SupportRequest::cancelRequest()
{
	cout << "Would you like to cancel your support request? (y/n)\n";
	char val;
	cin >> val;
	if (val == 'y' || val == 'Y')
	{
		cout << "Are you sure that you would like to cancel your request? (y/n)\n";
		char check;
		cin >> check;
		if (check == 'y' || check == 'Y')
		{
			cout << "Okay, your support request has been cancelled.\n";
			status = "cancelled";
			approved = false;
		}
		else
		{
			cout << "Okay, no update was made to your reservation.\n";
		}
	}
	else
	{
		cout << "Okay, no update was made to your support request.\n";
	}
}