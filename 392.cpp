class Solution {
public:
    bool isSubsequence(string s, string t) {
        unordered_map<char,vector<int>> map;
        for(int i = 0; i<t.size();i++){
            map[t[i]].push_back(i);
        }

        int  prevInd = -1;
        bool isSubSeq = true;
        for(char c : s){
            if(!map.count(c)){
                isSubSeq =false;
                break;
            }

            auto &vec = map[c];
            auto it = upper_bound(vec.begin(),vec.end(), prevInd);
            if(it == vec.end()){
                isSubSeq = false;
                break;
            }
            prevInd = *it;
        }
        return isSubSeq;
    }
};
