class Solution {
public:
    string reverseVowels(string s) {
        unordered_set<char> set = {'a','e','i','o','u','A','E','I','O','U'};
        int left = 0;
        int right = s.size()-1;
        while(right>left){
            if(!set.count(s[left])){
                left++;
            }
            else if(!set.count(s[right])){
                right--;
            }
            else{
                swap(s[right],s[left]);
                left++;
                right--;
            }
        }
        return s;
    }
};
