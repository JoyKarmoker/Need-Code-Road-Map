#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*
     * @param strs: a list of strings
     * @return: encodes a list of strings to a single string.
     */
    string encode(vector<string> &strs)
    {
        // write your code here
        string longtext = "";
        
        for (string s : strs)
        {
            int len = s.length();
            string l = to_string(len);
            longtext = longtext + l + "#" + s;
        }
        return longtext;
    }

    /*
     * @param str: A string
     * @return: dcodes a single string to a list of strings
     */
    vector<string> decode(string &str)
    {
        vector<string> decoded;
        string lenstr = "";
        string text = "";
        int len = str.length();
        //cout << "string length: " << len << endl;
        int lens;
        //cout << "TExt: ";
        for(int i=0; i<len; i++)
        {
            if(str[i] == '#')
            {
                lens = stoi(lenstr);
                text = str.substr(i+1, lens);
                decoded.push_back(text);
                //cout << text << " " << endl;
                i = i+lens+1;
                lenstr = "";
                //cout << "i: " << i << endl;
            }

            //cout << "i outside: " << i << endl;
            lenstr = lenstr + str[i];
            //cout << "Lenstr: " << lenstr << endl;

        }

        return decoded;
    }
};

int main()
{
    Solution sol;
    vector<string> codetext = {"#4lint", "co#de", "4#love", "#you"};\
    vector<string> decoded;
    string encoded = sol.encode(codetext);
    cout << "Encoded: " << encoded << endl;
    decoded = sol.decode(encoded);

    cout << "Decode: ";
    for(auto x: decoded)
    {
        cout << x << " ";
    }

    return 0;
}