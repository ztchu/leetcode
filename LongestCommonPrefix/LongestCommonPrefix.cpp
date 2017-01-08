#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len = strs.size();
        if (len == 0)
        	return string("");
        int len0 = strs[0].length();
        
       	int index = 0;
        for (int i = 0; i < len0; ++i)
        {
        	for (int j = 1; j < len; ++j)
        	{
	        	if (strs[j].length() <= i || strs[j][i] != strs[0][i])
	        	{
	        		return strs[0].substr(0, index);
	        	}
	        	
	        }
	        ++index;
        }
        return strs[0].substr(0, index);
    }
};

int main()
{
	vector<string> vec;
	int num;
	cin >> num;
	for (int i = 0; i < num; ++i)
	{
		string sr;
		cin >> sr;
		vec.push_back(sr);
	}
	
	Solution so;
	string ans = so.longestCommonPrefix(vec);
	cout << ans << endl;
}