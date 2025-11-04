#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    // Coefficients a1, a2, a3
    const double a1 = 11.0 / 6.0;
    const double a2 = -1.0;
    const double a3 = 1.0 / 6.0;

    // Initialize b1 and tolerance
    const double tolerance = 0.001;
    double b[100] = {0}; // Array to store b_n terms
    b[1] = 1.0;          // b1 initialization

    // Iterative calculation
    int n;
    for (n = 2; n <= 20; n++) { // Calculating more terms (up to b_20)
        if (n == 2) {
            b[n] = a1; // b2
        } else if (n == 3) {
            b[n] = a1 * b[n - 1] + a2 * b[n - 2]; // b3
        } else {
            b[n] = a1 * b[n - 1] + a2 * b[n - 2] + a3 * b[n - 3]; // bn for n >= 4
        }

        // Compute the ratio Rn = b[n-1] / b[n]
        double ratio = b[n - 1] / b[n];

        // Print results
        if (n >= 3) { // Start printing from b3
            std::cout << "b_" << n << " = " << std::fixed << std::setprecision(6) << b[n] << std::endl;
            std::cout << "b_" << n - 1 << " / b_" << n << " = " << ratio << std::endl;
        }

        // Check for convergence: |Rn - Rn-1| < tolerance
        if (n >= 4) {
            double delta_r = std::abs((b[n - 1] / b[n]) - (b[n - 2] / b[n - 1]));
            if (delta_r < tolerance) {
                break;
            }
        }
    }

    return 0;
}
