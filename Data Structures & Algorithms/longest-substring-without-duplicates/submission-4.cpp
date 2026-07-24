class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int j = 0;
        int n = s.size();
        
        vector<int> freq(128, 0);
        int maxLen = 0;

        while(j < n){
            char ch = s[j];

            freq[ch]++;

            while(freq[ch] > 1){
                freq[s[i]]--;
                i++;
            }

            maxLen = max(maxLen, j - i + 1);
            j++;
        }

        return maxLen;
    }
};
