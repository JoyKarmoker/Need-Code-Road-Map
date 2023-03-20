#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        st.push(0);
        for(char x: s)
        {
            int num = this->convertNum(x);
            int top;
            int opposite;

            if(num >=1 && num <=3)
            {
                st.push(num);
            }

            else
            {
                opposite = this->oppositeNum(num);
                top  = st.top();

                if(top != opposite)
                {
                    return false;
                }
                    
                else
                    st.pop();
            }
        }

        if(st.top() == 0)
            return true;
        else
            return false;
        
    }

    int convertNum(char &c)
    {
        switch (c)
        {
        case '[':
            return 1;
            break;
        case '{':
            return 2;
            break;
        case '(':
            return 3;
            break;
        case ')':
            return 4;
            break;
        case '}':
            return 5;
            break;
        case ']':
            return 6;
            break;
        
        default:
            return -1;
            break;
        }
    }

    int oppositeNum(int &num)
    {
        switch (num)
        {
        case 4:
            return 3;
            break;
        case 5:
            return 2;
            break;
        case 6:
            return 1;
            break;
        
        default:
            return -1;
            break;
        }
    }
};

int main()
{
    Solution s;
    string str = "()[{({})}]{}";
    cout << s.isValid(str) << endl;
    return 0;
}