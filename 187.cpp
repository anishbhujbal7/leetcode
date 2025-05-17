class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
     vector<string> res;
     int n=s.size();
     unordered_map<string,int> map;
     if(n<10) return res;
     for(int i=0;i<=n-10;i++){
        string sub=s.substr(i,10);
        map[sub]++;

     } 
     for(auto i:map){
        if(i.second>=2) res.push_back(i.first);
     }
     return res; 
    }
};
