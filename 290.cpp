class Solution {
public:
    bool wordPattern(string pattern, string s) {
       unordered_map<char,string>mymap;
       unordered_map<string,char> mymap2;
        istringstream iss(s);            // Create a stream from the string
        vector<string> words;
        string word;
        while (iss >> word) {            // Extract words separated by spaces
        words.push_back(word);       // Store in vector
        }
        if (words.size()!=pattern.size()) return false;
        for (int i =0; i<pattern.size();i++){
            char pat=pattern[i];
            string str=words[i];
            if(mymap.find(pat)!=mymap.end()){
                if(mymap[pat]!=str) return false;
            }
            if(mymap2.find(str)!=mymap2.end()){
                if(mymap2[str]!=pat) return false;
            }
            mymap[pat]=str;
            mymap2[str]=pat;
        }
        return true;
       
        
    }
};
