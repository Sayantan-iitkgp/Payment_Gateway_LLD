#ifndef PAYTM_GATEWAY_H
#define PAYTM_GATEWAY_H
#include "Payment_Gateway.h"
#include "../Banking_Strategies/Paytm_Banking_System.h"
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define st string
#define pb push_back

class PaytmGateway : public PaymentGateway
{
public:

    PaytmGateway(BankingSystem *banking_system) : PaymentGateway(banking_system) {
        retry_time = 3; // Paytm has retry time of 3
    } 

    // Validation logic for Paytm Gateway
    bool validatePaymentDetails(const string &sender_id, const string &receiver_id, double amount, const string &currency) override
    {
        // Implement Paytm-specific validation logic here
        cout << "Validating payment details for Paytm Gateway..." << endl;

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
        if (currency != "INR")
        {
            cout << "Invalid currency. Paytm only supports INR." << endl;
            return false;
        }
        // Additional validation logic can be added here
        return true;
    }

    // Initiate payment logic for Paytm Gateway
    void initiatePayment(const string &sender_id, const string &receiver_id, double amount, const string &currency) override
    {
        cout << "Initiating payment through Paytm Gateway..." << endl;
        // Here we would interact with the Paytm Banking System to process the payment
        // For simplicity, we will just simulate this interaction
    }

    // Confirm payment status logic for Paytm Gateway
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

#endif // PAYTM_GATEWAY_H