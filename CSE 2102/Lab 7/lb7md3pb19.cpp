#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

bool areTwinPrimes(int n1, int n2) {
    return (isPrime(n1) && isPrime(n2) );
}

int main() {
    int n;
    cout << "Enter a positive integer: ";
    cin >> n;

    if (isPrime(n)) {
        cout << n << " is a prime number.\n";
        if (areTwinPrimes(n, n + 2)) {
            cout << n << " and " << n + 2 << " are twin primes.\n";
        } else {
            cout << n << " and " << n + 2 << " are not twin primes.\n";
        }
    } else {
        cout << n << " is not a prime number.\n";
    }

    return 0;
}
