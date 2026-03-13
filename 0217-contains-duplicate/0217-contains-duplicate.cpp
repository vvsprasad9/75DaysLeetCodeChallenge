class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int>hs;
        for(int i = 0;i<nums.size();i++)
            hs.insert(nums[i]);

        return nums.size() != hs.size();
    }
};