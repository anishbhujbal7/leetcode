class Solution {
public:

    string compare(string str){
        string res="";
        for(char c :str){
            if(c=='#'){
                if(!res.empty()) res.pop_back();
            }
            else{
                res.push_back(c);
            }
        }
        return res;
    }

    bool backspaceCompare(string s, string t) {
       return compare(s)==compare(t); 
    }
};
