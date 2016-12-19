#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int min(int a, int b)
{
	return a < b ? a: b;
}

int MinOfThreeNum(int a, int b, int c)
{
	int ans = min(a, b);
	ans = min(ans, c);
	return ans;
}

int MinDistance(const string &lhs, const string &rhs)
{
	int len1 = lhs.length();
	int len2 = rhs.length();
	
	if (lhs.empty())
	{
		return len2;
	}
	if (rhs.empty())
	{
		return len1;
	}
	
	int **dis = new int *[len1 + 1];
	for (int i = 0; i < len1 + 1; ++i)
	{
		dis[i] = new int[len2 + 1];
	}
	
	for (int i = 0; i < len1 + 1; ++i)
	{
		dis[i][0] = i;
	}
	for (int i = 0; i < len2 + 1; ++i)
	{
		dis[0][i] = i;
	}
	
	for (int i = 1; i < len1 + 1; ++i)
	{
		for (int j = 1; j < len2 + 1; ++j)
		{
			if (lhs[i - 1] == rhs[j - 1])
			{
				dis[i][j] = dis[i - 1][j - 1];
			}
			else
			{
				dis[i][j] = MinOfThreeNum(dis[i - 1][j] + 1, dis[i][j - 1] + 1, 
											dis[i - 1][j - 1] + 1);
			}
		}
	}
	
	int minDis = dis[len1][len2];
	
	for (int i = 0; i < len1 + 1; ++i)
	{
		delete [] dis[i];
	}
	delete [] dis;
	
	return minDis;
}

int main()
{
	string str1;
	string str2;
	cin >> str1 >> str2;
	
	int ans = MinDistance(str1, str2);
	cout << ans << endl;
}