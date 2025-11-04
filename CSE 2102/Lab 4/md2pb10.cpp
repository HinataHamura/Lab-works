#include <iostream>
#include <cmath>
using namespace std;
double calculateGoldenRatio() {
    double a = 1.0;
    double b = -1.0;
    double c = -1.0;

    
    double discriminant = b * b - 4 * a * c;

    if (discriminant >= 0) {
        
        double solution1 = (-b + sqrt(discriminant)) / (2 * a);
        double solution2 = (-b - sqrt(discriminant)) / (2 * a);
        double goldenRatio = (solution1 > 0) ? solution1 : solution2;

        return goldenRatio;
    } else {
        
        cout << "Error: No real solutions for the quadratic equation." << endl;
        return -1.0; 
    }
}

int main() {
    double goldenRatio = calculateGoldenRatio();

    if (goldenRatio != -1.0) {
        cout << "The value of the golden ratio is: " << goldenRatio << endl;
    }

    return 0;
}
