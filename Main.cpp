#include <bits/stdc++.h>
using namespace std;
#include "Payment_Controller.h"
#include "Payment_Request.h"
#define ll long long int
#define st string
#define pb push_back

// Think it like a Facade design pattern where the PaymentController class is the Facade that provides a simple interface to the complex subsystem of payment processing. It interacts with the PaymentService class which is responsible for processing the payments using different gateways and banking systems. The PaymentController class also handles the validation of the payment requests and returns the appropriate response to the client.

int main()
{
    // Create a payment request
    PaymentRequest request1("user123", "merchant456", 100.0, "USD", "Razorpay");

    // Get the payment controller instance
    PaymentController *controller = PaymentController::getInstance();

    // Handle the payment request
    bool payment_status = controller->handlePaymentRequest(request1);

    if (payment_status)
    {
        request1.setStatus("completed");
        cout << "Payment processed successfully!" << endl;
    }
    else
    {
        request1.setStatus("failed");
        cout << "Payment processing failed. Please try again." << endl;
    }
   
    request1.printRequestDetails();

    // Create another payment request
    PaymentRequest request2("user789", "merchant012", 5000.0, "INR", "Paytm");
    // Handle the payment request
    payment_status = controller->handlePaymentRequest(request2);
    if (payment_status)
    {
        request2.setStatus("completed");
        cout << "Payment processed successfully!" << endl;
    }
    else
    {
        request2.setStatus("failed");
        cout << "Payment processing failed. Please try again." << endl;
    }
    request2.printRequestDetails();
    return 0;
}