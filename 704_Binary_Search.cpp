#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = static_cast<int> (nums.size() - 1);
        while(left <= right)
        {
            int mid = (left+right)/2;
            if(nums[mid] == target)
            {
                return mid;
            }

            if(target < nums[mid])
            {
                right = mid-1;
            }

            else
            {
                left = mid+1;
            }

        }
        
        return -1;
    }
};

int main()
{
    Solution S;
    vector<int> height = {-1,0,3,5,9,12};
    int target = 2;
    int result = S.search(height, target);
    cout << "Result: " << result;

    return 0;
}