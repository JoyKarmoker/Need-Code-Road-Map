#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int longestConsecutive(vector<int> &nums)
        {
            int ans = 1;
            int longans = 0;
            set<int> st;
            for(auto x: nums)
            {
                st.insert(x);
            }

            /*cout << "Set: ";
            for(auto x: st)
            {
                cout << x <<" ";
            }
            cout << endl;*/

            int len = st.size();
            //cout << "Len: " << len << endl;
            if(len >=1)
            {
                longans = 1;
            }
            auto it =st.begin();
            //cout << "outsideloop" << endl;
            
            for(int i=1; i<len; i++)
            {
                int current = *it;
                auto nextit = next(st.begin(), i);
                int next = *nextit;
                //cout << "CUrrent: " << current <<endl;
                //cout << "Next: " << next << endl;
                if(next == (current+1))
                {
                    //cout << "inloopif" << endl;
                    ans++;
                    if(ans>longans)
                    {
                        longans = ans;
                    }
                }

                else
                {
                    //cout << "current: " << current << endl;
                    //cout << "previous: " << previous << endl; 
                    ans = 1;
                }

                ++it;
            }

            return longans;
        }
};

int main()
{
    Solution sol;
    vector<int> nums = {0};
    int s = sol.longestConsecutive(nums);

    cout << "Longest Sequence is: " << s << endl;
    return 0;
}