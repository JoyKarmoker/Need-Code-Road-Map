#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int area = 0;
        int max = 0;
        int i = 0;
        int j = height.size() - 1;
        while(i<j)
        {
            area = (j-i) * min(height[j], height[i]);
            if(height[i] < height[j])
                i = i+1;
            else
                j = j-1;
            if(area>max)
                max = area;
        }
        return max;
    }
};

int main()
{
    Solution S;
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int result = S.maxArea(height);
    cout << "Result: " << result;

    return 0;
}