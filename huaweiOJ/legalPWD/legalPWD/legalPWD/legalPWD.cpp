#include<iostream>
#include<string>
#include<vector>
#include<cctype>

using namespace std;

class LegalPWD
{
public:
	LegalPWD();
	void Input();
	void Judge();

private:
	
	bool HaveThreeOrMoreCh(const string &str) const;
	bool HaveMulStr(const string &str) const;

private:
	vector<string> m_vecStr;

};

LegalPWD::LegalPWD()
{

}

void LegalPWD::Judge()
{
	//Input();
	for (int i = 0; i < m_vecStr.size(); ++i)
	{
		if (m_vecStr[i].length() < 8)
			cout << "NG" << endl;
		else if (!HaveThreeOrMoreCh(m_vecStr[i]))
		{
			cout << "NG" << endl;
		}
		else if (HaveMulStr(m_vecStr[i]))
			cout << "NG" << endl;
		else
			cout << "OK" << endl;

	}
}

void LegalPWD::Input()
{
	string str;
	while (cin >> str)
		m_vecStr.push_back(str);
}

bool LegalPWD::HaveThreeOrMoreCh(const string &str) const
{
	int upper = 0;
	int lower = 0;
	int digit = 0;
	int other = 0;

	for (int i = 0; i < str.length(); ++i)
	{
		if (isupper(str.at(i)))
			upper = 1;
		else if (islower(str.at(i)))
			lower = 1;
		else if (isdigit(str.at(i)))
			digit = 1;
		else 
			other = 1;
	}

	if (upper + lower + digit + other < 3)
		return false;
	else
		return true;
}

bool LegalPWD::HaveMulStr(const string &str) const
{
	int same_len = 0;
	for (int i = 0; i < str.length(); ++i)
	{
		int temp = i;
		for (int j = 0; j < i; ++j)
		{
			if (str[j] == str[temp])
			{
				++same_len;
				++temp;
			}
			else
			{
				same_len = 0;
				temp = i;
			}

			if (same_len > 2)
				return true;
		}
	}
	return false;
}


int main()
{
	LegalPWD lpwd;
	lpwd.Input();
	lpwd.Judge();
}
