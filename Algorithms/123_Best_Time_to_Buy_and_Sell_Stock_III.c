/*
Time: O(n)
Space: O(n)
Runtime: 4ms

Hint: DP. Two parts : [0~i] + [i+1~n-1]

by Timer [linyicx@126.com]
2015.09.24
*/
int maxProfit(int* prices, int pricesSize)
{
    if (pricesSize<=1) return 0;
    int front[pricesSize];
    int back[pricesSize];
    int front_min,back_max,ret;
    front[0]=0;
    front_min=prices[0];
    back[pricesSize-1]=0;
    back_max=prices[pricesSize-1];
    
    for (int i=1;i<pricesSize;i++)
    {
        int s,j;
        s = prices[i]-front_min;
        front[i] = s>front[i-1] ? s:front[i-1];
        if (prices[i]<front_min) front_min = prices[i];
        
        j = pricesSize-1-i;
        s = back_max-prices[j];
        back[j] = s>back[j+1] ? s:back[j+1];
        if (prices[j]>back_max) back_max = prices[j];
    }
    
    ret = back[0];
    for (int i=0;i+1<pricesSize;i++)
        if (front[i]+back[i+1]>ret)
            ret = front[i]+back[i+1];
    return ret;
}
