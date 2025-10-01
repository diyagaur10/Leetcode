class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ex_full = numBottles/numExchange;
        int remaining_empty = numBottles % numExchange;
        int count = numBottles;
        while(ex_full){
            count += ex_full;
            numBottles = ex_full + remaining_empty;
            ex_full = numBottles/numExchange;
            remaining_empty = numBottles % numExchange;
            
            
        }
        return count;
    }
};