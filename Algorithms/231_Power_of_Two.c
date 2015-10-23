/*
Time: O(log(n))
Space: O(1)
Runtime: 8ms

by Timer [linyicx@126.com]
2015.10.23
*/
bool isPowerOfTwo(int n)
{
    if (n<=0) return false;
    while (!(n&1))
    {
        n>>=1;
    }
    if (n^1) return false;
    return true;
}
