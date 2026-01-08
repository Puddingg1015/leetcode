class Solution {
public:
    // the max dotproduct of subsequences of nums1 ending at i and nums2 ending at j (inclusive)
    int dotproduct[500][500] = {{0}};
    // The dotproduct of A from i to j and B from k to l is A[i:]*B[k:]-A[j+1:]*B[l+1:]
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        dotproduct[0][0] =nums1[0] * nums2[0];
        for (int i = 1; i < nums1.size(); i++) dotproduct[i][0] = max(nums1[i] * nums2[0], dotproduct[i-1][0]);
        for (int j = 1; j < nums2.size(); j++) dotproduct[0][j] = max(nums1[0] * nums2[j], dotproduct[0][j-1]);
        // cout << "\t"; for (int j = 1; j < nums2.size(); j++) cout << nums2[j] << "\t"; cout << endl;
        for (int i = 1; i < nums1.size(); i++) {
            // cout << nums1[i] << "\t";
            for (int j = 1; j < nums2.size(); j++) {
                // hopefully this works
                dotproduct[i][j] = max(max(dotproduct[i-1][j], nums1[i] * nums2[j]), max(dotproduct[i-1][j-1] + nums1[i] * nums2[j], dotproduct[i][j-1])); 
                // cout << dotproduct[i][j] << "\t";
            } 
            // cout << endl << endl;
        }
        return dotproduct[nums1.size()-1][nums2.size()-1];
    }

    int dotProduct(vector<int> nums1, vector<int> nums2) {
        assert(nums1.size() == nums2.size());
        int out = 0;
        for (int i = 0; i < nums1.size(); i++) out += nums1[i] * nums2[i];
        return out;
    }

};// 72+80+3+45