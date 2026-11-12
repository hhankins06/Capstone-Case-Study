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