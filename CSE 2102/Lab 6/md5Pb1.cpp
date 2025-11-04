#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void nextPermutation(vector<int>& nums) {
    int n = nums.size();
    int j = n - 2;
    while (j >= 0 && nums[j] >= nums[j + 1]) {
        j--;
    }
    if (j == -1) {
        reverse(nums.begin(), nums.end());
        return;
    }
    int k = n - 1;
    while (nums[j] >= nums[k]) {
        k--;
    }
    swap(nums[j], nums[k]);
    int r = n - 1;
    int s = j + 1;
    while (r > s) {
        swap(nums[r], nums[s]);
        r--;
        s++;
    }
}

int main() {
    vector<int> nums = {1, 2, 3}; 
    sort(nums.begin(), nums.end()); 
    do {
        for (int num : nums) {
            cout << num << " ";
        }
        cout << endl;
        nextPermutation(nums);
    } while (!is_sorted(nums.begin(), nums.end()));
    return 0;
}
