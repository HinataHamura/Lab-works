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

int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int a, b;
    cout << "Enter two positive integers: ";
    cin >> a >> b;
    if (a <= 0 || b <= 0) {
        cout << "Both numbers must be positive." << endl;
        return 1;
    }
    int result = lcm(a, b);
    cout << "LCM of " << a << " and " << b << " is: " << result << endl;
    return 0;
}
