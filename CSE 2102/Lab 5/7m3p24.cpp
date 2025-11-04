#include <iostream>
#include <string>
#include <algorithm> 

using namespace std;

string toBinary(int n) {
    string binary = ""; 
    while (n > 0) {
        binary += to_string(n % 2);
        n /= 2;
    }
    
    reverse(binary.begin(), binary.end());
    return binary;
}

int modularExponentiation(int b, int n, int m) {
    int x = 1;
    int power = b % m;
    string binaryN = toBinary(n);
    int k = binaryN.length();

    for (int i = k-1; i >=0 ; i--) {
        if (binaryN[i] == '1') 
            x = (x * power) % m;
        power = (power * power) % m;
    }

    return x;
}

int main() {
    int b, n, m;
    
    cout << "Enter the base (b), exponent (n), and modulus (m): ";
    cin >> b >> n >> m;
    
    int result = modularExponentiation(b, n, m);
    
    cout << "Result of " << b << "^" << n << " mod " << m << " is: " << result << endl;
    
    return 0;
}
