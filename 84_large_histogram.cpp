#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
         int largestRectangleArea(vector<int>& heights) {
            
            int max_area = 0;
            int index=0;
            int length = 0;
            int area = 0;
            int start = 0;
            
            stack<pair<int,int>> st;
            pair<int,int> temp;
            
            for(int height:heights)
            {
                start = index;
                //cout << "Here\n";
                while(!st.empty() && (st.top().second > height))
                {
                        //cout << "While\n";
                        temp = st.top();
                        start = temp.first;
                        //cout << temp.first << endl;
                        //cout << "index: " << index << endl; 
                        length = (index-start);
                        //cout << "length: " << length << endl;
                        area = length*temp.second;
                        //cout << "Temp second: " << temp.second << endl;
                        //cout << "Area: " << area << endl;
                        
                        if(area > max_area)
                        {
                            //cout << "if\n";
                            max_area = area;
                            
                        }
                        st.pop();
                         

                }

                //cout << "Pushed: " << f <<" " << height << endl;
                st.push({start, height});         
                index++;
            }

            while (!st.empty())
            {
                temp =st.top();
                length = index - temp.first;
                area = length * temp.second;
                if(area > max_area)
                    max_area = area;
                st.pop();
            }
            

        return max_area;
    }
};

int main()
{

    Solution S;
    vector<int> h = {3,6,5,7,4,8,1,0};
    int ans = S.largestRectangleArea(h);

    cout << "Ans is: " << ans << endl;
    
    return 0;

}