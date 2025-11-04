#include <iostream>
#include <vector>

using namespace std;

// Function to find prime factorization of a number
vector<int> primeFactorization(int n) {
    vector<int> factors;

    // Divide by 2 until n is odd
    while (n % 2 == 0) {
        factors.push_back(2);
        n /= 2;
    }

    // Check for prime factors starting from 3
    for (int i = 3; i * i <= n; i += 2) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }

    // If n is a prime greater than 2
    if (n > 2)
        factors.push_back(n);

    return factors;
}

int main() {
    int n;
    
    cout << "Enter a positive integer: ";
    cin >> n;
    
    if (n <= 0) {
        cout << "Input must be a positive integer." << endl;
        return 1;
    }
    
    vector<int> factors = primeFactorization(n);
    
    cout << "Prime factorization of " << n << " is:";
    for (int factor : factors) {
        cout << " " << factor;
    }
    cout << endl;
    
    return 0;
}
