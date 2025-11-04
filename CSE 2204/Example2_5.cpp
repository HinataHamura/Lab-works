#include <iostream>
#include <iomanip>  
#include <cmath>   
using namespace std;

// Function f(x) = x^2.2 - 69
double f(double x) {
    return pow(x,2.2) - 69;
}


void falsePosition(double a, double b, double tol) {
    if (f(a) * f(b) >= 0) {
        cout << "Invalid initial guesses.\n";
        return;
    }

    double c;
    int iteration = 0;

    cout << fixed << setprecision(6);

    cout << "Iteration       a               b               c               f(c)\n";
    cout << "------------------------------------------------------------------------\n";

    while (fabs(b - a) >= tol) {
        iteration++;

        c = (a * f(b) - b * f(a)) / (f(b) - f(a));

        // Print the current values
        cout << setw(8) << iteration << setw(16)
                  << a << setw(16)
                  << b << setw(16)
                  << c << setw(16)
                  << f(c) << "\n";

        // Check if the root is found
        if (fabs(f(c)) < tol) {
            cout << "--------------------------------------------------------------------------\n";
            cout << "The approximate root is: " << c << "\n";
            return;
        }

        // Update the interval [a, b]
        if (f(a) * f(c) < 0) {
            b = c;  // Root is in [a, c]
        } else {
            a = c;  // Root is in [c, b]
        }
    }

}

int main() {
    double a = 5.0, b = 8.0, tol = 0.0001;
    falsePosition(a, b, tol);
    return 0;
}
