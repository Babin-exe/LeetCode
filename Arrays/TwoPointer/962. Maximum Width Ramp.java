// problem link: https://leetcode.com/problems/maximum-width-ramp/description/


  class Solution {
    public int maxWidthRamp(int[] nums) {

        int hehe = 0;

        int n = nums.length;

        int[] auh = new int[n];

        int take = Integer.MIN_VALUE;

        for (int i = n - 1; i >= 0; i--) {
            take = Math.max(take, nums[i]);
            auh[i] = take;
        }
        take = 0;
        int i = 0;
        int j = 0;
        while (j < n) {
            while (i < n && nums[i] > auh[j]) {
                i++;
            }
            take = Math.max(take, j - i);
            j++;
        }
        return take;
    }
}
