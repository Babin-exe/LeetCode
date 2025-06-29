class Solution {
    public int numberOfGoodPartitions(int[] nums) {

        int i = 0;
        int j = 0;
        int n = nums.length;
        int count = 0;
        

        Map<Integer, Integer> map = new HashMap<>();
        for (int k = 0; k < n; k++) {
            map.put(nums[k], k);
        }

        while (i < n) {
            j = map.get(nums[i]);
            while (i < j) {
                j = Math.max(j, map.get(nums[i]));
                i++;
            }
            i++;
            count++;
        }
         final int MOD = 1_000_000_007;
        long res = 1;
        for (int x = 0; x < count - 1; x++) {
            res = (res * 2) % MOD;
        }

        return (int) res;
    }
}
