class Solution {
public:
    int reverseBits(int n) {
        int result=0;
        for (int i = 0; i < 32; i++) {
        // Step 1: Shift result left to make room for next bit
        result <<= 1;

        // Step 2: Add the last bit of n
        result |= (n & 1);

        // Step 3: Shift n right to process the next bit
        n >>= 1;
    }

    return result;
    }
};