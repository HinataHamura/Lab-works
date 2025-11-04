#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to calculate factorial
int factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; ++i) {
        fact *= i;
    }
    return fact;
}

// Function to implement Newton's Forward Interpolation
double forwardInterpolation(const vector<int>& x, const vector<int>& y, int desired_x) {
    int n = x.size();
    
    // Create a 2D array for forward differences (difference table)
    vector<vector<double>> diffTable(n, vector<double>(n));

    // Fill the first column of the difference table with y[] values
    for (int i = 0; i < n; ++i) {
        diffTable[i][0] = y[i];
    }

    // Calculate the forward differences
    for (int j = 1; j < n; ++j) {
        for (int i = 0; i < n - j; ++i) {
            diffTable[i][j] = diffTable[i + 1][j - 1] - diffTable[i][j - 1];
        }
    }

    // Calculate h (difference between consecutive x values)
    double h = x[1] - x[0];
    
    // Calculate p (factor for interpolation)
    double p = (desired_x - x[0]) / h;

    // Initialize the result with the first y value
    double result = y[0];

    // Calculate the final result using the forward difference table
    for (int i = 1; i < n; ++i) {
        double product = p;
        for (int k = 1; k < i; ++k) {
            product *= (p - k);
        }
        result += (product * diffTable[0][i]) / factorial(i);
    }

    // Print the forward difference table
    cout << "Forward Difference Table\n";
    cout << "x\ty\tDel y\tDel^2 y\tDel^3 y\n";
    for (int i = 0; i < n; ++i) {
        cout << x[i] << "\t" << y[i];
        for (int j = 1; j < n - i; ++j) {
            cout << "\t" << diffTable[i][j];
        }
        cout << endl;
    }

    return result;
}

int main() {
    // Given data points
    vector<int> x = {1, 3, 5, 7};   // x[] values
    vector<int> y = {24, 120, 336, 720};  // y[] values

    // Desired x value for interpolation
    int desired_x = 8;

    // Get the interpolated value using Newton's Forward Interpolation
    double result = forwardInterpolation(x, y, desired_x);

    // Output the result
    cout << "The value of y(" << desired_x << ") is: " << result << endl;

    return 0;
}
