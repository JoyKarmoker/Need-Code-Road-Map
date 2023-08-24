#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int len = nums.size();
        sort(nums.begin(), nums.end());
        int j=1;
        int k=len-1;
        for(int i=0; i<=len-3; i++)
        {
            if(i>0 && nums[i] == nums[i-1])
                continue;
            //printf("Inside for");
            j = i+1;
            k = len-1;
            while(j<k)
            {
                //printf("Inside while");
                if(nums[i] + nums[j] + nums[k] == 0)
                {
                    result.push_back({nums[i], nums[j], nums[k]});
                    j=j+1;
                    while(nums[j] == nums[j-1] && j<k)
                    {
                        j = j+1;
                    }

                    
                }

                else if (nums[i] + nums[j] + nums[k] > 0)
                {
                    k = k-1;
                }

                else
                {
                    j = j+1;
                }
            }
        }

        vector<vector<int>> ::iterator ip;
        ip = unique(result.begin(), result.end());
        result.resize(distance(result.begin(), ip));


        return result;
    }
};

int main()
{
    Solution S;
    vector<int> nums = {-2,0,1,1,2};


    vector<vector<int>> result = S.threeSum(nums);

    for(vector<int> t: result)
    {
        cout << "[";
        for(int i: t)
        {
            cout << i << " ";
        }
        cout << "]";
    }


    return 0;
}