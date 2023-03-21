#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) 
    {
        for(auto x: tokens)
        {
            //cout << "x: " << x << endl;
            num = isOperator(x[0]);
            if(num != -1 && x.length() == 1)
            {
                secondNum = st.top();
                st.pop();
                firstNum = st.top();
                st.pop();

                /*Calculate The Number based on operator*/
                if(num == 1)
                {
                    temp = firstNum + secondNum;
                    st.push(temp);
                    //cout << "+ temp: " << temp << endl;
                }

                else if(num == 2)
                {
                    temp = firstNum - secondNum;
                    st.push(temp);
                    //cout << "- temp: " << temp << endl;
                }

                else if(num == 3)
                {
                    temp = firstNum * secondNum;
                    st.push(temp);
                    //cout << "* temp: " << temp << endl;
                }

                else
                {
                    temp = firstNum / secondNum;
                    st.push(temp);
                    //cout << "/ temp: " << temp << endl;
                }
            }

            else
            {
                st.push(stoi(x));
            }
        }

        return st.top();
    }

    int isOperator(char &tkn)
    {
        switch (tkn)
        {
        case '+':
            return 1;
            break;
        case '-':
            return 2;
            break;
        case '*':
            return 3;
            break;
        case '/':
            return 4;
            break;
        default:
            return -1;
            break;
        }
    }
private:
    stack<int> st;
    int temp = 0;
    int num = 0;
    int firstNum = 0;
    int secondNum = 0;
};

int main()
{
    Solution S;
    vector<string> tokens = {"2","1","+","3","*"};
    int num = S.evalRPN(tokens);

    cout << "Answer is: " << num << endl;
    return 0;
}