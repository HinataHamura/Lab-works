#include <iostream>
using namespace std;


bool isOneToOneIdentity(int n) {
    bool outputSet[n + 1] = {false}; 

    for (int x = 1; x <= n; ++x) {
        int output = x;

        if (outputSet[output]) {
            
            return false;
        }

        outputSet[output] = true;
    }

    return true;
}


bool isOneToOneIncrement(int n) {
    bool outputSet[n + 2] = {false};  

    for (int x = 1; x <= n; ++x) {
        int output = x + 1;

        if (outputSet[output]) {
            return false;
        }

        outputSet[output] = true;
    }

    return true;
}


bool isOneToOnePolynomial(int n) {
    bool outputSet[n * n * n + n * n + n + 2] = {false};  

    for (int x = 1; x <= n; ++x) {
        int output = x * x * x + x * x + x + 1;

        if (outputSet[output]) {
            
            return false;
        }

        outputSet[output] = true;
    }

    return true;
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;

   
    if (isOneToOneIdentity(n)) {
        cout << "f(x) = x is one-to-one." << endl;
    } else {
        cout << "f(x) = x is not one-to-one." << endl;
    }

    
    if (isOneToOneIncrement(n)) {
        cout << "f(x) = x + 1 is one-to-one." << endl;
    } else {
        cout << "f(x) = x + 1 is not one-to-one." << endl;
    }

    
    if (isOneToOnePolynomial(n)) {
        cout << "f(x) = x^3 + x^2 + x + 1 is one-to-one." << endl;
    } else {
        cout << "f(x) = x^3 + x^2 + x + 1 is not one-to-one." << endl;
    }

    return 0;
}
