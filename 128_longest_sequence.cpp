#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int longestConsecutive(vector<int> &nums)
        {
            int ans = 0;
            unordered_set<int> st;
            for(auto x: nums)
            {
                st.insert(x);
            }

            for(auto x: nums)
            {
                if(st.find(x-1) == st.end())
                {
                    int length = 0;
                    int temp = x;
                    while(st.find(temp) != st.end())
                    {
                        temp++;
                        length++;
                    }

                    if(length>ans)
                        ans  = length;
                }
            }

            return ans;
        }
};

int main()
{
    Solution sol;
    vector<int> nums = {100,4,200,1,3,2};
    int s = sol.longestConsecutive(nums);

    cout << "Longest Sequence is: " << s << endl;
    return 0;
}