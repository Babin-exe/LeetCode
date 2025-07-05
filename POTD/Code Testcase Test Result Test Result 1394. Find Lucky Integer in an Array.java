// Problem link : https://leetcode.com/problems/find-lucky-integer-in-an-array/?envType=daily-question&envId=2025-07-05

class Solution {
    public int findLucky(int[] arr) {
        int n = arr.length;
        int[] auh = new int[501];
        for (int i = 0; i < n; i++) {
            auh[arr[i]]++;
        }
        for (int i = 500; i > 0; i--) {
            if (auh[i] == i) {
                return i;
            }

        }
        return -1;
    }
}
