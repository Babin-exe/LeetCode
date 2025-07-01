class Solution {
    public int possibleStringCount(String word) {

        int n = word.length();
        int count = 0;
        for (int i = 1; i < n; i++) {
            if (word.charAt(i) == word.charAt(i - 1)) {
                count++;
            }
        }
        return count + 1;
    }
}


// when two adjacent equal char is found that could or could not be the possibility, so we consider both
