/*
Time: O(n)
Space: O(n)
Runtime: 0ms

Hint:
DP.
Divide into two pars:
1. Do not rob nums[0], DP {nums[1]~nums[numsSize-1]}
2. Rob nums[0], DP {nums[2]~nums[numsSize-2]}

by Timer [linyicx@126.com]
2015.09.26
*/
int rob(int* nums, int numsSize)
{
    if (numsSize<=0) return 0;
    if (numsSize==1) return nums[0];
    
    int a[numsSize][2];
    int ret,s;
    // 1. Do not rob nums[0], calc nums[1]~nums[numsSize-1]
    a[1][0] = 0; // Not robbing this house
    a[1][1] = nums[1]; // Robbing this house
    for (int i=2;i<numsSize;i++)
    {
        a[i][0] = a[i-1][0]>a[i-1][1] ? a[i-1][0]:a[i-1][1];
        a[i][1] = a[i-1][0] + nums[i];
    }
    ret = a[numsSize-1][0]>a[numsSize-1][1] ? a[numsSize-1][0]:a[numsSize-1][1];
    
    // 2. Rob nums[0], calc nums[2]~nums[numsSize-2]
    s = nums[0];
    if (numsSize==2 || numsSize==3) return ret>s ? ret:s;
    a[2][0] = 0; // Not robbing this house
    a[2][1] = nums[2]; // Robbing this house
    for (int i=3;i<numsSize-1;i++)
    {
        a[i][0] = a[i-1][0]>a[i-1][1] ? a[i-1][0]:a[i-1][1];
        a[i][1] = a[i-1][0] + nums[i];
    }
    s+= a[numsSize-2][0]>a[numsSize-2][1] ? a[numsSize-2][0]:a[numsSize-2][1];
    return ret>s ? ret:s;
}
