/*
Time: O(n)
Space: O(n)
Runtime: 16ms

Hint: Use hash.

by Timer [linyicx@126.com]
2015.09.12
*/
class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        int l;
        l = nums.size();
        unordered_map <int,int> hash;
        unordered_map <int,int>::iterator it;
        hash.clear();
        vector<int> ans;
        ans.clear();
        
        for (int i=0;i<l;i++)
        {
            int x,y;
            y = nums[i];
            x = target - y;
            it = hash.find(x);
            
            if (it != hash.end())
            {
                ans.push_back((*it).second);
                ans.push_back(i+1);
                break;
            }
            else
            {
                hash.insert(pair<int,int>(y,i+1));
            }
        }
        
        return ans;
    }
};
