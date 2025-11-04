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

// Function to find modular multiplicative inverse using extended Euclidean algorithm
long long modInverse(long long a, long long m) {
    long long m0 = m;
    long long y = 0, x = 1;

    if (m == 1)
        return 0;

    while (a > 1) {
        long long q = a / m;
        long long t = m;

        m = a % m;
        a = t;
        t = y;

        y = x - q * y;
        x = t;
    }

    if (x < 0)
        x += m0;

    return x;
}

// Function to calculate private key d from public key e and primes p, q
long long calculatePrivateKey(long long e, long long p, long long q) {
    long long phi = (p - 1) * (q - 1);
    return modInverse(e, phi);
}

int main() {
    // Given parameters
    long long p = 61;  // Example prime p
    long long q = 53;  // Example prime q
    long long n = p * q;  // Modulus n
    long long e = 17;  // Public exponent e

    // Calculate private key d
    long long d = calculatePrivateKey(e, p, q);

    // Output the private key d
    cout << "Private key d: " << d << endl;

    return 0;
}
