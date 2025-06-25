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
        int left=0;
        vector<int> sCount(26,0);
        for(int right=0;right<m;right++){
            while(right-left+1>n){
                sCount[s[left]-'a']--;
                left++;
            }
            sCount[s[right]-'a']++;
            if(right-left+1==n){
                if(sCount==hash) res.push_back(left);
            }
            
        }
       return res; 
    }
};
