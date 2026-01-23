#define lng long long int
#define pSum first
#define pIdx second
#define fori(N) for (int i = 0; i < N; i++)

class Solution {
public:

    static bool cusComp(pair<lng, int> a, pair<lng, int> b) {
        return a.pSum < b.pSum || (a.pSum == b.pSum && a.pIdx < b.pIdx);
    }

    int minimumPairRemoval(vector<int>& _nums) {
        vector<lng> nums(_nums.begin(), _nums.end());
        int n = nums.size();
        cout << n << '\n';
        unordered_map<int, lng> num_map;
        unordered_set<int> removed;
        vector<int> next_indices(n);
        vector<int> prev_indices(n);
        for (int i = 0; i < n; i++) {
            num_map[i] = nums[i];
        }
        bool non_decreasing;
        int count = 0;

        set<pair<lng, int>, decltype(cusComp)*> pair_sums(cusComp);

        fori(n) {
            next_indices[i] = i + 1;
            prev_indices[i] = i - 1;
        }

        fori(n-1) {
            pair_sums.insert({num_map[i] + num_map[i + 1], (int)i});
        }
        int swaps = 0;
        fori(n-1) {
            if (num_map[i + 1] < num_map[i]) swaps++;
        }
        non_decreasing = (!swaps);
        while (!non_decreasing) {
            // cout << swaps << " " << count << endl;
            non_decreasing = false;
            pair<lng, int> first_pair = *pair_sums.begin();
            pair_sums.erase(first_pair);
            lng p_sum = first_pair.pSum;
            int curr = first_pair.pIdx;
            int next = next_indices[curr];
            int prev = prev_indices[curr];
            // cout << "indices: " << curr << " " << next << endl;
            if (next < n && num_map[next] < num_map[curr]) swaps--;

            if (prev >= 0) {
                lng old_sum = num_map[prev] + num_map[curr];
                lng new_sum = num_map[prev] + p_sum;
                pair_sums.erase({old_sum, prev});
                pair_sums.insert({new_sum, prev});
                if (num_map[prev] > num_map[curr]) swaps--;
                if (num_map[prev] > p_sum) swaps++;
            }

            const int next_next = (next < n) ? next_indices[next] : n;
            if (next_next < n) {
                const long old_sum = num_map[next] + num_map[next_next];
                const long new_sum = p_sum + num_map[next_next];
                pair_sums.erase({old_sum, next});
                pair_sums.insert({new_sum, curr});
                if (num_map[next_next] < num_map[next]) swaps--;
                if (num_map[next_next] < p_sum) swaps++;
                prev_indices[next_next] = curr;
            }

            if (swaps == 0) non_decreasing = true;
            next_indices[curr] = next_next;
            num_map[curr] = p_sum;
            count++;
        };
        return count;
    }
};