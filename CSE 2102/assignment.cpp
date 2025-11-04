#include <iostream>
#include <vector>
#include <numeric>  // for std::accumulate
#include <cmath>    // for std::pow

using namespace std;

long long sumOfSubsets(const vector<int>& S) {
    int n = S.size();
    long long totalSum = accumulate(S.begin(), S.end(), 0LL);
    long long result = totalSum * static_cast<long long>(pow(2, n - 1));
    return result;
}

int main() {
    vector<int> S = {1, 2, 3, 4};
    cout << "R = " << sumOfSubsets(S) << endl;  
    return 0;
}
