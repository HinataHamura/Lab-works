#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Given data points
    vector<double> x = {0.0, 1.0, 2.0};
    vector<double> y = {1.0, 6.0, 17.0};

    // Summations needed for the equations
    double sum_x = 0, sum_x2 = 0, sum_x3 = 0, sum_x4 = 0;
    double sum_y = 0, sum_xy = 0, sum_x2y = 0;
    int n = x.size();

    // Compute summations
    for (int i = 0; i < n; i++) {
        double x_val = x[i];
        double y_val = y[i];
        double x2 = x_val * x_val;
        double x3 = x2 * x_val;
        double x4 = x3 * x_val;

        sum_x += x_val;
        sum_x2 += x2;
        sum_x3 += x3;
        sum_x4 += x4;
        sum_y += y_val;
        sum_xy += x_val * y_val;
        sum_x2y += x2 * y_val;
    }

    // Print the summations
    cout << "Summations:" << endl;
    cout << "Sum(x): " << sum_x << endl;
    cout << "Sum(x^2): " << sum_x2 << endl;
    cout << "Sum(x^3): " << sum_x3 << endl;
    cout << "Sum(x^4): " << sum_x4 << endl;
    cout << "Sum(y): " << sum_y << endl;
    cout << "Sum(xy): " << sum_xy << endl;
    cout << "Sum(x^2y): " << sum_x2y << endl;

    // Coefficient matrix
    double a[3][4] = {
        {n, sum_x, sum_x2, sum_y},
        {sum_x, sum_x2, sum_x3, sum_xy},
        {sum_x2, sum_x3, sum_x4, sum_x2y}
    };

    // Gaussian elimination
    for (int i = 0; i < 3; i++) {
        for (int j = i + 1; j < 3; j++) {
            double factor = a[j][i] / a[i][i];
            for (int k = 0; k < 4; k++) {
                a[j][k] -= factor * a[i][k];
            }
        }
    }

    // Back substitution
    double a2 = a[2][3] / a[2][2];
    double a1 = (a[1][3] - a[1][2] * a2) / a[1][1];
    double a0 = (a[0][3] - a[0][2] * a2 - a[0][1] * a1) / a[0][0];

    // Output the results
    cout << "\nCalculated coefficients:" << endl;
    cout << "a0: " << a0 << endl;
    cout << "a1: " << a1 << endl;
    cout << "a2: " << a2 << endl;

    // Output the polynomial
    cout << "\nThe polynomial is: y = " << a0 << " + " << a1 << "x + " << a2 << "x^2" << endl;

    return 0;
}
