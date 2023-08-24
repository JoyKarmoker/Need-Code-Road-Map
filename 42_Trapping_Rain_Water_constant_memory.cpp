#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int trapped_water = 0;
        int len = height.size();
        int max_left = height[0];
        int max_right = height[len - 1];
        int left_pointer = 0;
        int right_pointer = len - 1;
        int temp;

        while (left_pointer < right_pointer)
        {
            if (max_left < max_right)
            {
                left_pointer++;
                temp = max_left - height[left_pointer];
                if (temp < 0)
                    temp = 0;
                trapped_water += temp;

                if (height[left_pointer] > max_left)
                    max_left = height[left_pointer];
            }

            else
            {
                right_pointer--;
                temp = max_right - height[right_pointer];
                if (temp < 0)
                    temp = 0;
                trapped_water += temp;
                if (height[right_pointer] > max_right)
                    max_right = height[right_pointer];
            }
        }

        return trapped_water;
    }
};

int main()
{
    Solution S;
    vector<int> height = {1};
    int result = S.trap(height);
    cout << "Result: " << result;

    return 0;
}