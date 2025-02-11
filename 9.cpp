class Solution {
public:
    bool isPalindrome(int x) {
        std::string str = std::to_string(x);
        int con=1;
        int j=str.size()-1;
        for(int i=0; i<j;i++,j--){
           if(str[i]!=str[j]){
            con=0;
            break;
           }
          
          
        }
        if(con==0) return false;
        else return true;
    }
};
