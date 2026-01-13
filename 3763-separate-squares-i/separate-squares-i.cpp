#define lng int
#define ldbl long double
#define HEIGHT_THRESH 1e-6
#define AREA_THRESH_PERC 1e-14
#define AREA_THRESH_ABS 1e-5

// STOP TLE'ING PLEASE

class Solution {
public:
    vector<vector<lng>> squares;
    double separateSquares(vector<vector<int>>& _squares) {
        ios_base::sync_with_stdio(0);
        // for (vector<int> _square : _squares) {
        //     // squares.push_back(vector<lng>{(lng)_square[0], (lng)_square[1], (lng)_square[2]});
        //     // squares.push_back(_square);
        // }
        squares = _squares;
        ldbl maxy = 0;
        ldbl miny = INT_MAX;
        for (vector<lng>& square : squares) {
            if (square[1] + square[2] > maxy) maxy = (ldbl)square[1] + square[2];
            if (square[1] < miny) miny = (ldbl)square[1];
        }
        return solve(miny, maxy);
    }

    double solve(ldbl miny, ldbl maxy) {
        ldbl midy = (miny+maxy)*0.5;
        pair<ldbl, ldbl> areas = totalArea(midy);
        // cout << setprecision(20) << midy << " " << areas.first << " " << areas.second << " " << areasAreEqual(areas) << " " << (abs(midy-miny) <= HEIGHT_THRESH) << endl;
        if (areasAreEqual(areas) || abs(midy-miny) <= HEIGHT_THRESH) {
            if (abs(midy-miny) <= HEIGHT_THRESH || !areasAreEqual(totalArea(midy - HEIGHT_THRESH))) {
                // cout << "end" << endl;
                return midy;
            }
            return solve(miny, midy);
        }
        else if (areas.first < areas.second) miny = midy + HEIGHT_THRESH;
        else maxy = midy - HEIGHT_THRESH;
        return solve(miny, maxy);
    }

    bool areasAreEqual(ldbl area1, ldbl area2) {return (abs(area1 - area2) <= AREA_THRESH_ABS);}

    bool areasAreEqual(pair<ldbl, ldbl> areas) {return areasAreEqual(areas.first, areas.second);}

    pair<ldbl, ldbl> totalArea(ldbl y) {
        ldbl above = 0;
        ldbl below = 0;
        for (vector<lng>& square : squares) {
            ldbl _upper = square[1] + square[2];
            if (_upper > y) {
                above += (_upper - max((ldbl)square[1], y)) * square[2]; 
            }
            if (square[1] < y) {
                below += (min(y, _upper) - square[1]) * square[2];
            }
        }
        return make_pair(below, above);
    }
};