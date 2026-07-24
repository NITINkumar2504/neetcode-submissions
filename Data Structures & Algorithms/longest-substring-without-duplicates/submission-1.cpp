class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0;
        int j = 0;
        int n = s.size();
        unordered_map<int, int> freq;
        int maxLen = 0;

        while(j < n){
            char ch = s[j];

            // add char in map
            freq[ch]++;

            // remove, while freq of ch > 1
            while(freq[ch] > 1){
                freq[s[i]]--;
                i++;
            }

            // update len
            maxLen = max(maxLen, j - i + 1);
            j++;
        }

        return maxLen;
    }
};
