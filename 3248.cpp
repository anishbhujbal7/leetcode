class Solution {
public:
    int finalPositionOfSnake(int n, vector<string>& commands) {
        int x = 0;
        int y = 0;
       for (string str:commands){
        if (str == "RIGHT"){
            y+=1;
        }else if (str == "LEFT"){
            y-=1;
        }else if(str == "UP"){
            x-=1;
        }else{
            x+=1;
        }
       }

       int res = (x*n)+y;

       return res;
    }
};
