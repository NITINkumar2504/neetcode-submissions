class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> mp;

        int i = 0;
        int j = 0;
        int maxFreq = 0;
        int n = s.size();
        int ans = 0;

        while(j < n){
            // add 
            mp[s[j]]++;
            maxFreq = max(maxFreq, mp[s[j]]);

            // remove
            while((j - i + 1) - maxFreq > k){
                mp[s[i]]--;
                i++;    
            }

            // update ans
            ans = max(ans, j - i + 1);
            j++;
        }

        return ans;
    }
};
