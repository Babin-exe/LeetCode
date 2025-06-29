class Solution {
    public int numberOfGoodPartitions(int[] nums) {

        int i = 0;
        int j = 0;
        int n = nums.length;

        int result = 1;
        int MOD = 1_000_000_007;
        Map<Integer, Integer> map = new HashMap<>();
        for (int k = 0; k < n; k++) {
            map.put(nums[k], k);
        }
        j = map.get(nums[0]);

        while (i < n) {
            if (i > j) {
                result = (result * 2) % MOD;

            }

            j = Math.max(j,map.get(nums[i]));
            i++;

        }

        return result;
    }
}
//Time complexity: o(n) because we access the array once 
//Space complexity is also o(n) because we are building a hashmap of size n
