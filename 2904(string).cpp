class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int left = 0;
        int start = -1;
        int len = INT_MAX;
        int n = s.size();
        int cnt = 0;
        
        for (int right = 0; right < n; right++) {
            if (s[right] == '1') cnt++;

            while (left <= right && cnt == k) {
                int currLen = right - left + 1;

                if (currLen < len) {
                    start = left;
                    len = currLen;
                } else if (currLen == len) {
                    if (s.compare(left, currLen, s, start, len) < 0) {
                        start = left;
                    }
                }

                if (s[left] == '1') cnt--;
                left++;
            }
        }

        return start == -1 ? "" : s.substr(start, len);
    }
};









// class Solution {
// public:
//     string shortestBeautifulSubstring(string s, int k) {
//         int left = 0;
//         int start = -1;
//         int len = INT_MAX;
//         int n = s.size();
//         int cnt = 0;
//         for(int right = 0; right<n; right++){
           
//            if(s[right] == '1'){
//             cnt++;
//            }
//            while(left<=right && cnt == k){
//             int currLen = right-left+1;
//             if(currLen<len){
//                 start = left;
//                 len = currLen;
//             }else if(currLen>len) continue;
//             else{
//                 if(s.compare(left,currLen,s,start,len)<0){
//                     start = left;
//                 }
//             }
//             if(s[left] == '1') cnt--;
//             left++;
//            }
//         }
//         return start == -1 ? "" : s.substr(start,len);
//     }
// };
