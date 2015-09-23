/*
Time: O(n)
Space: O(n)
Runtime: 4ms

Hint: DP.

by Timer [linyicx@126.com]
2015.09.23
*/
int maxProfit(int* prices, int pricesSize)
{
    if (pricesSize<1) return 0;
    int f[pricesSize][2];
    f[0][0] = 0;
    f[0][1] = -prices[0];
    for (int i=1;i<pricesSize;i++)
    {
        f[i][0] = f[i-1][1]+prices[i] > f[i-1][0] ? f[i-1][1]+prices[i] : f[i-1][0];
        f[i][1] = f[i-1][1] > f[i-1][0]-prices[i] ? f[i-1][1] : f[i-1][0]-prices[i];
    }
    return f[pricesSize-1][0];
}
