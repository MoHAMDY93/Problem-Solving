#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
    static const int MOD = 1e9 + 7;
    
    struct Node {
        long long sum_x = 0;
        long long sum_sq = 0;
        long long lazy = 0;
    };

    vector<Node> tree;

    void apply(int node, int start, int end, long long val) {
        long long len = end - start + 1;
        val %= MOD;
        
        // sum_sq_new = sum_sq + 2 * val * sum_x + val^2 * len
        long long add_sq = (2 * val % MOD * tree[node].sum_x % MOD + val * val % MOD * len % MOD) % MOD;
        tree[node].sum_sq = (tree[node].sum_sq + add_sq) % MOD;
        
        // sum_x_new = sum_x + val * len
        tree[node].sum_x = (tree[node].sum_x + val * len) % MOD;
        
        tree[node].lazy = (tree[node].lazy + val) % MOD;
    }

    void push(int node, int start, int end) {
        if (tree[node].lazy == 0) return;
        long long lz = tree[node].lazy;
        tree[node].lazy = 0;

        int mid = start + (end - start) / 2;
        apply(2 * node, start, mid, lz);
        apply(2 * node + 1, mid + 1, end, lz);
    }

    void update(int node, int start, int end, int l, int r, long long val) {
        if (r < start || end < l) return;
        if (l <= start && end <= r) {
            apply(node, start, end, val);
            return;
        }
        push(node, start, end);
        int mid = start + (end - start) / 2;
        update(2 * node, start, mid, l, r, val);
        update(2 * node + 1, mid + 1, end, l, r, val);
        
        tree[node].sum_x = (tree[2 * node].sum_x + tree[2 * node + 1].sum_x) % MOD;
        tree[node].sum_sq = (tree[2 * node].sum_sq + tree[2 * node + 1].sum_sq) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        tree.assign(4 * n, Node());
        unordered_map<int, int> last_pos;
        long long total_ans = 0;

        for (int j = 0; j < n; ++j) {
            int prev = last_pos.count(nums[j]) ? last_pos[nums[j]] : -1;
            int l = prev + 1;
            int r = j;

            update(1, 0, n - 1, l, r, 1);
            total_ans = (total_ans + tree[1].sum_sq) % MOD;

            last_pos[nums[j]] = j;
        }

        return total_ans;
    }
};