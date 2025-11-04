#include <iostream>
using namespace std;
void nextCombination(int combination[], int n, int r) {
    int i = r;
    while (i > 0 && combination[i - 1] == n - r + i) {
        i--;
    }
    if (i > 0) {
        combination[i - 1]++;
        for (int j = i; j < r; j++) {
            combination[j] = combination[i - 1] + j - i + 1;
        }
    }
}

int main() {
    int combination[] = {1, 2, 5, 6};
    int n = 6; 
    int r = 4;
    nextCombination(combination, n, r);
    for (int i = 0; i < r; i++) {
        cout << combination[i] << " ";
    }
    cout << endl;

    return 0;
}
