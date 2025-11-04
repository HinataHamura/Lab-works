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

int polynomialValue(int n) {
    return n * n - n + 41;
}

int main() {
    int n;
    cout << "Enter a positive integer n: ";
    cin >> n;
    int result = polynomialValue(n);
    cout << "f(n) = " << result << endl;

    if (isPrime(result)) {
        cout << "f(n) is prime." << endl;
    } else {
        cout << "f(n) is not prime." << endl;
    }
    return 0;
}
