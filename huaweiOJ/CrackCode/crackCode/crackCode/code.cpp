#include<iostream>
#include<string>
#include<vector>
#include<cctype>

using namespace std;

class Code
{
public:
	void Input();
	void DealCode();
	char DealLowerCh(char ch);
private:
	vector<string> m_vecStr;
};

void Code::Input()
{
	string str;
	while (cin >> str)
		m_vecStr.push_back(str);
}

void Code::DealCode()
{
	//Input();
	for (int i = 0; i < m_vecStr.size(); ++i)
	{
		string ans;
		for (int j = 0; j < m_vecStr[i].length(); ++j)
		{
			char ch = m_vecStr[i].at(j);
			if (ch >= 'A' && ch <= 'Z')
			{
				ch += 32;
				if (ch < 'z')
					ch += 1;
				else
					ch = 'a';
			}
			else if (ch >= 'a' && ch <= 'z')
			{
				ch = DealLowerCh(ch);
			}
			ans.push_back(ch);
		}

		cout << ans << endl;
	}
}

char Code::DealLowerCh(char ch)
{
	if (ch >= 'a' && ch <= 'c')
		return '2';
	else if (ch >= 'd' && ch <= 'f')
		return '3';
	else if (ch >= 'g' && ch <= 'i')
		return '4';
	else if (ch >= 'j' && ch <= 'l')
		return '5';
	else if (ch >= 'm' && ch <= 'o')
		return '6';
	else if (ch >= 'p' && ch <= 's')
		return '7';
	else if (ch >= 't' && ch <= 'v')
		return '8';
	else if (ch >= 'w' && ch <= 'z')
		return '9';

}

int main()
{
	Code cd;
	cd.Input();
	cd.DealCode();
}
