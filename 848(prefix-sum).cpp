class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
     int n = shifts.size();   
     vector<int> totalShift(n);
     totalShift[n-1]= shifts[n-1];
     int j =n-2;

     while(j>=0){
        totalShift[j] = (totalShift[j+1]+shifts[j])%26;
        j--;
     }
     for(int i = 0; i<n; i++){
        char c = s[i];
        s[i] = (c-'a'+totalShift[i])%26+'a';
     }
     return s;  
    }
};
