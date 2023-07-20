#include <algorithm>

class Solution {
public:
  int maxProduct(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());

    int maxVal = nums[nums.size() - 1];
    int secMaxVal = nums[nums.size() - 2];

    return (maxVal - 1) * (secMaxVal - 1);
  }
};
