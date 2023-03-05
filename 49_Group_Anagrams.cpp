#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
        vector<vector<string>> groupAnagrams(vector<string> &strs)
        {
            map<map<char, int>, vector<string>> mms;
            vector<vector<string>> ans;
            
            for(auto str: strs)
            {
                map<char, int> mp;
                for(auto i: str)
                {
                    mp[i]++;
                }
                mms[mp].push_back(str);
            }

            for(auto mv: mms)
            {
                vector<string> vs = mv.second;
                ans.push_back(vs);
            }

            return ans;
        }
};

int main()
{
    Solution sol;
    vector<vector<string>> result;
    vector<string> str = {"","",""};
    result = sol.groupAnagrams(str);
    for(auto str: result)
    {
        cout << "Group: ";
        for(auto s: str)
        {
            cout << s << " ";
        }
        cout << endl;
    }
}