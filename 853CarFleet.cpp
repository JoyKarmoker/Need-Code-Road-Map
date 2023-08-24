#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) 
    {
        int ans=0;
        vector<pair<int, int>> list;
        stack<double> st;
        int length = position.size();   

        for(int i=0; i<length; i++)
        {
            list.push_back({(position[i]), speed[i]});
        }

        sort(list.begin(), list.end());

        for(int i= (length-1); i>=0; i--) 
        {
            double temp = ((target-list[i].first) * 1.00)/(list[i].second*1.00);
            if(st.empty())
            {
                //cout << "empty " << " temp is " << temp << endl;
                st.push(temp);
                continue;
            }

            double previous = st.top();
            st.push(temp);

            if(previous >= st.top())
            {
                st.pop();
            }



        }

        /*cout << "Time is: ";
        while(!st.empty())
        {
            cout << st.top() << " ";
            st.pop();
        }
        cout << endl;*/


        return st.size();
    }
};

int main()
{
    Solution s;
    int target = 10;
    vector<int> position = {3, 5, 7};
    vector<int> speed = {3,2, 1};

    int ans = s.carFleet(target,position, speed);
    cout << ans << endl;
    

    return 0;
}