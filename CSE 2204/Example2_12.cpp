#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

// Define the function f(x) = x - e^(-x)
double f(double x) {
    return x - exp(-x);
}

// Define the derivative f'(x) = 1 + e^(-x)
double f_prime(double x) {
    return 1 + exp(-x);
}

// Newton-Raphson method
void newtonRaphson(double initialGuess, double tolerance, int maxIterations) {
    double xn = initialGuess; // Initial guess
    double xn1;              // Next approximation
    int iteration = 0;       // Iteration counter
    double error = 0;        // Error |xn+1 - xn|

    cout << "Iteration\t x_n\t\t f(x_n)\t\t |x_{n+1} - x_n|" << endl;
    cout << "----------------------------------------------------------------" << endl;

    do {
        xn1 = xn - f(xn) / f_prime(xn); // Newton-Raphson formula
        error = abs(xn1 - xn);    // Calculate error
        cout << setw(9) << iteration + 1 << "\t" 
                  << fixed << setprecision(6) << xn << "\t" 
                  << f(xn) << "\t" 
                  << error << endl;

        xn = xn1;                      // Update xn
        iteration++;
        if (iteration >= maxIterations) {
            cout << "Maximum iterations reached without convergence!" << endl;
            return;
        }
    } while (error >= tolerance);

    cout << "----------------------------------------------------------------" << endl;
    cout << "The approximate root is: " << xn1 << endl;
}

int main() {
    double initialGuess = 1.0; // Initial guess
    double tolerance = 0.0001; // Tolerance for convergence
    int maxIterations = 100;  // Maximum number of iterations

    newtonRaphson(initialGuess, tolerance, maxIterations);

    return 0;
}
