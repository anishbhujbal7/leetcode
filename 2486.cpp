class Solution {
public:
    int appendCharacters(string s, string t) {
      unordered_map<char,vector<int>> map;
      for(int  i = 0; i<s.size();i++){
        map[s[i]].push_back(i);
      }
      int prevInd = -1;
      int  j = 0;
      while(j<t.size()){
        if(map.count(!t[j])) break;
        auto &vec = map[t[j]];
        auto it = upper_bound(vec.begin(),vec.end(),prevInd);
        if(it == vec.end()) break;
        prevInd = *it;
        j++;
      }
      return t.size()-j;  
    }
};
