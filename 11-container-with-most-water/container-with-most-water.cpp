class Solution {
public:
    int maxArea(vector<int>& height) {
        int max = 0;
        int L = 0;
        int R = height.size()-1;
        while (L < R) {
            if (min(height[L], height[R])*(R-L) > max) {
                max = min(height[L], height[R])*(R-L);
            } 
            if (height[L] < height[R]) {
                L++;
            } else {
                R--;
            }
        }
        return max;
    }
};