#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {

        vector<int> ans;
        map<int, int> mp;
        for (auto num : nums)
        {
            mp[num]++;
        }
        
        int len = nums.size();
        vector<int> temp[len+1];
        for(auto m:mp)
        {
            temp[m.second].push_back(m.first);
        }
        int ans_len = 0;

        for(int i=len; i>0; i--)
        {
            if(!temp[i].empty())
            {
                for(auto i: temp[i])
                {
                    ans.push_back(i);
                    ans_len++;
                    if(ans_len == k) return ans;
                }
            }
            
        }

        //cout << "Return" << endl;
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {-1, -1};
    int k = 1;
    vector<int> ans;
    cout << "Before answer" << endl;;
    ans = sol.topKFrequent(nums, k);

    cout << "Answer: ";
    for (auto a:ans)
    {
        cout << a << " ";
    }

    return 0;
}