class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat)
    {
        int diagonal_sum = 0;
        unsigned int n = mat.size();

        // calculate the primary diagonal sum
        for(int i = 0; i < n; i++)
        {
            // primary diagonal
            diagonal_sum+= mat[i][i];

            // to exclude the center element
            if(i != n-i-1)
            {
                // secondary diagonal
                diagonal_sum+= mat[i][n-i-1];
            }
        }
        return diagonal_sum;
    }
};
