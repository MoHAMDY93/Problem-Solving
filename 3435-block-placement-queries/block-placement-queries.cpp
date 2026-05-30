
class SegmentTree {
    int n;
    vector<int> tree;

public:
    SegmentTree(int size) {
        n = size;
        tree.assign(4 * n, 0);
    }

    // Point update: set tree[idx] = val
    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, val);
        } else {
            update(2 * node + 1, mid + 1, end, idx, val);
        }
        tree[node] = max(tree[2 * node], tree[2 * node + 1]);
    }

    // Range maximum query for [l, r]
    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l) {
            return 0;
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = start + (end - start) / 2;
        int p1 = query(2 * node, start, mid, l, r);
        int p2 = query(2 * node + 1, mid + 1, end, l, r);
        return max(p1, p2);
    }

    void update(int idx, int val) {
        update(1, 0, n - 1, idx, val);
    }

    int query(int l, int r) {
        if (l > r) return 0;
        return query(1, 0, n - 1, l, r);
    }
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {
        int max_x = 0;
        for (const auto& q : queries) {
            max_x = max(max_x, q[1]);
        }
        
        // Target upper bound size for the segment tree coordinate system
        int M = max_x + 1;
        SegmentTree segTree(M);
        
        set<int> obstacles;
        obstacles.insert(0); // Origin is an implicit boundary/obstacle
        
        vector<bool> results;
        
        for (const auto& q : queries) {
            int type = q[0];
            if (type == 1) {
                int x = q[1];
                
                auto it = obstacles.lower_bound(x);
                int prev = *std::prev(it);
                
                // If there's an obstacle after x, update its gap representation
                if (it != obstacles.end()) {
                    int next = *it;
                    segTree.update(next, next - x);
                }
                
                // Update the gap ending at x
                segTree.update(x, x - prev);
                obstacles.insert(x);
                
            } else if (type == 2) {
                int x = q[1];
                int sz = q[2];
                
                // Find the largest obstacle <= x
                auto it = obstacles.upper_bound(x);
                int prev = *std::prev(it);
                
                // Maximum gap inside [0, prev]
                int max_gap_before = segTree.query(0, prev);
                
                // Gap between the last obstacle before x and x itself
                int last_gap = x - prev;
                
                int max_possible_sz = max(max_gap_before, last_gap);
                
                results.push_back(max_possible_sz >= sz);
            }
        }
        
        return results;
    }
};