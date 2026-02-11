#ifndef PAYTM_BANKING_SYSTEM_H
#define PAYTM_BANKING_SYSTEM_H
#include "Banking_System.h"
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define st string
#define pb push_back

class PaytmBankingSystem : public BankingSystem
{
public:
    PaytmBankingSystem() : BankingSystem("Paytm") {}

    bool processPayment(const string &sender_id, const string &receiver_id, double amount, const string &currency) override
    {
        // Simulate payment processing logic for Paytm
        cout << "Processing payment through Paytm:" << endl;
        cout << "Sender ID: " << sender_id << endl;
        cout << "Receiver ID: " << receiver_id << endl;
        cout << "Amount: " << amount << " " << currency << endl;

        // Simulate success or failure randomly
        // 2% chance of failure to mimic real-world scenarios
        bool payment_status = (rand() % 50 != 17); // Randomly succeed or fail

        if (payment_status)
        {
            cout << "Payment successful via Paytm!" << endl;
        }
        else
        {
            cout << "Payment failed via Paytm. Please try again." << endl;
        }
        return payment_status;
    }
};

#endif // PAYTM_BANKING_SYSTEM_H