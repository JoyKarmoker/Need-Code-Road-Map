#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
         int largestRectangleArea(vector<int>& heights) {

            int length = heights.size();
            //int max = *max_element(heights.begin(), heights.end());
            int max = 0;
            int consectuive[10050];
            int consecutive_length[10050];

            /*for(int i=1; i<=max; i++)
            {
                consecutive_length[i] = 0;
                consectuive[i] = 0;
            }*/

            memset(consectuive, 0, sizeof(consectuive));
            memset(consecutive_length, 0, sizeof(consecutive_length));

            int ans = 0;
            int temp;

            /*cout << "Conseutive Length : ";
            for(auto i: consecutive_length)
            {
                cout << i << " ";
            }*/

            //cout << "Outside for loop\n";

            for(int height: heights)
            {
                if(height>max)
                    max = height;
                //cout <<"\n\nheight: " << height << endl;
                //cout << "Outside 1st inner for loop\n";
                for(int i=1; i<=height; i++)
                {
                    consecutive_length[i] +=1;

                }
                //cout << "Outside 2nd inner for loop\n";
                for(int i= height+1; i<=(max); i++)
                {
                    //cout << "k" << i <<" ";
                    if(consecutive_length[i] > consectuive[i])
                        consectuive[i] = consecutive_length[i];
                    consecutive_length[i] = 0;
                }
            }

            for(int i= 1; i<=(max); i++)
            {
                //cout << "j" << i <<" ";
                if(consecutive_length[i] > consectuive[i])
                    consectuive[i] = consecutive_length[i];
            }

            //cout << "Outside 2nd looop\n";
            for(int i=1; i<=(max); i++)
            {
                    //cout << "i : " << i <<" : " << consectuive[i] << endl; 
                    temp = i*consectuive[i];
                    if(temp>ans)
                        ans = temp;
                //cout << endl;
            }

        return ans;
    }
};

int main()
{

    Solution S;
    vector<int> h = {2,5};
    int ans = S.largestRectangleArea(h);

    cout << "Ans is: " << ans << endl;
    
    return 0;

}