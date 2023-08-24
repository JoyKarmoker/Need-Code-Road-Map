#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int numrows = matrix.size();
        int numcollums = (numrows > 0) ? matrix[0].size() : 0;

        int left = 0;
        int right = (numrows * numcollums) - 1;
        //cout << "Right: " << right << endl;
        //cout << "Left: " << left << endl;

        while(left <= right)
        {
            int mid = (left+right) / 2;
            int row = mid / numcollums;
            int collum = mid % numcollums;
            //cout << "mid:" << mid << " row: " << row << " collum: " << collum <<endl;

            if(matrix[row][collum] == target)
            {
                return true;
            }
            else if(target < matrix[row][collum])
            {
                right = mid - 1;
                //cout << "right: " << right << endl;
            }
            else
            {
                left = mid + 1;
                //cout << "left: " << left << endl;
            }
        }


        return false;        
    }
};
int main()
{
    Solution S;
    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 35;
    int result = S.searchMatrix(matrix, target);
    cout << "Result: " << result;

    return 0;
}