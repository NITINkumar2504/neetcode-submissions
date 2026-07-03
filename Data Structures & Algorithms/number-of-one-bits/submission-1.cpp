class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;
        while(n){
            int digit = n & 1;
            if(digit) ans++;
            n = n >> 1;
        }
        return ans;
    }
};
