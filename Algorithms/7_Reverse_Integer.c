/*
Time: O(log_10(n))
Space: O(1)
Runtime: 4ms

Hint: Consider int bounds.

by Timer [linyicx@126.com]
2015.09.14
*/
int reverse(int x)
{
    const int INF = 214748364;
    int p,ret;
    if (x<0)
        p = -1;
    else
        p = 1;
    ret = 0;
    while (x)
    {
        int y;
        y = x%10;
        if (y<0) y=-y;
        if (ret > INF) return 0;
        if (ret == INF)
        {
            if (p==1 && y>7) return 0;
            if (p==-1 && y>8) return 0;
        }
        ret = ret*10 + y;
        x /= 10;
    }
    return ret*p;
}
