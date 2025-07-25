class Solution {
public:

    int leftSide(int i,vector<int>& arr,vector<int>& leftArr){
        if(i==0) return 0;
        if(leftArr[i]!=-1) return leftArr[i];
        if(arr[i-1]<arr[i]){
            return leftArr[i] = 1+leftSide(i-1,arr,leftArr);
        }
        else{
            return 0;
        }
    }

    int rightSide(int i,vector<int>& arr,vector<int>& rightArr,int n){
        if(i==n-1) return 0;
        if(rightArr[i]!=-1) return rightArr[i];
        if(arr[i+1]<arr[i]){
            return rightArr[i] = 1+rightSide(i+1,arr,rightArr,n);
        }
        else{
            return 0;
        }
    }

    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        if(n<3) return  0;
        vector<int> rightArr(n,-1);
        vector<int> leftArr(n,-1);
        for(int i = 0;i<n;i++){
            int nothing1= rightSide(i,arr,rightArr,n);
            int nothing2 = leftSide(i,arr,leftArr);
        }
        int maxLen = 0;
        for(int i = 0;i<n;++i){
            if(leftArr[i]>0&&rightArr[i]>0){
                maxLen = max(maxLen,(leftArr[i]+rightArr[i]+1));
            }
        }
        return maxLen;
    }
};
