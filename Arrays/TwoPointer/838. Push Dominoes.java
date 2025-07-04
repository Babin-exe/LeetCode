//problem link : https://leetcode.com/problems/push-dominoes/description/

class Solution {
    public String pushDominoes(String dominoes) {

        int n = dominoes.length();
        int[] leftCloseR = new int[n];
        int[] rightCloseL = new int[n];
        StringBuilder hehe = new StringBuilder();

        //lets form the closest right array 

        for (int i = 0; i < n; i++) {
            if (dominoes.charAt(i) == 'R') {
                leftCloseR[i] = i;
            } else if (dominoes.charAt(i) == '.') {
                leftCloseR[i] = (i > 0) ? leftCloseR[i - 1] : -1;
            } else {
                leftCloseR[i] = -1;
            }

        }
        //lets form the closest left array now 

        for (int i = n - 1; i >= 0; i--) {
            if (dominoes.charAt(i) == 'L') {
                rightCloseL[i] = i;
            } else if (dominoes.charAt(i) == '.') {
                rightCloseL[i] = (i < n - 1) ? rightCloseL[i + 1] : -1;
            } else {
                rightCloseL[i] = -1;
            }

        }

        //now we want to form the answer finally

        for (int i = 0; i < n; i++) {

            int distRightL = Math.abs(i - rightCloseL[i]);
            int distLeftR = Math.abs(i - leftCloseR[i]);

            if (leftCloseR[i] == rightCloseL[i]) {
                hehe.append(".");
            } else if (leftCloseR[i] == -1) {
                hehe.append("L");
            } else if (rightCloseL[i] == -1) {
                hehe.append("R");
            } else if (distRightL > distLeftR) {
                hehe.append("R");

            } else if (distRightL < distLeftR) {
                hehe.append("L");
            } else {
                hehe.append(".");
            }

        }
        return hehe.toString();
    }
}
