class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>hm;
        for(string s : strs){
            string k = s;
            sort(k.begin(),k.end());
            hm[k].push_back(s);
        }
        vector<vector<string>>ans;
        for(auto it : hm){
            ans.push_back(it.second);
        }
        return ans;
    }
};