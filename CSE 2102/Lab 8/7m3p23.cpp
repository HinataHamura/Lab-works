#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;


vector<int> baseBExpansion(int n, int b) {
    vector<int> expansion;
    int q = n;
    int k = 0;

    while (q != 0) {
        int ak = q % b;
        q /= b;
        expansion.push_back(ak);
        k++;
    }

    reverse(expansion.begin(), expansion.end());

    return expansion;
}

int main() {
    int n, b;

    cout << "Enter a positive integer (n): ";
    cin >> n;

    cout << "Enter the base (b): ";
    cin >> b;

    if (n <= 1 || b <= 1) {
        cout << "Both n and b must be greater than 1." << endl;
        return 1;
    }

    vector<int> expansion = baseBExpansion(n, b);

    cout << "Base-" << b << " expansion of " << n << " is: ";
    for (int digit : expansion) {
        cout << digit;
    }
    cout << endl;

    return 0;
}
