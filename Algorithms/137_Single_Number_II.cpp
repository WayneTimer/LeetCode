/*
Time: O(2n)
Space: O(n)
Runtime: 16ms

Hint:
SelectK.
Each time randomly choose a number, scan and put less than it into left, greater than it into right. Also count the numbers of elements while doing partition.
Then the size of one array mod K = 1, or the number randomly chosen is the answer.
Continue to run the algorithm for array whick size mod K =1.

At last, amortization analysis shows that time complex is O(2n):
 O((1 + 1/2 * ( 1 - 1/2^n) / (1 - 1/2))*n)
=O(1+(1-1/2^n)n)
=O(2n), when n->infty

by Timer [linyicx@126.com]
2015.10.18
*/
class Solution
{
public:
    const int K = 3;
    
    int singleNumber(vector<int>& nums)
    {
        vector<int> small,big;
        int sum_small,sum_big,l,mid;
     
        while (nums.size()>1)
        {
            l = nums.size();
            small.clear();
            big.clear();
            sum_small=0;
            sum_big=0;
            mid = nums[l>>1];
            
            for (int i=0;i<l;i++)
                if (nums[i]<mid)
                {
                    small.push_back(nums[i]);
                    sum_small++;
                }
                else if (nums[i]>mid)
                {
                    big.push_back(nums[i]);
                    sum_big++;
                }
            
            if (sum_small%K !=0) nums=small;
            else if (sum_big%K !=0) nums=big;
            else
            {
                nums.clear();
                nums.push_back(mid);
            }
        }
        return nums[0];
    }
};
