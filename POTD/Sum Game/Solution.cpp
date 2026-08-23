// Problem Link : https://leetcode.com/problems/sum-game/description/?envType=daily-question&envId=2026-08-23
class Solution {
public:
    bool sumGame(string num) {
        int left_sum = 0, right_sum = 0;
        int left_que = 0, right_que = 0;

        int n = num.length();
        int i = 0;

        while (i < n / 2) {
            if (num[i] == '?')
                left_que++;
            else
                left_sum += num[i] - '0';
            i++;
        }
        while (i < n) {
            if (num[i] == '?')
                right_que++;
            else
                right_sum += num[i] - '0';
            i++;
        }

        if ((left_que + right_que) % 2)
            return true;

        int sum_diff = left_sum - right_sum;
        int que_diff = left_que - right_que;

        return (sum_diff + ((que_diff * 9) / 2) == 0) ? false : true;
    }
};
