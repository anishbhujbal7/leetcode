class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
       int m=s.size();
       int n=p.size();
       
       vector<int> res;
       vector<int> hash(26,0);
        for(int j=0;j<n;j++){
            hash[p[j]-'a']++;
        }
        
        for(int i=0;i<m;i++){
            vector<int> sCount(26,0);
            string str=s.substr(i,n);
            for(char ch:str){
                sCount[ch-'a']++;
            }
            if(hash==sCount) res.push_back(i);
        }
       return res; 
    }
};
