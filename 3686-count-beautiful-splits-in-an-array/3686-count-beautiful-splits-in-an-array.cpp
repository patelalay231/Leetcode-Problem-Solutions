#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int beautifulSplits(vector<int>& nums) {
        const int MOD = 1e9 + 7; // Large prime modulus
        const int BASE = 31;    // Base for hashing

        int n = nums.size();
        vector<long long> hash(n + 1, 0); // Hash values
        vector<long long> power(n + 1, 1); // Powers of BASE

        // Precompute hash values and powers of BASE
        for (int i = 0; i < n; i++) {
            hash[i + 1] = (hash[i] * BASE + nums[i]) % MOD;
            power[i + 1] = (power[i] * BASE) % MOD;
        }

        auto getHash = [&](int l, int r) -> long long {
            return (hash[r + 1] - hash[l] * power[r - l + 1] % MOD + MOD) % MOD;
        };

        int result = 0;

        // Iterate through all possible positions for splitting
        for (int i = 1; i < n - 1; i++) {  // Split between nums1 and nums2
            for (int j = i + 1; j < n; j++) {  // Split between nums2 and nums3
                // Check if nums1 is a prefix of nums2
                if (isPrefix(getHash, 0, i - 1, i, j - 1)) {
                    result++;
                }
                // Check if nums2 is a prefix of nums3
                else if (isPrefix(getHash, i, j - 1, j, n - 1)) {
                    result++;
                }
            }
        }

        return result;
    }

private:
    // Helper function to check if one range is a prefix of another using hash values
    bool isPrefix(function<long long(int, int)> getHash, int l1, int r1, int l2, int r2) {
        int len1 = r1 - l1 + 1;
        int len2 = r2 - l2 + 1;

        if (len1 > len2) return false;

        // Compare hash values of the overlapping range
        return getHash(l1, r1) == getHash(l2, l2 + len1 - 1);
    }
};
