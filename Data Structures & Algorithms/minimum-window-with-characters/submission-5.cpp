class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        if(n < m) return "";

        unordered_map<char, int> mp;

        for(auto &ch: t){
            mp[ch]++;
        }

        int requiredCount = m;
        int i = 0;
        int j = 0;
        int substart = 0;
        int minWinLen = INT_MAX;

        while(j < n){
            char ch = s[j];

            if(mp[ch] > 0) requiredCount--;

            mp[ch]--;

            while(requiredCount == 0){
                int currWin = j - i + 1;

                if(currWin < minWinLen){
                    minWinLen = currWin;
                    substart = i;
                }

                mp[s[i]]++;

                if(mp[s[i]] > 0) requiredCount++;

                i++;
            }

            j++;
        }

        return minWinLen == INT_MAX ? "" : s.substr(substart, minWinLen);
    }
};
