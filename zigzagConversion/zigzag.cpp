#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        //int len = s.length();
        int len = s.size();
        //vector<string> tmp(numRows, "");
        string tmp[numRows];
        int gap = numRows - 2;
        for (int i = 0;  i < len;)
        {
        	
	        for (int j = 0; i < len && j < numRows; ++j, ++i)
	        {
        		tmp[j] += s[i];//s.substr(i, 1);
        	}
        	for (int j = gap; i < len && j > 0; --j, ++i)
        	{
	        	tmp[j] += s[i];//s.substr(i, 1);
	        }
        }
        string ans("");
        for (int i = 0; i < numRows; ++i)
        {
        	ans += tmp[i];
        }
        return ans;
    }
};

int main()
{
	Solution so;
	string ans = so.convert("PAYPALISHIRING", 3);
	cout << ans << endl;
}