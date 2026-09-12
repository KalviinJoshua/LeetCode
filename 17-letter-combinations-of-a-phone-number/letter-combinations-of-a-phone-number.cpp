class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
        if (digits.empty()) {
            return result;
        }
        string phone[] = {
            "", "", "abc", "def",
            "ghi", "jkl", "mno", "pqrs",
            "tuv", "wxyz"
        };
        function<void(int, string)> backtrack =
            [&](int index, string current) {
                if (index == digits.length()) {
                    result.push_back(current);
                    return;
                }
                string letters = phone[digits[index] - '0'];
                for (char letter : letters) {
                    backtrack(index + 1, current + letter);
                }
            };
        backtrack(0, "");
        return result;
    }
};