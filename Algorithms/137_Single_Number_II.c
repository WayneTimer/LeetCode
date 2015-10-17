/*
Time: O(nlogk)
Space: O(logk)
Runtime: 8ms

Hint: Each bit of each number occur three times except one.(Do not forget negative number)

by Timer [linyicx@126.com]
2015.10.17
*/
int singleNumber(int* nums, int numsSize)
{
    const int BIT_SIZE = 33;
    int w[BIT_SIZE];
    memset(w,0,sizeof(w));
    
    for (int i=0;i<numsSize;i++)
    {
        unsigned int x,j;
        x = nums[i];
        j = 0;
        while (x)
        {
            if (x&1) w[j]++;
            j++;
            x>>=1;
        }
    }
    
    unsigned int ret,a;
    ret = 0;
    a = 1;
    for (int i=0;i<BIT_SIZE;i++)
    {
        w[i]%=3;
        if (w[i]>0) ret += w[i]*a;
        a<<=1;
    }
    return (int)ret;
}
