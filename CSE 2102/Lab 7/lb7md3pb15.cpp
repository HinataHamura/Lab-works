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

bool isMersennePrime(int n) {
     if (!isPrime(n)) {
        return false;
    }
    int p = 2; 
    while (pow(2, p) - 1 <= n) {
        if (isPrime(p) && (pow(2, p) - 1 == n)) {
            return true;
        }
        ++p;
    }
    return false;
}

int main() {
    int num;
    cout << "Enter a positive integer: ";
    cin >> num;

    if (isMersennePrime(num)) {
        cout << num << " is a Mersenne prime.\n";
    } else {
        cout << num << " is not a Mersenne prime.\n";
    }

    return 0;
}
