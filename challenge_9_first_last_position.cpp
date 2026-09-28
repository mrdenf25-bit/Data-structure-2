#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

int findFirst(const vector<int>& nums, int target) {
    int left = 0;
    int right = (int)nums.size() - 1;
    int result = -1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            result = mid;
            right = mid - 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}

int findLast(const vector<int>& nums, int target) {
    int left = 0;
    int right = (int)nums.size() - 1;
    int result = -1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            result = mid;
            left = mid + 1;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return result;
}

// Time: O(log n), Space: O(1)
pair<int, int> searchRange(const vector<int>& nums, int target) {
    return {findFirst(nums, target), findLast(nums, target)};
}

int main() {
    vector<int> nums = {5, 7, 7, 8, 8, 8, 10};
    assert((searchRange(nums, 8) == pair<int, int>{3, 5}));
    assert((searchRange(nums, 6) == pair<int, int>{-1, -1}));
    assert((searchRange(nums, 10) == pair<int, int>{6, 6}));
    assert((searchRange(nums, 5) == pair<int, int>{0, 0}));
    assert((searchRange({}, 3) == pair<int, int>{-1, -1}));

    cout << "All Challenge 9 tests passed." << endl;
    return 0;
}
