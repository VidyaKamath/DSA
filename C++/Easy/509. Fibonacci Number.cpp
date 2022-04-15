class Solution1 {
public:
    int fib(int n)
    {
        // Solution using a vector to store the previous values
        vector<int> fib_series;

        fib_series.push_back(0);
        fib_series.push_back(1);

        for(int i = 2; i <= n; i++)
        {
            fib_series.push_back(fib_series[i - 1] + fib_series[i - 2]);
        }
        return fib_series[n];
    }
};


class Solution2{
public:
    int fib(int n)
    {
        // Using only variables to store the previous two values
        int fib1 = 0;
        int fib2 = 1;

        if(n == 0)
            return fib1;
        if(n == 1)
            return fib2;
        else{
            for(int i = 2; i <= n; i++)
            {
                int fib_temp = fib2;
                fib2 = fib1 + fib2;
                fib1 = fib_temp;
            }
        }
        return fib2;
    }
};
