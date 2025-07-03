//Prolem link : https://leetcode.com/problems/partition-labels/

class Solution {
    public List<Integer> partitionLabels(String s) {
        int n = s.length();
        int[] store = new int[26];
        List<Integer> hehe = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            store[s.charAt(i) - 'a'] = i;
        }
        int start = 0, end = 0;
        for (int i = 0; i < n; i++) {
            end = Math.max(end, store[s.charAt(i) - 'a']);
            if (i == end) {
                hehe.add(end - start + 1);
                start = i + 1;
            }

        }
        return hehe;
    }
}
