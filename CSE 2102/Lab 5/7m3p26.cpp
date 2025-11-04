#include <iostream>
using namespace std;

int extendedEuclidean(int a, int b, int &s, int &t) {
    if (b == 0) {
        s = 1;
        t = 0;
        return a;
    }

    int s1, t1;
    int gcd = extendedEuclidean(b, a % b, s1, t1);

    s = t1;
    t = s1 - (a / b) * t1;

    return gcd;
}

int main() {
    int a, b;
    
    cout << "Enter two positive integers a and b: ";
    cin >> a >> b;
    
    if (a <= 0 || b <= 0) {
        cout << "Both numbers must be positive." << endl;
        return 1;
    }
    
    int s, t;
    int gcd = extendedEuclidean(a, b, s, t);
    
    cout << "gcd(" << a << ", " << b << ") = " << gcd << endl;
    cout << "s = " << s << ", t = " << t << endl;
    cout << "s * " << a << " + t * " << b << " = " << s * a + t * b << endl;
    
    return 0;
}
