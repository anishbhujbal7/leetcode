class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,int> map;
        unordered_set<char> set;
        for(int  i = 0;i<s.size();i++){
            if(map.count(s[i])){
                char c  = map[s[i]];
                if(c!=t[i]) return false;
            }
            else{
                if(set.count(t[i])) return false;
                map[s[i]]=t[i];
                set.insert(t[i]);
            }
        }
        return true;
    }
};
