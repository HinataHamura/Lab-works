//Find the prime of the form n^2+1 where n is a positive integer between 1 to 1000.
#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;
    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}

vector<int> findPrimesOfForm() {
    vector<int> primes;
    for (int n = 1; n <= 1000; ++n) { 
        int num = n * n + 1;
        if (isPrime(num)) {
            primes.push_back(num);
        }
    }
    return primes;
}

int main() {
    vector<int> primes = findPrimesOfForm();
    cout << "Primes of the form n^2 + 1 where n is between 1 and 1000:" << endl;
    for (int prime : primes) {
        cout << prime << " ";
    }
    cout << endl;
    return 0;
}
