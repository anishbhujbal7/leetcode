class Solution {
public:

    string makeString(string str, char c, int j){
        string res = "";
        for(int  i = 0; i<str.size(); i++){
            if( i == j) res += c;
            else res += str[i];
        }
        return res;
    }

    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> bankMap(bank.begin(), bank.end());
       queue<pair<string,int>> q;
       q.push({startGene,0});
       unordered_set<string> set;
       set.insert(startGene);
       
       string str2 = "ACGT";
       while(!q.empty()){
        string str = q.front().first;
        int moves = q.front().second;
        q.pop();
        if(str == endGene) return moves;
        for(int  i =0; i<str.size(); i++){
            for(char c : str2){
                string newStr = makeString(str, c, i);
               
                if(!set.count(newStr)){
                    if(bankMap.count(newStr)){
                        q.push({newStr, moves+1});
                        set.insert(newStr);
                    }
                }
            }
        }
       }
       return -1; 
    }
};
