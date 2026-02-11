// This is a Protected Gateway Strategy that acts as a proxy for the actual payment gateways to save it from retry logic handling
#ifndef PROXY_GATEWAY_H
#define PROXY_GATEWAY_H
#include "Payment_Gateway.h"
#include "../Banking_Strategies/Banking_System.h"
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define st string
#define pb push_back
class ProxyGateway : public PaymentGateway
{
private:
    PaymentGateway *realGateway;

public:
    ProxyGateway(PaymentGateway *gateway) : PaymentGateway(gateway->getBankingSystem()), realGateway(gateway) {}

    // Process payment with retry logic
    bool process_with_retry(const string &sender_id, const string &receiver_id, double amount, const string &currency)
    {
        ll retry_time = realGateway->getRetryTime();
        bool status = false;
        for (ll attempt = 0; attempt < retry_time; attempt++)
        {
            status |= realGateway->processPayment(sender_id, receiver_id, amount, currency);
            if (status)
                break;
        }
        return status;
    }

    // validate payment details using the real gateway's validation logic
    bool validatePaymentDetails(const string &sender_id, const string &receiver_id, double amount, const string &currency) override
    {
        // do not validate the payment details in the proxy gateway as it is only responsible for handling retries and not for validating the payment details. The validation should be done by the real gateway.
        return true;
    }

    // initiate payment using the real gateway's initiate payment logic
    void initiatePayment(const string &sender_id, const string &receiver_id, double amount, const string &currency) override
    {
        // do not initiate the payment in the proxy gateway as it is only responsible for handling retries and not for initiating the payment. The initiation should be done by the real gateway.
    }

    // confirm payment status using the real gateway's confirm payment status logic
    bool confirmPaymentStatus(const string &sender_id, const string &receiver_id, double amount, const string &currency) override
    {
        // do not confirm the payment status in the proxy gateway as it is only responsible for handling retries and not for confirming the payment status. The confirmation should be done by the real gateway.
        return true;
    }
};

#endif // PROXY_GATEWAY_H