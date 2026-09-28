#include <iostream>
#include <vector>
#include <unordered_map>
#include <stdexcept>
#include <cassert>
using namespace std;

// Time: O(n), Space: O(n)
pair<int, int> twoSum(const vector<int>& nums, int target) {
    unordered_map<int, int> seen; // value -> index

    for (int i = 0; i < (int)nums.size(); i++) {
        int complement = target - nums[i];
        auto it = seen.find(complement);
        if (it != seen.end()) {
            return {it->second, i};
        }
        seen[nums[i]] = i;
    }
    throw runtime_error("No two sum solution exists");
}

int main() {
    assert((twoSum({2, 7, 11, 15}, 9) == pair<int, int>{0, 1}));
    assert((twoSum({3, 2, 4}, 6) == pair<int, int>{1, 2}));
    assert((twoSum({-3, 4, 3, 90}, 0) == pair<int, int>{0, 2}));
    assert((twoSum({3, 3}, 6) == pair<int, int>{0, 1}));

    cout << "All Challenge 2 tests passed." << endl;
    return 0;
}
