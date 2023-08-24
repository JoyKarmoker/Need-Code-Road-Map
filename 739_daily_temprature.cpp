#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dailyTemperatures(vector<int>& temperatures)
    {
        int len = temperatures.size();
        cout << "len is: " << len << endl;; 
        stack<pair<int, int>> cmp; //pair(temprature, index);
        vector<int> ans(len, 0);

        for(int i=0; i<len; i++)
        {
            //cout << "For" << endl;
            while(!cmp.empty() && (cmp.top().first < temperatures[i]))
            {
                //cout << "While" << endl;
                pair<int, int> temp = cmp.top();
                ans[temp.second] = (i-temp.second);
                cmp.pop();
            }

            cmp.push({temperatures[i], i});


        }
        return ans;
        
    }
};

int main()
{
    Solution sol;
    vector<int> temperatures = {73,74,75,71,69,72,76,73};
    vector<int> result = sol.dailyTemperatures(temperatures);
    cout << "[";
    for (auto i : result)
    {
        cout << i << " ";
    }
    cout << "]";
    return 0;
}