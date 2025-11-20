class Solution {
public:

    bool kokoHappy(int rate,vector<int>& piles, int h ){
        int hours = 0;
        for(int i = 0; i<piles.size();i++){
            if(piles[i]%rate == 0) hours += piles[i]/rate;
            else{
                hours+=(piles[i]/rate)+1;
            }
            if(hours>h) break;
        }
        if(hours>h) return false;
        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        sort(piles.begin(), piles.end());
        int n = piles.size();
        if(n == h ) return piles[n-1];
        if(n>h) return 0;
        long right = piles[n-1];
        long left = 1;
        long lastHappy = 0;

        while(left<=right){
            int mid = left + (right - left) / 2;
            if(kokoHappy(mid, piles, h)){
                lastHappy = mid;
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        return lastHappy;
    }
};
