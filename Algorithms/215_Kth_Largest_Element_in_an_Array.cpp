/*
Time: O(2n)=O(n)
Space: O(n)
Runtime: 8ms

Hint:
1. Find a pivot, O(n) search the whole array, biger than pivot put left, smaller than pivot put right;
2. If Kth largest in left, use left to repeat 1;
3. If Kth largest in right, use right to repeat 1 with K=K-left.size()-1.

by Timer [linyicx@126.com]
2015.11.18
*/
class Solution
{
public:
    int findKthLargest(vector<int>& nums, int k)
    {
        int l,r,mid;
        l = 0;
        r = nums.size()-1;
        mid = l+r>>1;
        vector<int> left,right;
        left.clear();
        right.clear();
        for (int i=l;i<=r;i++)
        {
            if (i==mid) continue;
            if (nums[i]>=nums[mid]) // left is big
                left.push_back(nums[i]);
            else
                right.push_back(nums[i]);
        }
        if (left.size()==k-1)
            return nums[mid];
        else if (left.size()>=k)
            return findKthLargest(left,k);
        else
            return findKthLargest(right,k-left.size()-1);
    }
};
