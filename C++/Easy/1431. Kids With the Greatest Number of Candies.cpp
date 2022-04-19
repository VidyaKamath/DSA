class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies)
    {
        vector<bool> result;
        int max_candies = *max_element(candies.begin(), candies.end());

        for(unsigned int i = 0; i < candies.size(); i++)
        {
              if(candies[i] + extraCandies >= max_candies)
              {
                  result.push_back(true);
              }
              else
                  result.push_back(false);
        }
        return result;
    }
};
