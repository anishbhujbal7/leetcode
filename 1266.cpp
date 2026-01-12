class Solution {
public:

    int findDist(int x, int y, int p, int q){
        int dx = abs(x-p);
        int dy = abs(y-q);
        int diagonal = min(dx, dy);
        int minDist = diagonal;

        if(x<p) x += diagonal;
        else x -= diagonal;

        if(y<q) y += diagonal;
        else y -= diagonal;

        if(x == p && y == q) return minDist;
        if(x != p) minDist += abs(x-p);
        if(y != q) minDist += abs(y-q);
        return minDist;
    }

    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int x = points[0][0];
        int y = points[0][1];
        int n = points.size();
        
        int dist = 0;
        for(int i = 1; i<points.size(); i++){
            
            int p = points[i][0];
            int q = points[i][1];
            dist += findDist(x, y, p, q);
            x = p;
            y = q;
        }
        return dist;
    }
};
