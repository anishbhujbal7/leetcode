class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        vector<vector<int>> triangle;
        for(int  i = 0;i<=rowIndex;i++){
            vector<int> row(i+1,1);
            for(int j=1;j<i;j++){
                row[j] = triangle[i-1][j-1] + triangle[i-1][j];
            }
            triangle.push_back(row);
            
        }
        res = triangle[rowIndex];
        return res;
    }
};
