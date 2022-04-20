class Solution {
public:
    int numJewelsInStones(string jewels, string stones)
    {
        unordered_set <char> jewel_set;
        int jewel_count = 0;

        // alternate way to create set
        // unordered_set <char> jewel_set(begin(jewels), end(jewels));
        for(int i = 0; i < jewels.length(); i++ )
        {
            jewel_set.insert(jewels[i]);
        }

        for(int i = 0; i < stones.length(); i++)
        {
            if(jewel_set.find(stones[i]) != jewel_set.end())
            {
                jewel_count++;
            }
        }
        return jewel_count;
    }
};
