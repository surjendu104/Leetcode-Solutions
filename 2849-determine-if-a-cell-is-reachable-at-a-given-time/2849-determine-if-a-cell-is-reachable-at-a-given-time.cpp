class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(sx == fx && sy == fy && t == 1) {
            return false;
        }
        
        int dx = fx - sx;
        int dy = fy - sy;
        
        if(dx < 0) dx = -dx;
        if(dy < 0) dy = -dy;
        
        int maxi = max(dx, dy);
        if(maxi <= t) return true;
        return false;
    }
};