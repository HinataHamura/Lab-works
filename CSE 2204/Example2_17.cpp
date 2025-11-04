#include <iostream>
#include <cmath>

using namespace std;

int main() {
    // Initialize coefficients
    double a1 = 1.0, a2 = -1.0/4.0, a3 = 1.0/36.0, a4 = -1.0/576.0, a5 = 1.0/14400.0, a6 = -1.0/518400.0, a7 = 1.0/25401600.0;

    // Initialize b1
    double b[9];
    b[1] = 1.0;

    // Set tolerance
    double epsilon = 0.001;

    // Compute b_n terms for n = 2 to n = 8
    for (int n = 2; n <= 8; ++n) {
        if (n == 2) {
            b[2] = a1;
        } else if (n == 3) {
            b[3] = a1 * b[2] + a2 * b[1];
        } else if (n == 4) {
            b[4] = a1 * b[3] + a2 * b[2] + a3 * b[1];
        } else if (n == 5) {
            b[5] = a1 * b[4] + a2 * b[3] + a3 * b[2] + a4 * b[1];
        } else if (n == 6) {
            b[6] = a1 * b[5] + a2 * b[4] + a3 * b[3] + a4 * b[2] + a5 * b[1];
        } else if (n == 7) {
            b[7] = a1 * b[6] + a2 * b[5] + a3 * b[4] + a4 * b[3] + a5 * b[2] + a6 * b[1];
        } else if (n == 8) {
            b[8] = a1 * b[7] + a2 * b[6] + a3 * b[5] + a4 * b[4] + a5 * b[3] + a6 * b[2] + a7 * b[1];
        }
    }

    // Calculate successive ratios and check for convergence
    double R[9];
    for (int n = 2; n <= 8; ++n) {
        R[n] = b[n-1] / b[n];
        cout << "b_" << n << " = " << b[n] << endl;
        if (n > 2) {
            cout << "b_" << (n-1) << " / b_" << n << " = " << R[n] << endl;
        }
    }

    // Check for convergence
    if (fabs(R[8] - R[7]) < epsilon) {
        cout << "Convergence reached. Approximate root = " << R[8] << endl;
    } else {
        cout << "Convergence not reached." << endl;
    }

    return 0;
}
