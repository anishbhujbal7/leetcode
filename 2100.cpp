class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();
        if(time>n) return {};
        vector<int> nonInc(n);
        vector<int> nonDec(n);
        int count  = 0;
        for(int i= 1;i<n;i++){
            if(security[i-1]>=security[i]){
                count++;
                
            }
            else{
                count = 0;
                
            }
            nonInc[i]=count;
        }
        count  =0;
        for(int i = n-2;i>=0;i--){
            if(security[i+1]>=security[i]){
                count++;
                
            }
            else{
                count  = 0;
                
            }
            nonDec[i]= count;
        }
        vector<int> ans;
        for(int  i = time; i<n-time;i++){
            if(nonDec[i]>=time&&nonInc[i]>=time) ans.push_back(i);
        }
        return ans;
    }
};
