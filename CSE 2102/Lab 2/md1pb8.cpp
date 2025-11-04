#include <iostream>
#include <cmath>
using namespace std;

void findPythagoreanPairs(int z) {
    bool found = false;

    for (int x = 1; x < z; ++x) {
        for (int y = x; y < z; ++y) {
            if (x * x + y * y == z * z) {
                cout << "Pair found: (" << x << ", " << y << ")" << endl;
                found = true;
            }
        }
    }

    if (!found) {
        cout << "No Pythagorean pair found for z = " << z << endl;
    }
}

int main() {
    int z;

    cout << "Enter the value of z: ";
    cin >> z;

    findPythagoreanPairs(z);

    return 0;
}
