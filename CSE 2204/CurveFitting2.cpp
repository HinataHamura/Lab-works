#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Given data
    vector<double> x = {0, 2, 5, 7}; // x values
    vector<double> y = {-1, 5, 12, 20}; // y values

    // Initialize summations
    double sum_x = 0, sum_y = 0, sum_x2 = 0, sum_xy = 0;
    int n = x.size();

    // Calculate summations
    for (int i = 0; i < n; i++) {
        sum_x += x[i];
        sum_y += y[i];
        sum_x2 += x[i] * x[i];
        sum_xy += x[i] * y[i];
    }

    // Display the summations
    cout << "Summations:" << endl;
    cout << "Sum(x): " << sum_x << endl;
    cout << "Sum(y): " << sum_y << endl;
    cout << "Sum(x^2): " << sum_x2 << endl;
    cout << "Sum(xy): " << sum_xy << endl;

    // Solve for a0 and a1 using the formulas
    double a1 = (n * sum_xy - sum_x * sum_y) / (n * sum_x2 - sum_x * sum_x);
    double a0 = (sum_y - a1 * sum_x) / n;

    // Output the results
    cout << "\nCalculated coefficients:" << endl;
    cout << "a0: " << a0 << endl;
    cout << "a1: " << a1 << endl;

    // Predict y for x = 5
    double x_value = 5;
    double y_value = a0 + a1 * x_value;
    cout << "\nPredicted y for x = 5: " << y_value << endl;

    return 0;
}
