class Solution {
public:

    double findArea(double i, vector<vector<int>>& squares){
        double area = 0.0;
        for(auto& point : squares){
            double y = point[1];
            double l = point[2];
            if(y>=i) area += l*l;
            if(y<i && y+l>i){
                double j = y+l-i;
                area += j*l;
            }
        }
        return area;
    }

    double separateSquares(vector<vector<int>>& squares) {
        double low = INT_MAX;
        double high = INT_MIN;
        double totalArea = 0;
        for(auto& point : squares){
            
            low = min(low, (double)point[1]);
            high = max(high, (double)point[1]+point[2]);
            double area =(double)point[2]*point[2];
            totalArea += area; 
        }

        while(high-low > 1e-6){
            double mid = (high+low)/2.0;
            double areaAbove = findArea(mid, squares);
            double areaBelow = totalArea - areaAbove;
            if(areaAbove>areaBelow){
                low = mid;
            }
            else{
                high = mid;
            }
        }
        return (low + high)/2.0;
    }
};
