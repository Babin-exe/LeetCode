class Solution {
    public int numSubseq(int[] nums, int target) {
        int MOD = 1_000_000_007;
        int count = 0;
        int n = nums.length;
        int l = 0, r = n - 1;
        Arrays.sort(nums);
        int[] powers = new int[n];
        powers[0] = 1;
        for (int i = 1; i < n; i++) {
            powers[i] = (powers[i - 1] * 2) % MOD;
        }
        while (l <= r) {
            if (nums[l] + nums[r] <= target) {
                count = (count + powers[r - l]) % MOD;
                l++;
            } else {
                r--;
            }
        }
        return count % MOD;
    }
}




// Sort the array to efficiently manage minimum and maximum values.

// Use two pointers (l, r) to represent the minimum and maximum elements.

// If nums[l] + nums[r] <= target, all subsequences between l and r are valid (total: 2^(r-l)), so we add that to the count.

// Precompute powers of 2 modulo 10⁹ + 7 to avoid recomputation and overflow.

// Move l or r accordingly to explore other valid subsequences.

// Time Complexity: O(n log n) (due to sorting)

// Space Complexity: O(n) (for storing powers of 2)

