#include <iostream>
#include <vector>
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

pair<int, int> findPrimesForGoldbach(int n) {
    pair<int, int> primesPair;
    for (int i = 2; i <= n / 2; ++i) {
        if (isPrime(i) && isPrime(n - i)) {
            primesPair.first = i;
            primesPair.second = n - i;
            break;
        }
    }
    return primesPair;
}

int main() {
    int n;
    cout << "Enter an even integer n: ";
    cin >> n;

    if (n % 2 != 0) {
        cout << "Please enter an even integer." << endl;
        return 1;
    }

    pair<int, int> primesPair = findPrimesForGoldbach(n);
    if (primesPair.first != 0 && primesPair.second != 0) {
        cout << "Two prime numbers that sum up to " << n << " are: "
                  << primesPair.first << " and " << primesPair.second << endl;
    } else {
        cout << "Goldbach's conjecture is not satisfied for " << n << endl;
    }

    return 0;
}
