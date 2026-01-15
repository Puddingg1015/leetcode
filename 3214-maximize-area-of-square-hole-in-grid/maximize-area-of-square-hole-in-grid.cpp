// sub 30 min yahhhhh

class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int maxh = maxConsecutiveSequenceLen(hBars);
        int maxv = maxConsecutiveSequenceLen(vBars);
        int side = min(maxh + 1, maxv + 1);
        return side * side;
    }

    int maxConsecutiveSequenceLen(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int out = 1;
        int starti = 0;
        for (int i = 1; i <= arr.size(); i++) {
            if (i == arr.size()) out = max(out, i - starti);
            else if (arr[i] == arr[i-1] + 1) out = max(out, i - starti + 1);
            else starti = i;
        }
        return out;
    }
};