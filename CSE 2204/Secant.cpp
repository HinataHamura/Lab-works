#include <iostream>
#include <cmath>
#include <iomanip> // For controlling output formatting

using namespace std;

// Define the function f(x) = x^3 - 2x - 5
double f(double x) {
    return x*x*x - 2*x - 5;
}

int main() {
    // Initial guesses
    double x0 = 2.0, x1 = 3.0;
    // Tolerance for convergence
    double epsilon = 0.0001;
    // Maximum number of iterations
    int maxIterations = 100;
    int n = 0;  // iteration counter
    double x2;

    // Print the header for output
    cout << fixed << setprecision(6); // Control output precision
    cout << "Iteration\tx_n\t\tf(x_n)\t\t|x_{n+1} - x_n|" << endl;
    cout << "------------------------------------------------------------------" << endl;

    // Iterative process
    for (n = 1; n <= maxIterations; ++n) {
        // Compute f(x0) and f(x1)
        double fx0 = f(x0);
        double fx1 = f(x1);

        // Check if the denominator will be too small (avoid division by zero)
        if (fabs(fx1 - fx0) < epsilon) {
            cout << "Error: Denominator is too small." << endl;
            return 1;  // Exit the program due to error
        }

        // Use Secant method formula to calculate x2
        x2 = x1 - fx1 * (x1 - x0) / (fx1 - fx0);

        // Calculate the absolute difference |x2 - x1|
        double diff = fabs(x2 - x1);

        // Output the current iteration values
        cout << n << "\t \t" << x1 << "\t" << fx1 << "\t" << diff << endl;

        // Check for convergence
        if (diff < epsilon) {
            cout << "\nConvergence reached. Root = " << x2 << endl;
            break;
        }

        // Update values for the next iteration
        x0 = x1;
        x1 = x2;
    }

    // If maximum iterations reached without convergence
    if (n > maxIterations) {
        cout << "Maximum iterations reached. Last approximation: " << x2 << endl;
    }

    return 0;
}
