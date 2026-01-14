
class SegmentTree {
public:
    int N;
    vector<int> xcoords;
    vector<int> covered_count;
    vector<int> covered_width;
    SegmentTree(const vector<int>& xs) {
        xcoords = xs;
        N = xcoords.size() - 1;
        covered_count = vector<int>(4*N);
        covered_width = vector<int>(4*N);
    }

    // Adds val to the range [i, j].
    void add(int i, int j, int val) {
        add(0, 0, N - 1, i, j, val); 
    }

    void add(int index, int low, int high, int i, int j, int val) {
        if (j <= xcoords[low] || xcoords[high + 1] <= i)
            return;
        if (i <= xcoords[low] && xcoords[high + 1] <= j) {
            covered_count[index] += val;
        } else {
            const int mid = (low + high) / 2;
            add(2 * index + 1, low, mid, i, j, val);
            add(2 * index + 2, mid + 1, high, i, j, val);
        }
        if (covered_count[index] > 0) {
            covered_width[index] = xcoords[high + 1] - xcoords[low];
        } else if (low == high) {
            covered_width[index] = 0;
        } else {
            covered_width[index] = covered_width[2 * index + 1] +
                                      covered_width[2 * index + 2];
        }
    }
};

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        vector<tuple<int, int, int, int>> boundaries;
        set<int> xcoords;
        for (const vector<int>& square : squares) {
            const int x = square[0];
            const int y = square[1];
            const int l = square[2];
            boundaries.emplace_back(y, 1, x, x + l);
            boundaries.emplace_back(y + l, -1, x, x + l);
            xcoords.insert(x);
            xcoords.insert(x + l);
        }
        
        long area = 0;
        int lasty = 0;
        SegmentTree tree({xcoords.begin(), xcoords.end()});
        ranges::sort(boundaries);
        double total_A = getArea(boundaries, xcoords);
        for (auto& [y, d, xl, xr] : boundaries) {
            int cur_covered = tree.covered_width[0];
            long dA = cur_covered * (long)(y - lasty);
            if (area + dA >= total_A / 2.0)
                return lasty + (total_A / 2.0 - area) / cur_covered;
            area += dA;
            tree.add(xl, xr, d);
            lasty = y;
        }
        return -1;
    }

    long getArea(const vector<tuple<int, int, int, int>>& boundaries,
                 const set<int>& xcoords) {
        long out = 0;
        int lasty = 0;
        SegmentTree tree({xcoords.begin(), xcoords.end()});
        for (const auto& [y, delta, xl, xr] : boundaries) {
            out += tree.covered_width[0] * static_cast<long>(y - lasty);
            tree.add(xl, xr, delta);
            lasty = y;
        }
        return out;
    }
};