class Solution {
private:
int n;
struct RollingHash {
    using ll = long long;

    static constexpr ll MOD = 1'000'000'007LL;
    static constexpr ll BASE = 911382323LL;

    int n;
    vector<ll> pref, power;

    RollingHash(const vector<int>& a) {
        n = a.size();

        pref.assign(n + 1, 0);
        power.assign(n + 1, 1);

        for (int i = 0; i < n; i++) {
            ll x = (1LL * a[i] % MOD + MOD) % MOD;

            pref[i + 1] = (pref[i] * BASE + x) % MOD;
            power[i + 1] = power[i] * BASE % MOD;
        }
    }

    // Hash of [l, r] inclusive
    ll get(int l, int r) const {
        ll res = (pref[r + 1] -
                  pref[l] * power[r - l + 1] % MOD + MOD) % MOD;

        return res;
    }

    // Hash of an empty subarray
    ll getEmpty() const {
        return 0;
    }
};
bool check(int sz, const RollingHash& rh) {
    unordered_map<int, int> freq;
    for (int r = sz-1, l = 0 ; r < n ; r++, l++) {
        freq[rh.get(l, r)]++;
    }
    for (auto& [hash, f] : freq) {
        if (f == 1) return true;
    }
    return false;
}
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        RollingHash rh(nums);
        n = nums.size();
        int lo = 1 , hi = nums.size();
        int ans = nums.size();
        while (lo <= hi) {
            int mid = (lo + hi) / 2;
            if (check(mid, rh)) ans = mid, hi = mid-1;
            else lo = mid + 1;
        }
        return ans;
    }
};