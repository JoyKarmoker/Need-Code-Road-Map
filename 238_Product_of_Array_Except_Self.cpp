#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
        vector<int> productExceptSelf(vector<int> & nums)
        {
            //cout << "Answer function called" << endl;
            vector<int> ans;
            int len = nums.size();
            int prefix[len];
            int suffix[len];
            prefix[0] = 1;
            suffix[len-1] = 1;
            int j=1;
            //cout << "Prefix Loop outside" << endl;
            for(int i=0; i<len-1; i++)
            {
                //cout << "Prefix Loop inside" << endl;
                prefix[j] = prefix[j-1]*nums[i];
                j = j+1;
            }
            //cout << "Suffix Loop outside" << endl;
            j=len-2;
            for(int i=len-1; i>=1;i--)
            {
                //cout << "Suffix Loop inside" << endl;
                suffix[j] = suffix[j+1] * nums[i];
                j = j-1;
            }

            //cout << "Prefix: ";
            /*for (auto x:prefix)
            {
                cout << x <<" ";
            }*/
            //cout << endl;

            //cout << "Sufix: ";
            /*for (auto x:suffix)
            {
                //cout << x <<" ";
            }*/
            //cout << endl;

            for(int i=0; i<len; i++)
            {
                int temp = prefix[i]*suffix[i];
                ans.push_back(temp);
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