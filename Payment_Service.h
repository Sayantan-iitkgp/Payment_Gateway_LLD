#ifndef PaYMENT_SERVICE_H
#define PaYMENT_SERVICE_H
#include<bits/stdc++.h>
using namespace std;
#include "./Gateway_Strategies/Payment_Gateway.h"
#include "Gateway_Factory.h"
#define ll long long int
#define st string
#define pb push_back

//This is also a singleton class
class PaymentService
{
    private:
        static PaymentService* instance;
        static mutex mu;

        // Private constructor to prevent instantiation
        PaymentService() {}

    public:
        // Static method to get the single instance of the PaymentService class 
        static PaymentService* getInstance()
        {
            // Double-checked locking to ensure thread safety
            if (instance == nullptr)
            {
                unique_lock<mutex> lock(mu);
                if (instance == nullptr)
                {
                    instance = new PaymentService();
                }
            }
            return instance;
        }

        // Method to process payment using the specified gateway
        bool processPayment(const string &gateway_name, const string &sender_id, const string &receiver_id, double amount, const string &currency)
        {
            try
            {
                // Get the gateway instance from the factory
                PaymentGateway *gateway = GatewayFactory::getInstance()->createGateway(gateway_name);
                // Process the payment using the gateway
                return gateway->process_with_retry(sender_id, receiver_id, amount, currency);
            }
            catch (const invalid_argument &e)
            {
                cout << e.what() << endl;
                return false;
            }
        }
};

// Initialize static members
PaymentService* PaymentService::instance = nullptr; 
mutex PaymentService::mu;

#endif // PaYMENT_SERVICE_H