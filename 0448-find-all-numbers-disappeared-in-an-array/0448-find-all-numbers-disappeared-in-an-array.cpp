class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int>v(n+1,0);
        for(int i = 0;i<n;i++){
            v[nums[i]]++;
        }
        nums.clear();
        for(int i = 1;i<=n;i++){
            if(v[i] == 0){
                nums.push_back(i);
            }
        }
        return nums;
    }
};