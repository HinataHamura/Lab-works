#include <iostream>
#include <vector>
using namespace std;
void findFirstAndLastOccurrences(vector<int>nums, int& firstOccurrence, int& lastOccurrence) {
    int n = nums.size();
    if (n == 0) {
        firstOccurrence = -1;
        lastOccurrence = -1;
        return;
    }
    int largest = nums[0];
    firstOccurrence = -1;
    lastOccurrence = -1;

    for (int i = 0; i < n; ++i) {
        if (nums[i] == largest) {
            if (firstOccurrence == -1) {
                firstOccurrence = i;
            }
            lastOccurrence = i;
        } else if (nums[i] > largest) {
            largest = nums[i];
            firstOccurrence = i;
            lastOccurrence = i;
        }
    }
}

int main() {
    vector<int> numbers = {3, 5, 2, 8, 5, 7, 9, 5, 8};
    int firstOccurrence, lastOccurrence;
    findFirstAndLastOccurrences(numbers, firstOccurrence, lastOccurrence);

    cout << "First occurrence of the largest integer: " << firstOccurrence << endl;
    cout << "Last occurrence of the largest integer: " << lastOccurrence << endl;

    return 0;
}
