class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
       int m=s.size();
       int n=p.size();
       sort(p.begin(),p.end());
       vector<int> res;
      
       for(int i=0;i<m;i++){
        string str=s.substr(i,n);
        sort(str.begin(),str.end());
        if(str==p) res.push_back(i);
       }
       return res; 
    }
};
