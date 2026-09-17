class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        const int INF = 1000000;
        vector<int> best(n, INF);
        int left = 0;
        int sum = 0;
        int minLength = INF;
        int answer = INF;
        for (int right = 0; right < n; right++) {
            sum += arr[right];
            while (sum > target) {
                sum -= arr[left];
                left++;
            }
            if (sum == target) {
                int length = right - left + 1;
                if (left > 0 && best[left - 1] != INF) {
                    answer = min(answer, length + best[left - 1]);
                }
                minLength = min(minLength, length);
            }
            best[right] = minLength;
        }
        if (answer == INF)
            return -1;
        return answer;
    }
};