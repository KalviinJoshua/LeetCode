class Solution {
public:
    int knightDialer(int n) {
        const int MOD = 1000000007;
        // Knight moves from each digit
        vector<vector<int>> moves = {
            {4, 6},       // 0
            {6, 8},       // 1
            {7, 9},       // 2
            {4, 8},       // 3
            {0, 3, 9},    // 4
            {},           // 5
            {0, 1, 7},    // 6
            {2, 6},       // 7
            {1, 3},       // 8
            {2, 4}        // 9
        };
        // Initially, we can start from any digit
        vector<long long> dp(10, 1);
        // Make n-1 jumps
        for (int step = 1; step < n; step++) {
            vector<long long> next(10, 0);
            for (int digit = 0; digit <= 9; digit++) {
                for (int nextDigit : moves[digit]) {
                    next[nextDigit] += dp[digit];
                    next[nextDigit] %= MOD;
                }
            }
            dp = next;
        }
        long long answer = 0;
        for (int digit = 0; digit <= 9; digit++) {
            answer += dp[digit];
            answer %= MOD;
        }
      return answer;
    }
};