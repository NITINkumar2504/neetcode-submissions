class Solution {
public:
    bool cmp(vector<int> &freqs, vector<int> &freqt){
        for(int i = 0; i < 128; i++){
            if(freqs[i] < freqt[i]) return false;
        }

        return true;
    }

    string minWindow(string s, string t) {
        if(t.size() > s.size()) return "";

        vector<int> freqt(128, 0);
        vector<int> freqs(128, 0);

        for(auto &ch: t){
            freqt[ch]++;
        }

        int i = 0;
        int j = 0;
        int substart = -1;
        int subend = -1;
        int sublen = INT_MAX;

        while(j < s.size()){
            freqs[s[j]]++;

            while(cmp(freqs, freqt)){
                if(j - i + 1 < sublen){
                    substart = i;
                    subend = j;
                    sublen = j - i + 1;
                }

                freqs[s[i]]--;
                i++;
            }

            j++;
        }


        return sublen == INT_MAX ? "" : s.substr(substart, sublen);
    }
};
