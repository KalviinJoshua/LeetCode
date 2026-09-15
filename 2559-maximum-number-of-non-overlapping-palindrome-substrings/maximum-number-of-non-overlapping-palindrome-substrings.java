class Solution {
    public int maxPalindromes(String s, int k) {
        int n = s.length();
        boolean[][] dp = new boolean[n][n];
        for (int length = 1; length <= n; length++) {
            for (int i = 0; i + length <= n; i++) {
                int j = i + length - 1;
                if (length == 1) {
                    dp[i][j] = true;
                }
                else if (length == 2) {
                    dp[i][j] = (s.charAt(i) == s.charAt(j));
                }
                else {
                    dp[i][j] = (s.charAt(i) == s.charAt(j))
                            && dp[i + 1][j - 1];
                }
            }
        }
        int count = 0;
        int start = 0;
        for (int end = 0; end < n; end++) {
            for (int i = start; i <= end - k + 1; i++) {
                if (dp[i][end]) {
                    count++;
                    start = end + 1;
                    break;
                }
            }
        }
        return count;
    }
}