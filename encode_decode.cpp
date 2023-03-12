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
        //vector<string> spacepos;
        int index = 0;
        int add = 0;
        string code;
        for (string s : strs)
        {
            int len = s.length();
            index = len + index + add;
            string temp = to_string(index);
            int l = temp.length();
            code = code+to_string(l)+temp;
            //spacepos.push_back(index);
            longtext = longtext + s + "#";
            add = 1;
        }
        
        int len = code.size();
        code = to_string(len) + code;
        longtext = code + longtext;

        return longtext;
    }

    /*
     * @param str: A string
     * @return: dcodes a single string to a list of strings
     */
    vector<string> decode(string &str)
    {
        vector<string> decoded;
        string codeLen = str.substr(0, 2);
        int clen = stoi(codeLen);
        //cout << "Length: " << clen << endl;

        string code = str.substr(2, clen);
        string codedText = str.substr(2+clen, str.length());

        //cout << "Code: " << code << endl;
        //cout << "codedText: " <<codedText << endl;

        int i = 0;
        int j = 0;
        int previous = 0;

        while(i < clen)
        {
            
            //cout << "i " << i << endl;
            int codelenpos = stoi(code.substr(i, 1));
            string codel = code.substr(i+1, codelenpos);
            int codepos = stoi(codel);
            //cout << "code len: " << codepos << endl;

            string text = codedText.substr(previous, codepos - previous);
            decoded.push_back(text);
            previous = codepos + 1;

            i = i + codelenpos + 1; 
            //j = j+codeLen+1;
        }
        return decoded;
    }
};

int main()
{
    Solution sol;
    vector<string> codetext = {"lint", "code", "love", "you"};\
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