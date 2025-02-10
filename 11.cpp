#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int result = 0;

        while (i < j) {
            int width = j - i;
            int hmin = min(height[i], height[j]);
            result = max(result, width * hmin);

            
            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }

        return result;
    }
};
