#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
        vector<int> productExceptSelf(vector<int> & nums)
        {
            //cout << "Answer function called" << endl;
            
            int len = nums.size();
            vector<int> ans(len, 1);
            int j=1;
            //cout << "Prefix Loop outside" << endl;
            for(int i=0; i<len-1; i++)
            {
                //cout << "Prefix Loop inside" << endl;
                ans[j] = ans[j-1]*nums[i];
                j = j+1;
            }
            cout << "Suffix Loop outside" << endl;
            j=len-2;
            int post = 1;
            for(int i=len-1; i>=1;i--)
            {
                //cout << "Suffix Loop inside" << endl;
                post = post*nums[i];
                ans[j] = ans[j] * post;
                j = j-1;
            }


            return ans;
        }
};


int main()
{
    Solution sol;
    vector<int> nums = {1,2,3,4};
    int k = 1;
    vector<int> ans;
    ans = sol.productExceptSelf(nums);

    cout << "Output: ";
    for (auto a:ans)
    {
        cout << a << " ";
    }

    return 0;
}