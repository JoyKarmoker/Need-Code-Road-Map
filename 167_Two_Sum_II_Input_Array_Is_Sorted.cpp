#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
        vector<int> twoSum(vector<int>& numbers, int target){
            int len = numbers.size();
            int i=0; 
            int j = len-1;
            int tar;
            vector<int> result;

            while(i<j)
            {
                tar = numbers[i] + numbers[j];
                if(tar == target)
                {
                    result.push_back(i+1);
                    result.push_back(j+1);

                    return result;
                }

                else if (tar < target)
                {
                    i = i+1;
                }

                else
                {
                    j = j-1;
                }
            }

            result.push_back(i+1);
            result.push_back(j+1);
            return result;
        }
};

int main()
{
    vector<int> nums;
    Solution s;
    int target;

    nums = {-1, 0};
    target = -1;

    vector<int> result = s.twoSum(nums, target);

    for(int r : result)
    {
        cout << r << " ";
    }

    return 0;
}