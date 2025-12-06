class Solution {
public:

    pair<int,int> fillJug(int a, int b, int c){
        // int fill = b-a;
        return{b, c};
    }

    pair<int,int> pourWater(int a, int b, int c){
        if(c-a == b) return{b,0};
        else if(c-a> b) return  {a+b,0};
        else{
            return{a+(c-a),b-(c-a)};
        }
    }

    long long encode(int c, int a, int b) {
    return ((long long)c << 40) | ((long long)a << 20) | b;
    }


    bool canMeasureWater(int x, int y, int target) {
      int curr = 0;
      queue<pair<int,pair<int,int>>> q;
      unordered_set<long long> visited;

      q.push({0,{0,0}});
      long long key = encode(0,0,0);
      visited.insert(key);
      while(!q.empty()){
        int capacity = q.front().first;
        int firstJug = q.front().second.first;
        int secondJug = q.front().second.second;
        q.pop();
        capacity = firstJug + secondJug;
        if(capacity == target || firstJug == target || secondJug == target) return true;
        // fill either jug
        auto[fx1,fy1] = fillJug(firstJug,x,secondJug);
        int c1 = fx1+fy1;
        key = encode(c1,fx1,fy1);
        if(!visited.count(key)){
            visited.insert(key);
            q.push({c1,{fx1,fy1}});
        }
        auto [fy2,fx2] = fillJug(secondJug,y,firstJug);
        int c2 = fy2+fx2;
         key = encode(c2,fx2,fy2);
        if(!visited.count(key)){
            visited.insert(key);
            q.push({c2,{fx2,fy2}});
        }
        // completely empty
        int cx1 = 0, cy1 = secondJug;
        int c3 = cx1+cy1;
        key = encode(c3,cx1,cy1);
        if(!visited.count(key)){
            visited.insert(key);
            q.push({c3,{cx1,cy1}});
        }
        int cx2 = firstJug, cy2 = 0;
        int c4 = cx2+cy2;
        key = encode(c4,cx2,cy2);
        if(!visited.count(key)){
            visited.insert(key);
            q.push({c4,{cx2,cy2}});
        }
        // pour water foem one jug into another
        auto [px1,py1] = pourWater(firstJug,secondJug,x);
        int c5 = px1+py1;
        key = encode(c5,px1,py1);
        if(!visited.count(key)){
            visited.insert(key);
            q.push({c5,{px1,py1}});
        }
        auto [py2,px2] = pourWater(secondJug, firstJug, y);
        int c6 = px2+py2;
        key = encode(c6,px2,py2);
        if(!visited.count(key)){
            visited.insert(key);
            q.push({c6,{px2,py2}});
        }
      }
      return false;  
    }
};
