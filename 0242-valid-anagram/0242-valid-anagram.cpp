class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }else{
            bool flag = false;
            unordered_map<char,int>hm1;
            unordered_map<char,int>hm2;
            for(int i = 0;i<s.size();i++){
                hm1[s[i]]++;
                hm2[t[i]]++;
            }
            for(auto it : hm1){
                if(hm1[it.first] != hm2[it.first]){
                    return false;
                }
            }
            return true;
        }
    }
};