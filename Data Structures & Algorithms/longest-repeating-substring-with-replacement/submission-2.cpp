class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int> freq(26, 0);

        int i = 0;
        int j = 0;
        int maxFreq = 0;
        int ans = 0;

        while(j < n){
            // expand 
            freq[s[j] - 'A']++;
            maxFreq = max(maxFreq, freq[s[j] - 'A']);
            int currWin = j - i + 1;

            // shrink (invalid window)
            while(currWin - maxFreq > k){
                freq[s[i] - 'A']--;
                i++;  
                currWin--;  
            }

            // update ans
            ans = max(ans, j - i + 1);
            j++;
        }

        return ans;
    }
};
