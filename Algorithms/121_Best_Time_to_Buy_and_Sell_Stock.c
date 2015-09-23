/*
Time: O(n)
Space: O(1)
Runtime: 4ms

by Timer [linyicx@126.com]
2015.09.23
*/
int maxProfit(int* prices, int pricesSize)
{
    if (pricesSize<1) return 0;
    int min,ret;
    min = prices[0];
    ret = 0;
    for (int i=1;i<pricesSize;i++)
    {
        int t;
        t = prices[i]-min;
        if (t>ret) ret=t;
        if (prices[i]<min) min=prices[i];
    }
    return ret;
}
