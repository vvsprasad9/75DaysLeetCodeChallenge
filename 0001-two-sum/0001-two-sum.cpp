class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>hm;
        for(int i = 0;i<nums.size();i++){
            int v = target - nums[i];
            if(hm.count(v)){
                return {hm[v],i};
            }
            hm[nums[i]] = i;
        }
        return{};
        
    }
};