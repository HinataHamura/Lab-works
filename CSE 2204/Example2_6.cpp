#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
// Define tolerance
const double EPSILON = 1e-4;

double g(double x) {
    return 1.0 / (sqrt(x+1));
}

int main() {
    double x0, x1;  // x0: initial guess, x1: next approximation
    int maxIterations = 1000, iteration = 0;

    // Input the initial guess
    cout << "Enter initial guess x0: ";
    cin >> x0;

    // Compute the first approximation
    x1 = g(x0);

    cout << "Iteration        x_n             g(x_n)           |x_{n+1} - x_n|" << endl;
    cout << "--------------------------------------------------------------" << endl;

    // Loop to perform the iteration
    do {
        iteration++;

        // Print the current iteration, x_n, g(x_n), and |x_{n+1} - x_n|
        cout << setw(9) << iteration
                  << setw(16) << fixed << setprecision(6) << x0 
                  << setw(16) << x1
                  << setw(16) << abs(x1 - x0) << endl;

        // Update x0 for the next iteration
        x0 = x1;
        // Compute the next approximation
        x1 = g(x0);

    } while (abs(x1 - x0) >= EPSILON && iteration < maxIterations);

    iteration++;
    cout << setw(9) << iteration
              << setw(16) << fixed << setprecision(6) << x0 
              << setw(16) << x1
              << setw(16) << abs(x1 - x0) << endl;

    cout << "--------------------------------------------------------------" << endl;
    cout << "The approximate root is: " << fixed << setprecision(6) << x1 << endl;

    return 0;
}
