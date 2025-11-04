#include <iostream>
#include <cmath>
using namespace std;

// Function to calculate modular exponentiation
long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    base = base % mod;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % mod;
        exp = exp >> 1;
        base = (base * base) % mod;
    }
    return result;
}

// Function to encrypt a message using RSA
long long encrypt(long long message, long long e, long long n) {
    return power(message, e, n);
}

int main() {
    long long m ;
    cout<<"Enter the message to encrypt: ";
    cin>>m;
    // Given parameters
    long long p = 61;  // Example prime p
    long long q = 53;  // Example prime q
    long long n = p * q;  // Modulus n
    long long e = 17;  // Public exponent e
    long long message = m;  // Message to encrypt

    // Check if e is relatively prime to (p-1)(q-1)
    if (e <= 1 || e >= (p - 1) * (q - 1)) {
        cout << "Invalid value of e. It should be greater than 1 and less than (p-1)(q-1)." << endl;
        return 1;
    }

    // Encrypt the message
    long long encrypted_message = encrypt(message, e, n);

    // Output the encrypted message
    cout << "Encrypted message: " << encrypted_message << endl;

    return 0;
}
