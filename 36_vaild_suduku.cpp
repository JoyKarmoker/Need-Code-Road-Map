#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        unordered_set<char> charSet;
        int i = 0;
        int ilen = board.size();
        int jlen = board[0].size();
        int j = 0;

        /*check Row*/
        for (i = 0; i <ilen; i++)
        {
            cout << "Row: " << i << endl;
            for (j = 0; j < jlen; j++)
            {
                char temp = board[i][j];
                
                if(temp >= '1' && temp <= '9')
                {
                    if (charSet.find(temp) == charSet.end())
                    {
                        cout << "Insert " << temp << endl;
                        charSet.insert(temp);
                    }

                    else
                    {
                        cout << temp << endl;
                        cout << "Row invalid" << endl;
                        return false;
                    }
                }

            }

            cout << "Clear" << endl;
            charSet.clear();
        }

        cout << "Col check" << endl;
        /*check Column*/
        for (i = 0; i < 10; i++)
        {
            cout << "Col: " << i << endl;
            for (j = 0; j < 10; j++)
            {
                char temp = board[j][i];

                if(temp>='1' && temp <='9')
                {
                    if (charSet.find(temp) == charSet.end())
                    {
                        cout << "Insert " << temp << endl;
                        charSet.insert(temp);
                    }

                    else
                    {
                        cout << "Col invalid" << endl;
                        return false;
                    }
                }
               
            }

            charSet.clear();
        }

        //Box Check
        unordered_set<char> chSet[9];
        for(i=0; i<10; i++)
        {
            cout << "Row: " << i << endl;
            for(j=0; j<10; j++)
            {
                int index = (i+j)/3;
                char temp = board[j][i];
                if(temp >= '1' && temp <= '9')
                {
                    if (chSet[index].find(temp) == chSet[index].end())
                    {
                        chSet[index].insert(temp);
                    }

                    else
                    {
                        cout << "Box invalid" << endl;
                        return false;
                    }                    
                }



            }
        }

        return true;
    }
};

int main()
{
    Solution sol;
    vector<vector<char> > board{
    {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
     {'5', '3', '.', '.', '7', '.', '.', '.', '.'}, 
     {'5', '3', '.', '.', '7', '.', '.', '.', '.'}, 
     {'5', '3', '.', '.', '7', '.', '.', '.', '.'}, 
     {'5', '3', '.', '.', '7', '.', '.', '.', '.'}, 
     {'5', '3', '.', '.', '7', '.', '.', '.', '.'}, 
     {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
     {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
     {'5', '3', '.', '.', '7', '.', '.', '.', '.'}, 
     {'5', '3', '.', '.', '7', '.', '.', '.', '.'}};

    bool ans = sol.isValidSudoku(board);

    cout << "Output: " << ans << endl;
    return 0;
}