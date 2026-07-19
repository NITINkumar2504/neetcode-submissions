class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t num = 0;

        for(int i = 0; i < 32; i++){
            num = num << 1;        // shift left to make space
            num = num | (n & 1);   // copy the least significant bit of n
            n = n >> 1;            // shift n right to process next bit
        }
        
        return num;
    }
};
