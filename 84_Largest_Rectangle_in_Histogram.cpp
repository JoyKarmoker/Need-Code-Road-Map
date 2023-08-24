#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
         int largestRectangleArea(vector<int>& heights) {

            int length = heights.size();
            int max = *max_element(heights.begin(), heights.end());
            stack<int> consectuive[max+1];
            int consecutive_length[max+1];

            for(int i=1; i<=max; i++)
            {
                consecutive_length[i] = 0;
            }

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
                    if(consecutive_length[i] != 0)
                        consectuive[i].push(consecutive_length[i]);
                    consecutive_length[i] = 0;
                }
            }

                for(int i= 1; i<=(max); i++)
                {
                    //cout << "j" << i <<" ";
                    if(consecutive_length[i] != 0)
                        consectuive[i].push(consecutive_length[i]);
                }

            //cout << "Outside 2nd looop\n";
            for(int i=1; i<=(max); i++)
            {
                //cout << "Consecutive length of " << i << " : ";
                while (!consectuive[i].empty()) {
                    //std::cout << consectuive[i].top() << " ";
                    temp = i*consectuive[i].top();
                    if(temp>ans)
                        ans = temp;
                    consectuive[i].pop();
                }
                //cout << endl;
            }

        return ans;
    }
};

int main()
{

    Solution S;
    vector<int> h = {2,4};
    cout << "Start" << endl;
    int ans = S.largestRectangleArea(h);

    cout << "Ans is: " << ans << endl;
    
    return 0;

}