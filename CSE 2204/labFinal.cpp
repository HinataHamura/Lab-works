#include <iostream>
#include <iomanip>  
#include <cmath>    
using namespace std;

// Function f(x) = x^3 - x - 1
double f(double x) {
    return x * x * x - x - 1;
}

void bisection(double a, double b, double tol) {
    if (f(a) * f(b) >= 0) {
        cout << "Invalid initial guesses.\n";
        return;
    }

    double m;
    int iteration = 0;

    cout << fixed << setprecision(6);

    cout << "Iteration       a               b               m               f(m)\n";
    cout << "-----------------------------------------------------------------------\n";

    while ((b - a) / 2.0 > tol) {
        iteration++;
        m = (a + b) / 2.0;
        cout << setw(8) << iteration << setw(16)
                  << a << setw(16)
                  << b << setw(16)
                  << m << setw(16)
                  << f(m) << "\n";

        if (f(m) == 0.0) {
            cout << "Exact root found at " << m << "\n";
            return;
        }

        else if (f(a) * f(m) < 0) {
            b = m;  // Root is in the interval [a, m]
        } else {
            a = m;  // Root is in the interval [m, b]
        }
    }

    m = (a + b) / 2.0;
    cout << "-------------------------------------------------------------\n";
    cout << "The approximate root is: " << m << "\n";
}

int main() {
    double a = 1.0, b = 2.0, tol = 0.0001;
    bisection(a, b, tol);
    return 0;
}
