class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        unordered_map<char, vector<int>> map;
        for(int i =0; i<s.size();i++){
            map[s[i]].push_back(i);
        }
        
        int count =0;

        for(string word : words){
            bool isSubSeq = true;
            int prevInd = -1;
            for(char c : word){
                if(!map.count(c)){
                    isSubSeq = false;
                    break;
                }
                auto &vec = map[c];
                auto it  = upper_bound(vec.begin(), vec.end(), prevInd);
                if(it == vec.end()){
                    isSubSeq = false;
                    break;
                }
                prevInd = *it;
            }
            if (isSubSeq) count++;
        }

       return count;
    }
};
