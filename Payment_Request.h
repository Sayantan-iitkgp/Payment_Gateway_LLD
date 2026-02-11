#ifndef PAYMENT_REQUEST_H
#define PAYMENT_REQUEST_H
#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define st string
#define pb push_back

class PaymentRequest
{
private:
    string sender_id;
    string receiver_id;
    double amount;
    string currency;
    string payment_method;
    string status; // pending, completed, failed

public:
    PaymentRequest(const string &sender, const string &receiver, double amt, const string &curr, const string &method)
        : sender_id(sender), receiver_id(receiver), amount(amt), currency(curr), payment_method(method), status("pending") {}

    // Getters
    string getSenderId() const { return sender_id; }
    string getReceiverId() const { return receiver_id; }
    double getAmount() const { return amount; }
    string getCurrency() const { return currency; }
    string getPaymentMethod() const { return payment_method; }
    string getStatus() const { return status; }

    // Setters
    void setStatus(const string &new_status) { status = new_status; }

    void printRequestDetails() const
    {
        cout << "Payment Request Details:" << endl;
        cout << "Sender ID: " << sender_id << endl;
        cout << "Receiver ID: " << receiver_id << endl;
        cout << "Amount: " << amount << " " << currency << endl;
        cout << "Payment Method: " << payment_method << endl;
        cout << "Status: " << status << endl;
    }
};

#endif // PAYMENT_REQUEST_H