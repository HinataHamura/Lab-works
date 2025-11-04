#include <iostream>
#include <vector>

using namespace std;

// Simpson's 3/8 rule calculation
double simpsonsThreeEighthRule(double h, const vector<double>& y) {
    // Validate input length
    if (y.size() < 2) {
        cerr << "At least two data points are required for integration." << endl;
        return -1;
    }

    double sum = y[0] + y[y.size() - 1]; // Add the first and last terms

    double sum3 = 0.0; // Terms with coefficient 3
    double sum2 = 0.0; // Terms with coefficient 2

    for (size_t i = 1; i < y.size() - 1; ++i) {
        if (i % 3 == 0) {
            sum2 += y[i]; // Terms where index is a multiple of 3
        } else {
            sum3 += y[i]; // All other terms
        }
    }

    return (3 * h / 8) * (sum + 3 * sum3 + 2 * sum2);
}

int main() {
    double h;
    int n;

    // Input the step size
    cout << "Enter the step size (h): ";
    cin >> h;

    // Input the number of data points
    cout << "Enter the number of data points: ";
    cin >> n;

    vector<double> y(n);

    // Input f(x) values
    cout << "Enter the f(x) (y) values:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "f(x)[" << i << "]: ";
        cin >> y[i];
    }

    // Calculate the area using Simpson's 3/8 rule
    double area = simpsonsThreeEighthRule(h, y);

    // Display the result
    if (area != -1) {
        cout << "The area under the curve is: " << area << endl;
    }

    return 0;
}
