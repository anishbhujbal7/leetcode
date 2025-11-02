class Solution {
public:
    int countVowelSubstrings(string word) {
        unordered_set<char> set = {'a','e','i','o','u'};
        int n = word.size();
        int count = 0;

        for (int left = 0; left < n; left++) {
            if (!set.count(word[left])) continue; // skip consonant starts

            unordered_map<char,int> map; // track vowels in current window

            for (int right = left; right < n; right++) {
                if (!set.count(word[right])) break; // stop when we hit a consonant

                map[word[right]]++; // include this vowel

                // if all 5 vowels are present, increment count
                if (map.size() == 5) count++;
            }
        }

        return count;
    }
};
