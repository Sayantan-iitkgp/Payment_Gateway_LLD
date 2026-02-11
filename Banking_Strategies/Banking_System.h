#ifndef BaNKING_SYSTEM_H
#define BaNKING_SYSTEM_H
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define st string
#define pb push_back

// Banking System Interface
//  It is actually belongs to a different server and Remote Proxy is used by the Gateway system to interact with it. But for simplicity, we are including it here.
class BankingSystem
{
private:
    string gateway_name;

public:
    BankingSystem(const string &name) : gateway_name(name) {}

    string getGatewayName() const { return gateway_name; }

    virtual bool processPayment(const string &sender_id, const string &receiver_id, double amount, const string &currency) = 0;
};

#endif // BaNKING_SYSTEM_H