class Solution {
public:
    // a function that checks if m balls can be placed 'd' distance apart from each other in the  position vector 
    bool canPlace(int d, vector<int>& position, int m){
        int lastPosition  = position[0];
        // place the first ball at 0th index
        int count =1;   
        // as the first ball is placed
        for(int i = 1; i<position.size(); i++){
            int currPosition  = position[i];
            if((currPosition - lastPosition >= d)){
                count++;
                lastPosition = currPosition;
            }
            // if the distance between two positions is greater than or equal to d then place the ball at that position
            if(count == m) return true;
        }
        return false;
    }

    int maxDistance(vector<int>& position, int m) {
        sort(position.begin(), position.end());
        int low = 1;
        int high = position.back() - position.front();
        int ans = 0;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(canPlace(mid, position, m)){
                // if we can  place the balls mid distance apart from each other then increase the distance 
                ans = mid;
                low = mid+1;
            }else{
                // if cannot place the balls mid distance apart from each other then decrease the distance
                high = mid -1;
            }
        }

        return ans;
    }
};
