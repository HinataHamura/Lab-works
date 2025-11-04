#include <iostream>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    int a, b;
    cout << "Enter two positive integers: ";
    cin >> a >> b;
    
    if (a <= 0 || b <= 0) {
        cout << "Both numbers must be positive." << endl;
        return 1;
    }
    
    if (a < b)
        swap(a, b);
    
    int result = gcd(a, b);
    cout << "GCD of " << a << " and " << b << " is: " << result << endl;
    
    return 0;
}
