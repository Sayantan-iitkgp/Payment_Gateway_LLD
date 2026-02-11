#ifndef Razorpay_BANKING_SYSTEM_H
#define Razorpay_BANKING_SYSTEM_H
#include "Banking_System.h"
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define st string
#define pb push_back

class RazorpayBankingSystem : public BankingSystem
{
public:
    RazorpayBankingSystem() : BankingSystem("Razorpay") {}

    bool processPayment(const string &sender_id, const string &receiver_id, double amount, const string &currency) override
    {
        // Simulate payment processing logic for Razorpay
        cout << "Processing payment through Razorpay:" << endl;
        cout << "Sender ID: " << sender_id << endl;
        cout << "Receiver ID: " << receiver_id << endl;
        cout << "Amount: " << amount << " " << currency << endl;

        // Simulate success or failure randomly
        // 5% chance of failure to mimic real-world scenarios
        bool payment_status = (rand() % 20 != 13); // Randomly succeed or fail

        if (payment_status)
        {
            cout << "Payment successful via Razorpay!" << endl;
        }
        else
        {
            cout << "Payment failed via Razorpay. Please try again." << endl;
        }
        return payment_status;
    }
};

#endif