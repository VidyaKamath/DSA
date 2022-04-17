class Solution {
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> result(numRows);
        vector<int> first_row = {1};

        result[0] = first_row;
        for(int row = 1; row < numRows; row++)
        {
            // first element of every row is always 1
            result[row].push_back(1);
            for (unsigned int column = 1; column < row; column++)
            {
                result[row].push_back(result[row-1][column] + result[row-1][column - 1]);
            }
            // last element of every row is always 1
            result[row].push_back(1);
        }
        return result;
    }
};
