#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
        bool isPalindrome(string s){
            int length = s.size();
            int leftPointer = 0;
            int rightPointer = 0+length-1;

            while(leftPointer < rightPointer)
            {
                while(!isalphaNumeric(s[leftPointer]))
                {
                    leftPointer++;
                }

                while(!isalphaNumeric(s[rightPointer]))
                {
                    rightPointer--;
                }

                if(lowerCase(s[leftPointer]) != lowerCase(s[rightPointer]))
                {
                    return false;
                }

                //cout << s[rightPointer];

                leftPointer++;
                rightPointer--;
            }

            return true;

        }

        bool isalphaNumeric(char c){
            if(c>=65 && c<=90)
                return true;
            else if(c>= 97 && c<= 122)
                return true;
            
            return false;

        }

        char lowerCase(char c){
            if(c>=65 && c<=90)
                return c+32;
            
            return c;
        }
};

int main()
{

    Solution S;
    string s = " ";
    bool ans = S.isPalindrome(s);

    cout << "Ans is: " << ans << endl;
    
    return 0;

}