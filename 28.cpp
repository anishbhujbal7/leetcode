class Solution {
public:

    bool findNed(string haystack, string needle, int i){
        int j = 0;
        while(i<haystack.size() && j<needle.size()){
            if(haystack[i]!=needle[j]) return false;
            i++;
            j++;
        }
        return true;
    }

    int strStr(string haystack, string needle) {
        int n = haystack.size();
        int  m = needle.size();
        for(int i = 0; i<n-m+1; i++){
            if(haystack[i] == needle[0]){
                if(findNed(haystack,needle,i)){
                    return i;
                }else{
                    continue;
                }
            }
        }
        return -1;
    }
};
