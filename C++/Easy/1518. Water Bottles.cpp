class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {

        int max_bottles = numBottles;
        int number_of_bottles_in_exchange = 0;
        int remaining_bottles = 0;

        while(numBottles >= numExchange)
        {
            number_of_bottles_in_exchange = numBottles / numExchange;
            max_bottles += number_of_bottles_in_exchange;
            remaining_bottles = numBottles % numExchange;
            numBottles = number_of_bottles_in_exchange + remaining_bottles;
        }
        return max_bottles;
    }
};
