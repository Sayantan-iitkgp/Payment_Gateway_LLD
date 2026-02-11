#ifndef PAYMENT_GATEWAY_H
#define PAYMENT_GATEWAY_H
#include <bits/stdc++.h>
#include "../Banking_Strategies/Banking_System.h"
using namespace std;
#define ll long long int
#define st string
#define pb push_back

// Payment Gateway class that interacts with different banking systems
class PaymentGateway
{
private:
    BankingSystem *bankingSystem;

protected:
    ll retry_time = 0; // Retry time for the gateway to be used by the Proxy Gateway for handling retries

public:
    PaymentGateway(BankingSystem *banking_system) : bankingSystem(banking_system) {}

    // getter for retry time to be used by the Proxy Gateway for handling retries
    ll getRetryTime() const { return retry_time; }

    // Here we will use a Template design pattern to maintain the pipeline of the payment process.

    bool processPayment(const string &sender_id, const string &receiver_id, double amount, const string &currency)
    {
        // Validate payment details according to the gateway logic
        if (!validatePaymentDetails(sender_id, receiver_id, amount, currency))
        {
            cout << "Payment validation failed. Please check the details and try again." << endl;
            return false;
        }

        // Initiate payment
        initiatePayment(sender_id, receiver_id, amount, currency);

        // Confirm payment status
        if (!confirmPaymentStatus(sender_id, receiver_id, amount, currency))
        {
            cout << "Payment confirmation failed. Please try again later." << endl;
            return false;
        }
        return true;
    }

    // Process payment with retry logic
    virtual bool process_with_retry(const string &sender_id, const string &receiver_id, double amount, const string &currency) = 0;

    // Getter for the banking system to be used by the gateway strategies
    BankingSystem *getBankingSystem() const { return bankingSystem; }

protected:
    // Validate payment according to the gateway logic
    virtual bool validatePaymentDetails(const string &sender_id, const string &receiver_id, double amount, const string &currency) = 0;

    // Initiate payment according to the gateway logic
    virtual void initiatePayment(const string &sender_id, const string &receiver_id, double amount, const string &currency) = 0;

    // Confirm that the payment is successsful or not according to the gateway logic
    virtual bool confirmPaymentStatus(const string &sender_id, const string &receiver_id, double amount, const string &currency) = 0;
};

#endif // PAYMENT_GATEWAY_H