class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int col=0;
        while(col<n){
            for(int row = col+1;row<n;row++){
                swap(matrix[row][col],matrix[col][row]);
            }
            col++;
        }
        int row =0;
        while(row<n){
            int i= 0;
            int j=n-1;
            while(i<j){
                swap(matrix[row][i], matrix[row][j]);
                ++i;
                --j;
            }
            row++;
        }
    }
};
