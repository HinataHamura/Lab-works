#include <iostream>
#include <vector>
using namespace std;

double trapezoidalRule(const vector<double>& y, double h) {
    double sum = y.front() + y.back(); 

    for (size_t i = 1; i < y.size() - 1; ++i) {
        sum += 2 * y[i];
    }

    return (h / 2) * sum;
}

double simpsonsOneThirdRule(const vector<double>& y, double h) {
    if (y.size() % 2 == 0) {
        cerr << "Simpson's 1/3 rule requires an odd number of points (even number of subintervals)." << endl;
        return -1; // Error case
    }

    double sum = y.front() + y.back(); // Add the first and last terms

    // Sum terms with coefficients 4 and 2
    for (size_t i = 1; i < y.size() - 1; ++i) {
        if (i % 2 == 0) {
            sum += 2 * y[i]; // Even-indexed terms (y2, y4, ...)
        } else {
            sum += 4 * y[i]; // Odd-indexed terms (y1, y3, ...)
        }
    }

    return (h / 3) * sum;
}

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
    int n;
    double h;

    cout << "Enter the number of data points: ";
    cin >> n;

    cout << "Enter the step size (h): ";
    cin >> h;

    vector<double> y(n);

    cout << "Enter the f(x)=(y) values:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "f(x)[" << i << "]: ";
        cin >> y[i];
    }

    double area = trapezoidalRule(y, h);
    double area1 = simpsonsOneThirdRule(y, h);
    double area2 = simpsonsThreeEighthRule(h, y);


    cout << "The area under the curve is(Trapezoidal Rule): " << area << endl;
    cout << "The area under the curve is(Simpson's 1/3 Rule): " << area1 << endl;
    cout << "The area under the curve is(Simpson's 3/8 Rule): " << area2 << endl;

    return 0;
}
