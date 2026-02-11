#ifndef PAYMENT_CONTROLLER_H
#define PAYMENT_CONTROLLER_H
#include <bits/stdc++.h>
using namespace std;
#include "Payment_Request.h"
#include "Payment_Service.h"

// This is the main controller class that handles the payment requests and interacts with the payment service to process the payments. It is responsible for receiving the payment requests, validating them, and then passing them to the payment service for processing. It also handles the responses from the payment service and returns the appropriate response to the client.
//This is also a singleton class.

class PaymentController{
  private:
    static PaymentController* instance;
    static mutex mu;

    // Private constructor to prevent instantiation
    PaymentController() {}

    public:
    // Static method to get the single instance of the PaymentController class
    static PaymentController* getInstance() 
    {
        // Double-checked locking to ensure thread safety
        if (instance == nullptr)
        {
            unique_lock<mutex> lock(mu);
            if (instance == nullptr)
            {
                instance = new PaymentController();
            }
        }
        return instance;
    }

    // Method to handle payment requests
    bool handlePaymentRequest(const PaymentRequest &request){
        // Validate the payment request
        if (request.getAmount() <= 0)
        {
            cout << "Invalid amount. Amount must be greater than zero." << endl;
            return false;
        }
        if (request.getCurrency() != "USD" && request.getCurrency() != "INR")
        {
            cout << "Invalid currency. Only USD and INR are supported." << endl;
            return false;
        }
        // Additional validation logic can be added here

        // Process the payment using the payment service
        PaymentService *payment_service = PaymentService::getInstance();
        return payment_service->processPayment(request.getPaymentMethod(), request.getSenderId(), request.getReceiverId(), request.getAmount(), request.getCurrency());
    }
};

// Initialize static members
PaymentController* PaymentController::instance = nullptr;
mutex PaymentController::mu;

#endif // PAYMENT_CONTROLLER_H