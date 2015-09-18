/*
Time: O(n)
Space: O(1)
Runtime: 8ms

by Timer [linyicx@126.com]
2015.09.18
*/
int singleNumber(int* nums, int numsSize)
{
    for (int i=1;i<numsSize;i++)
        nums[i]^=nums[i-1];
    return nums[numsSize-1];
}
