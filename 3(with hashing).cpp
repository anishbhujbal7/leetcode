class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_len=0;
        for (int i=0;i<s.length();i++){
            int hash[250]={0};
            for(int j=i;j<s.length();j++){
                if (hash[s[j]]==1) break;
                int len=j-i+1;
                max_len=max(len,max_len);
                hash[s[j]]=1;


            }
        }
        return max_len;
    }
};  
