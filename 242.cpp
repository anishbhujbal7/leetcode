class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> st(26,0);
        vector<int> tt(26,0);
        for(char i:s){
            st[i-'a']++;
        }
        for(char i: t){
            tt[i-'a']++;
        }
        if(tt==st) return true;
        return false;
    }
};
