#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    // Coefficients
    double a1 = 1;
    double a2 = 1;
    double a3 = 1.0 / 2;
    double a4 = 1.0 / 6;
    double a5 = 1.0 / 24;

    // Initialize b_1
    double b[7];  // Array to store b_n terms (index 0 is unused)
    b[1] = 1;

    // Compute b_n terms
    b[2] = a1;
    b[3] = a1 * b[2] + a2 * b[1];
    b[4] = a1 * b[3] + a2 * b[2] + a3 * b[1];
    b[5] = a1 * b[4] + a2 * b[3] + a3 * b[2] + a4 * b[1];
    b[6] = a1 * b[5] + a2 * b[4] + a3 * b[3] + a4 * b[2] + a5 * b[1];

    // Print b_n terms
    cout << "b_n terms:" << endl;
    for (int n = 1; n <= 6; ++n) {
        cout << "b_" << n << " = " << fixed << setprecision(6) << b[n] << endl;
    }

    // Calculate and print ratios
    cout << "\nRatios of consecutive b_n terms:" << endl;
    for (int n = 2; n <= 6; ++n) {
        double ratio = b[n - 1] / b[n];
        cout << "b_" << (n - 1) << " / b_" << n << " = " << fixed << setprecision(6) << ratio << endl;
    }

    // Check for convergence
    double epsilon = 0.0001;
    for (int n = 3; n <= 6; ++n) {
        double delta_r = abs((b[n - 1] / b[n]) - (b[n - 2] / b[n - 1]));
        if (delta_r < epsilon) {
            cout << "\nConverged at R_" << n << " = " << fixed << setprecision(6) << (b[n - 1] / b[n]) << endl;
            break;
        }
    }

    return 0;
}
