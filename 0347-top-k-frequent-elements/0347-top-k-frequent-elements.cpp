class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>hm;
        vector<int>tot;
        for(int i = 0;i<nums.size();i++){
            hm[nums[i]]++;
        }
        vector<vector<int>>ans(nums.size()+1);
        for(auto it : hm){
            ans[it.second].push_back(it.first);
        }
        for(int i = nums.size();i>=0 ;i--){
            for(int x : ans[i]){
                if(tot.size() == k)break;
                tot.push_back(x);
            }
        }
        return tot;
    }
};