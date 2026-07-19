class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t num = 0;

        int count = 0;
        while(n){
            int bit = n & 1;
            num = num << 1 | bit;
            count++;
            n = n >> 1;
        }

        num = num << (32 - count);
        return num;
    }
};
