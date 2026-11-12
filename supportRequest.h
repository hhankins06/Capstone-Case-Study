// This is the header file for supportRequest.cpp

#ifndef SUPPORTREQUEST_H

#define SUPPORTREQUEST_H

#include <string>

//Class declaration
class SupportRequest
{
public:
    int supportId;
    std::string supportType;
    std::string description;
    std::string status;

    //Constructor and Destructor
    SupportRequest(int id);
    ~SupportRequest();

    //Functions
    void requestSupport();
    void cancelRequest();
    void updateStatus();
};


#endif