#include <iostream>
#include <iomanip>  // For setting output precision
#include <cmath>    // For fabs() function
using namespace std;

// Function f(x) = x^3 - 2x - 5
double f(double x) {
    return x * x * x - 2*x - 5;
}

// Bisection Method implementation
void bisection(double a, double b, double tol) {
    if (f(a) * f(b) >= 0) {
        cout << "Invalid initial guesses.\n";
        return;
    }

    double m;
    int iteration = 0;

    // Setting output format
    cout << fixed << setprecision(6);

    // Printing table header
    cout << "Iteration       a               b               m               f(m)\n";
    cout << "-----------------------------------------------------------------------\n";

    // Perform the Bisection Method
    while ((b - a) / 2.0 > tol) {
        iteration++;
        m = (a + b) / 2.0;
        cout << setw(8) << iteration << setw(16)
                  << a << setw(16)
                  << b << setw(16)
                  << m << setw(16)
                  << f(m) << "\n";

        // Check if m is a root
        if (f(m) == 0.0) {
            cout << "Exact root found at " << m << "\n";
            return;
        }

        // Narrow the interval
        else if (f(a) * f(m) < 0) {
            b = m;  // Root is in the interval [a, m]
        } else {
            a = m;  // Root is in the interval [m, b]
        }
    }

    // After the loop, compute the final midpoint
    m = (a + b) / 2.0;
    cout << "-------------------------------------------------------------\n";
    cout << "The approximate root is: " << m << "\n";
}

int main() {
    double a = 2.0, b = 3.0, tol = 0.0001;
    bisection(a, b, tol);
    return 0;
}
