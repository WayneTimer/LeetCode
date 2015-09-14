/*
Time: O(n)
Space: O(n)
Runtime: 4ms

Hint: ASCII hash.

by Timer [linyicx@126.com]
2015.09.14
*/
int lengthOfLongestSubstring(char* s)
{
    int h[256];
    int ret,i,sum,last;
    memset(h,0,sizeof(h));
    ret = 0;
    i = 0;
    last = 0;
    while (s[i])
    {
        sum = i+1 - h[s[i]];
        if (last+1 < sum) sum = last+1;
        if (sum > ret) ret = sum;
        last = sum;
        h[s[i]] = i+1;
        i++;
    }
    return ret;
}
