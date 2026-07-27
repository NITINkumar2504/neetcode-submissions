class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freqs1(26, 0);
        for(auto &ch: s1){
            freqs1[ch - 'a']++;
        }

        int n = s1.size();
        int m = s2.size();

        for(int i = 0; i <= m - n; i++){
            vector<int> freqs2(26, 0);
            
            for(int k = 0; k < n; k++){
                char ch = s2[k + i];
                freqs2[ch - 'a']++;
            }

            if(freqs1 == freqs2) return true;
        }

        return false;
    }
};