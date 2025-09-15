class Solution {
public:
    int numberOfSpecialChars(string word) {
      vector<char> map(26,0);
      vector<char> toRemove;
      for(char c : word){
        if(islower(c)){
            if(!map.count(c)){
                map[c] = '*';
            }else{
                if(map[c]!='*'){
                    map.erase(c);
                }
            }
        }else{
            if(!map.count(tolower(c))){
                toRemove.push_back(c);
                continue;
            }else{
                map[tolower(c)] = '+';
            }
        }
      }
      for(auto pair:map){
        if(pair.second == '*') toRemove.push_back(pair.first);
      }
      for(char c : toRemove){
        if(map.count(c)){
            map.erase(c);
        }
      }
      return map.size();  
    }
};
