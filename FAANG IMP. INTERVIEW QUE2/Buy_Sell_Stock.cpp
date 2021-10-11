PROBLEM STATEMENT: BUY AND SELL STOCK
In the stock market, a person buys a stock and sells it on some future date. 
Given the stock prices of N days in an array A[ ] and a positive integer K, 
find out the maximum profit a person can make in at-most K transactions. 
A transaction is equivalent to (buying + selling) of a stock and new 
transaction can start only when the previous transaction has been completed.

LANGUAGE USED:C++
CODE SOLUTION:
class Solution {
  public:
    int maxProfit(int K, int N, int A[]) {
        // table to store results of subproblems
    // profit[t][i] stores maximum profit using atmost
    // t transactions up to day i (including day i)
    int n=N;
    int k=K;
    int profit[k + 1][n + 1];

    // For day 0, you can't earn money
    // irrespective of how many times you trade
    for (int i = 0; i <= k; i++)
        profit[i][0] = 0;

    // profit is 0 if we don't do any transation
    // (i.e. k =0)
    for (int j = 0; j <= n; j++)
        profit[0][j] = 0;

    // fill the table in bottom-up fashion
    for (int i = 1; i <= k; i++) {
        int prevDiff = INT_MIN;
        for (int j = 1; j < n; j++) {
            prevDiff = max(prevDiff,
                           profit[i - 1][j - 1] - A[j - 1]);
            profit[i][j] = max(profit[i][j - 1],
                               A[j] + prevDiff);
        }
    }

    return profit[k][n - 1];
    }
};