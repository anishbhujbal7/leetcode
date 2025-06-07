class Solution {
public:
    string getHint(string secret, string guess) {
       int n=secret.size();
    
       unordered_map<char,int> gMap;
       int bullCnt=0;
       int cowCnt=0;
       for(int i=0;i<n;i++){
            char s1=secret[i];
            char g1=guess[i];
            if(s1==g1){
                bullCnt++;
                secret[i]='x';
                guess[i]='x';
            }
            else{
                gMap[g1]++;
            }
        }
        for(int i=0;i<n;i++){
            char s1=secret[i];
            if(secret[i]=='x') continue;
            if(gMap.find(s1)!=gMap.end()){
                if(gMap[s1]>0){
                    cowCnt++;
                    gMap[s1]--;
                }
            }
        }
        return to_string(bullCnt)+'A'+to_string(cowCnt)+'B';
    }
};
