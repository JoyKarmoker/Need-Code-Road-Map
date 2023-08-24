#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int trap(vector<int>& height) {
        int trapped_water = 0;
        vector<int> max_left(height.size());
        vector<int> max_right(height.size());
        int len = height.size();
        max_left[0] = 0;
        
        for(int i=1; i<len; i++)
        {
            max_left[i] = max(max_left[i-1], height[i-1]);
        }

        // cout << "Max Left: ";
        // for(int i=0; i<height.size(); i++)
        // {
        //     cout << max_left[i] << " ";
        // }
        // cout << endl;

        max_right[len-1] = 0;
        for(int i= len-2; i>=0; i--)
        {
            max_right[i] = max(max_right[i+1], height[i+1]);
        }

        // cout << "Max Right: ";
        // for(int i=0; i<height.size(); i++)
        // {
        //     cout << max_right[i] << " ";
        // }
        // cout << endl;

        for(int i=0; i<len; i++)
        {
            int temp = min(max_left[i], max_right[i]) - height[i];
            if (temp < 0)
                temp = 0;
            trapped_water += temp;
        }

        return trapped_water;

    }
};

int main()
{
    Solution S;
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    int result = S.trap(height);
    cout << "Result: " << result;

    return 0;
}