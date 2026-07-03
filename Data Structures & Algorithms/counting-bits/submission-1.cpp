class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;

        for(int i = 0; i <= n; i++){
            int ones = 0;
            int num = i;
            while(num){
                int bit = num & 1;
                if(bit) ones++;
                num = num >> 1;
            }
            ans.push_back(ones);
        }

        return ans;
    }
};
