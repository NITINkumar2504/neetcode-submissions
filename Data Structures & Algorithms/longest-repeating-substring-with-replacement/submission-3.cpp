class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int> freq(26, 0);

        int i = 0;
        int j = 0;
        int maxFreq = 0;
        int ans = 0;

        for(int j = 0; j < n; j++){
            freq[s[j] - 'A']++;

            // A stale, higher maxf can temporarily make the validity check more permissive and allow an actually invalid current window, but it does not affect correctness because it cannot make the algorithm record a length larger than one that was achievable when maxf was accurate.
            maxFreq = max(maxFreq, freq[s[j] - 'A']);

            if((j - i + 1) - maxFreq > k){    // No need of while loop, if a window is invalid shrink it by 1, and check further
                freq[s[i] - 'A']--;
                i++;  
            }

            ans = max(ans, j - i + 1);
        }
            
        return ans;
    }
};
