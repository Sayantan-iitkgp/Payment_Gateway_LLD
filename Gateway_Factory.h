#ifndef GATEWAY_FACTORY_H
#define GATEWAY_FACTORY_H
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define st string
#define pb push_back
#include "./Gateway_Strategies/Payment_Gateway.h"
#include "./Gateway_Strategies/Proxy_Gateway.h"
#include "./Gateway_Strategies/Razorpay_Gateway.h"
#include "./Gateway_Strategies/Paytm_Gateway.h"
#include "./Banking_Strategies/Banking_System.h"
#include "./Banking_Strategies/Razorpay_Banking_System.h"
#include "./Banking_Strategies/Paytm_Banking_System.h"

// It is a Singleton Factory class that creates instances of the payment gateways and the proxy gateway according to the requirements. It also ensures that only one instance of each gateway is created and used throughout the application.
class GatewayFactory
{
private:
    static GatewayFactory *instance;
    static mutex mu;
    GatewayFactory() {} // Private constructor to prevent instantiation

public:

    static GatewayFactory *getInstance()
    {
        // Double-checked locking to ensure thread safety
        if (instance == nullptr)
        {
            unique_lock<mutex> lock(mu);
            if (instance == nullptr)
            {
                instance = new GatewayFactory();
            }
        }
        return instance;
    }

    // Factory method to create instances of the payment gateways
    PaymentGateway *createGateway(const string &gateway_name)
    {
        if (gateway_name == "Razorpay")
        {
            PaymentGateway *razorpay_gateway = new RazorpayGateway(new RazorpayBankingSystem());
            return new ProxyGateway(razorpay_gateway);
        }
        else if (gateway_name == "Paytm")
        {
            PaymentGateway *paytm_gateway = new PaytmGateway(new PaytmBankingSystem());
            return new ProxyGateway(paytm_gateway);
        }
        else
        {
            throw invalid_argument("Invalid gateway name");
        }
    }
};

// Initialize static members
GatewayFactory *GatewayFactory::instance = nullptr;
mutex GatewayFactory::mu;

#endif // GATEWAY_FACTORY_H