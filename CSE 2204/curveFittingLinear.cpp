#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Given data
    vector<double> T = {20, 30, 40, 50, 60, 70}; // Temperatures
    vector<double> l = {800.3, 800.4, 800.6, 800.7, 800.9, 801.0}; // Lengths

    // Summations
    double sum_T = 0, sum_l = 0, sum_T2 = 0, sum_Tl = 0;
    int n = T.size();

    for (int i = 0; i < n; i++) {
        sum_T += T[i];
        sum_l += l[i];
        sum_T2 += T[i] * T[i];
        sum_Tl += T[i] * l[i];
    }

    // Print summations
    cout << "Summations:" << endl;
    cout << "Sum(T): " << sum_T << endl;
    cout << "Sum(l): " << sum_l << endl;
    cout << "Sum(T^2): " << sum_T2 << endl;
    cout << "Sum(T * l): " << sum_Tl << endl;

    // Solve for a0 and a1 using the formulas
    double a1 = (n * sum_Tl - sum_T * sum_l) / (n * sum_T2 - sum_T * sum_T);
    double a0 = (sum_l - a1 * sum_T) / n;

    // Output results
    cout << "\nCalculated coefficients:" << endl;
    cout << "a0: " << a0 << endl;
    cout << "a1: " << a1 << endl;

    return 0;
}
