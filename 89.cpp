class Solution {
public:
    vector<int> grayCode(int n) {
        int totalNo=1<<n;
        vector<int> res(totalNo);
        for(int i=0;i<totalNo;i++){
            res[i]=(i^(i>>1));
        }
        return res;
    }
};
