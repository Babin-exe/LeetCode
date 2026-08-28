// Problem Link : https://leetcode.com/problems/lexicographically-smallest-palindromic-permutation-greater-than-target/description/?envType=daily-question&envId=2026-08-28
// TC : O(N);
// SC : O(N);
class Solution {
public:
    vector<int> count;
    string ans;
    int n;

    bool solve(string& current, string& target, int idx, int greater) {
        // Base case reached , here we only go upto half because the mirror
        // image is already made ,,,,, same as previous check is done to see if
        // what we have formed is a palindrome + lexicographically larger also
        if (idx >= (n + 1) / 2) {
            if (greater || current > target) {
                ans = current;
                return true;
            }
            return false;
        }

        for (char ch = 'a'; ch <= 'z'; ++ch) {
            // We want to make palindrome so we have to place the same char at i
            // th index and n-1-i th  index , but the thing is for odd length
            // string at the very middle index we ony want to put one char so
            // that must be handled

            // so this is for odd length + middle reached case
            int freq = count[ch - 'a'];
            if (n % 2 == 1 && idx == n / 2) {

                if (freq < 1 || (!greater && ch < target[idx]))
                    continue;

                current[idx] = ch;
                count[ch - 'a']--;

                if (solve(current, target, idx + 1,
                          (greater || ch > target[idx]))) {
                    return true;
                }

                current[idx] = '?';
                count[ch - 'a']++;

            }
            // and this is for all other (odd+even ) because we only care about
            // putting the char in ith position and n-1-i th position
            else {

                if (freq < 2 || (!greater && ch < target[idx]))
                    continue;

                // Do
                current[idx] = ch;
                current[n - idx - 1] = ch;
                count[ch - 'a'] -= 2;
                // Explore
                if (solve(current, target, idx + 1,
                          (greater || (ch > target[idx])))) {
                    return true;
                }
                // Undo and try for next(loop does it )
                current[idx] = '?';
                current[n - idx - 1] = '?';
                count[ch - 'a'] += 2;
            }
        }
        return false;
    }

    string lexPalindromicPermutation(string s, string target) {
        count.resize(26, 0);
        n = target.length();
        ans = "";
        for (char ch : s)
            count[ch - 'a']++;
        string current(n, '#');

        // If we have even length of the string we need all the present
        // characters to be even so that they contribue equally to form a
        // palidrome and for odd we only need one odd , because we have more
        // than one odd , it is simply not possible to form palidrome....

        int ct = 0;
        for (int it : count) {
            if (it % 2) {
                ct++;
            }
        }

        if (ct > 1)
            return "";

        solve(current, target, 0, false);
        return ans;
    }
};
