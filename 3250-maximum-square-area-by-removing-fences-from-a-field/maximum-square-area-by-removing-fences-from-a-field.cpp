// Dang the time limit here is tight

#define MMOD ((int)1e9+7)
#define MSIZE ((int)1e9+2)
#define lng long long int

class Solution {
public:

    // bool hFencesExists[MSIZE] = {0};
    // bool vFencesExists[MSIZE] = {0};

    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.insert(hFences.begin(), 1);
        hFences.push_back(m);
        vFences.insert(vFences.begin(), 1);
        vFences.push_back(n);
        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());
        unordered_set<lng> hDiffs = diffs(hFences);
        unordered_set<lng> vDiffs = diffs(vFences);
        // printVec(hFences);
        // printVec(vFences);
        // printVec(hDiffs);
        // printVec(vDiffs);
        vector<lng> _hDiffs(hDiffs.begin(), hDiffs.end());
        vector<lng> _vDiffs(vDiffs.begin(), vDiffs.end());;
        lng max_side = -1;
        for (lng i : _hDiffs) {
            if (i <= max_side) continue;
            if (diffSizeExists(i, vDiffs)) {
                max_side = max(max_side, i);
                // break;
            }
        }
        for (lng i : _vDiffs) {
            if (i <= max_side) continue;
            if (diffSizeExists(i, hDiffs)) {
                max_side = max(max_side, i);
                // break;
            }
        }
        if (max_side == -1) return max_side;
        return getModArea(max_side);
        // lng max_side = -1;
        // for (lng hDiff : hDiffs) {
        //     for (lng vDiff : vDiffs) {
        //         if (hDiff == vDiff) {
        //             max_side = max(max_side, hDiff);
        //             // cout << hDiff << endl;
        //         }
        //         if (hDiff < max_side && vDiff < max_side) {
        //             return getModArea(max_side);
        //         }
        //     }
        // }
        // if (max_side == -1) return max_side;
        // return getModArea(max_side);
    }

    int getModArea(long side) {
        side %= MMOD;
        return (side * side) % MMOD;
    }

    unordered_set<lng> diffs(vector<int>& arr) {
        unordered_set<lng> out;
        for (int i = 0; i < arr.size() - 1; i++) {
            for (int j = i+1; j < arr.size(); j++) {
                out.insert((lng)arr[j] - arr[i]);
            }
        }
        return out;
    }

    bool diffSizeExists(int diff, unordered_set<lng>& diffs) {
        return diffs.find(diff) != diffs.end();
        // return binary_search(diffs.begin(), diffs.end(), diff, [](int a, int b) { return a > b; });
    }

    bool diffSizeExists(int diff, vector<int>& arr, char side) {
        if (side == 'h') {
            for (int i = 0; i < arr.size() - 1; i++) {
                if (binary_search(arr.begin() + i, arr.end(), arr[i] + diff)) return true;
                // if (hFencesExists[arr[i] + diff]) return true;
            }
        } else if (side == 'v') {
            for (int i = 0; i < arr.size() - 1; i++) {
                if (binary_search(arr.begin() + i, arr.end(), arr[i] + diff)) return true;
                // if (vFencesExists[arr[i] + diff]) return true;
            }
        }
        return false;
    }

    void printVec(auto arr) {
        for (int i : arr) cout << i << " ";
        cout << endl;
    }
};