#ifndef RAZORPAY_GATEWAY_H
#define RAZORPAY_GATEWAY_H
#include "Payment_Gateway.h"
#include "../Banking_Strategies/Razorpay_Banking_System.h"
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define st string
#define pb push_back

class RazorpayGateway : public PaymentGateway
{
public:
    RazorpayGateway(BankingSystem *banking_system) : PaymentGateway(banking_system)
    {
        retry_time = 5; // Razorpay has retry time of 5
    }

    // Validation logic for Razorpay Gateway
    bool validatePaymentDetails(const string &sender_id, const string &receiver_id, double amount, const string &currency) override
    {
        // Implement Razorpay-specific validation logic here
        cout << "Validating payment details for Razorpay Gateway..." << endl;

        // For real-world case we should verify these things from the database.
        if (sender_id.empty() || receiver_id.empty())
        {
            cout << "Sender and Receiver IDs cannot be empty." << endl;
            return false;
        }

        if (amount <= 0)
        {
            cout << "Invalid amount. Amount must be greater than zero." << endl;
            return false;
        }
        if (currency != "USD" && currency != "INR")
        {
            cout << "Invalid currency. Razorpay only supports INR and USD." << endl;
            return false;
        }
        // Additional validation logic can be added here
        return true;
    }

    // Initiate payment logic for Razorpay Gateway
    void initiatePayment(const string &sender_id, const string &receiver_id, double amount, const string &currency) override
    {
        cout << "Initiating payment through Razorpay Gateway..." << endl;
        // Here we would interact with the Razorpay Banking System to process the payment
        // For simplicity, we will just simulate this interaction
    }

    // Confirm payment status logic for Razorpay Gateway
    bool confirmPaymentStatus(const string &sender_id, const string &receiver_id, double amount, const string &currency) override
    {
        return getBankingSystem()->processPayment(sender_id, receiver_id, amount, currency);
    }

    //process payment with retry logic
    bool process_with_retry(const string &sender_id, const string &receiver_id, double amount, const string &currency) override
    {
        //here do nothing it is done in the proxy gateway as it is responsible for handling retries and not for processing the payment. The processing should be done by the real gateway.
        return true;
    }
};

#endif // RAZORPAY_GATEWAY_H