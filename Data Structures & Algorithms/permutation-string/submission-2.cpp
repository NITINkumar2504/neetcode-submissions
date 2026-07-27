class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> freqs1(26, 0);
        for(auto &ch: s1){
            freqs1[ch - 'a']++;
        }

        vector<int> freqs2(26, 0);
        int i = 0;
        for(int j = 0; j < s2.size(); j++){
            freqs2[s2[j] - 'a']++;

            if((j - i + 1) > s1.size()){
                freqs2[s2[i] - 'a']--;
                i++;
            }

            if(freqs1 == freqs2) return true;
        }

        return false;
    }
};