/*
Time: O(n)
Space: O(n)
Runtime: 0ms

Hint: DP.

by Timer [linyicx@126.com]
2015.09.19
*/
int rob(int* nums, int numsSize)
{
    if (numsSize<=0) return 0;
    int a[numsSize][2];
    a[0][0] = 0; // Not robbing this house
    a[0][1] = nums[0]; // Robbing this house
    for (int i=1;i<numsSize;i++)
    {
        a[i][0] = a[i-1][0]>a[i-1][1] ? a[i-1][0]:a[i-1][1];
        a[i][1] = a[i-1][0] + nums[i];
    }
    return a[numsSize-1][0]>a[numsSize-1][1] ? a[numsSize-1][0]:a[numsSize-1][1];
}
