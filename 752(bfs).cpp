class Solution {
public:

    string rotateUp(string str, int i){
        str[i]=(str[i]=='9') ? '0': str[i]+1;
        return str;
    }

    string rotateDown(string str, int i){
        str[i]=(str[i]=='0') ? '9':str[i]-1;
        return str;
    }

    int openLock(vector<string>& deadends, string target) {
      
       unordered_set<string> visited;
       unordered_set<string> deadEnds(deadends.begin(), deadends.end());
       if (deadEnds.count("0000")) return -1;
       visited.insert("0000");
       queue<pair<string, int>> q;
       q.push({"0000",0});
       int moves=0;
       while(!q.empty()){
            string str = q.front().first;
            int m =q.front().second;
            moves=max(moves,m);
            if(str==target) return moves;
            q.pop();
                for(int i =0;i<str.size();i++){
                    string nextUp=rotateUp(str,i);
                    string nextDown=rotateDown(str,i);
                    if(!visited.count(nextUp)&&!deadEnds.count(nextUp)){
                        q.push({nextUp,m+1});
                        visited.insert(nextUp);
                    }

                    if(!visited.count(nextDown)&&!deadEnds.count(nextDown)){
                        q.push({nextDown,m+1});
                        visited.insert(nextDown);
                    }
                }
       }
       return -1; 
    }
};
