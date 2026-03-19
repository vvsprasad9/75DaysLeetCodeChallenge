class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }else{
            vector<int>v(26,0);
            for(char c : s){
                v[c - 'a']++;
            }
            for(char c : t){
                v[c - 'a']--;
            }
            for(int val : v){
                if(val != 0){
                    return false;
                }
            }
            return true;
        }
    }
};