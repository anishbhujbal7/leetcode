class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        vector<int> lastBit;
        int n = bits.size();
        int i = 0;
        while (i < n) {

            if (bits[i] == 0) {
                lastBit = {bits[i]};
                i++;
            } else {
                lastBit = {bits[i], bits[i + 1]};
                i += 2;
            }
        }
        vector<int> correct = {0};
        if (lastBit == correct)
            return true;
        return false;
    }
};
