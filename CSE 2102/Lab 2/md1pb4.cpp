#include <iostream>
using namespace std;

//  !(p ∧ q) ∧ r
bool proposition1(bool p, bool q, bool r) {
    return !(p && q) && r;
}

//  !p ∨ !q ∧ r
bool proposition2(bool p, bool q, bool r) {
    return (!p || !q) && r;
}

int main() {
    for (int p = 0; p <= 1; ++p) {
        for (int q = 0; q <= 1; ++q) {
            for (int r = 0; r <= 1; ++r) {
                bool result1 = proposition1(p, q, r);
                bool result2 = proposition2(p, q, r);
                if (result1 != result2) {
                    cout << "The propositions are NOT equivalent." << endl;
                    return 0;
                }
            }
        }
    }

    cout << "The propositions are equivalent." << endl;
    return 0;
}
