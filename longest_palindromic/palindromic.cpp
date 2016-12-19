#include<iostream>
#include<vector>
#include<string>


using namespace std;

string Palindromic(const string &sr)
{
	int srLen = sr.length();
	vector<vector<bool> >  table(srLen, vector<bool>(srLen, false));
	
	int maxLen = 1;
	int longestBegin = 0;
	for (int i = 0; i < srLen - 1; ++i)
	{
		table[i][i] = true;
		if (sr[i] == sr[i + 1])
		{
			table[i][i+1] = true;
			maxLen = 2;
			longestBegin = i;
		}	
	}
	table[srLen - 1][srLen - 1]  = true;
	
	for (int len = 3; len <= srLen; ++len)
	{
		for (int i = 0; i < srLen - len + 1; ++i)
		{
			int j = i + len - 1;
			if (sr[i] == sr[j] && table[i + 1][j - 1])
			{
				table[i][j] = true;
				if (len > maxLen)
				{
					maxLen = len;
					longestBegin = i;
				}
			}
		}
	}
	return sr.substr(longestBegin, maxLen);
}

string LongestSubPalindome(const string &sr, int low, int high)
{
	int len = sr.length();
	while (low >= 0 && high <= len - 1 && sr[low] == sr[high])
	{
		--low;
		++high;
	}
	return sr.substr(low + 1, high - low - 1);
}

string LongestPalindome(const string &sr)
{
	int len = sr.length();
	if (len == 0) 
		return "";
		
	string longestPalin = sr.substr(0, 1);
	for (int i = 0; i < len - 1; ++i)
	{
		string p1 = LongestSubPalindome(sr, i, i);
		if (p1.length() > longestPalin.length())
		{
			longestPalin = p1;
		}
		
		string p2 = LongestSubPalindome(sr, i , i + 1);
		if (p2.length() > longestPalin.length())
		{
			longestPalin = p2;
		}
	}
	return longestPalin;
}

int main()
{
	string sr("babcd");
	string ans = LongestPalindome(sr);
	cout << ans << endl;
}

