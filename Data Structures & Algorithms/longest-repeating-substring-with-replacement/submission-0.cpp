class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            unordered_map<char, int> count;
            int maxf = 0;
            for (int j = i; j < n; j++) {
                count[s[j]]++;
                maxf = max(maxf, count[s[j]]);
                if ((j - i + 1) - maxf <= k) {
                    ans = max(ans, j - i + 1);
                }
            }
        }
        return ans;
    }
};