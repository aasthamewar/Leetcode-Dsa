class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int totalDrank = 0;
        int empty = 0;

        // Start with all full bottles
        int full = numBottles;

        while (full > 0) {
            // Drink all current full bottles
            totalDrank += full;
            empty += full;
            full = 0;

            // Exchange empty bottles for full ones
            if (empty >= numExchange) {
                full = empty / numExchange;  // new full bottles
                empty = empty % numExchange; // leftover empties
            }
        }

        return totalDrank;
    }
};