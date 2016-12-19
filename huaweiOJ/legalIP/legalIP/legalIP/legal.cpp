#include<iostream>
#include<string>
#include<vector>

using namespace std;

class LegalIP
{
public:
	LegalIP();
	void CountIP();
	void Print();

private:
	int IsLegalIP(const string &str);
	bool IsLegalMask(const string &str);
	bool IsPrivateIP(const string &str);
	void GetIPMask(const string &str, string &ip, string &mask);
	void GetField(const string &str, vector<int> &vec);

private:
	vector<int> m_count;
	vector<string> m_str;
};

LegalIP::LegalIP():m_count(7)
{
	for (int i = 0; i < 7; ++i)
		m_count[i] = 0;
}

void LegalIP::CountIP()
{
	string sr;
	while (getline(cin, sr))
		m_str.push_back(sr);

	for (int i = 0; i < m_str.size(); ++i)
	{
		string ip, mask;
		GetIPMask(m_str[i], ip, mask);

		int kindIP = IsLegalIP(ip);
		bool legalMask = IsLegalMask(mask);

		if (kindIP != -1 && legalMask)
		{
			++m_count[kindIP];
			if (IsPrivateIP(ip))
			{
				++m_count[6];
			}
		}
		else
		{
			++m_count[5];
		}
	}
}

void LegalIP::Print()
{
	for (int i = 0; i < m_count.size(); ++i)
	{
		cout << m_count[i];
		if (i == m_count.size() - 1)
			cout << endl;
		else
			cout << " ";
	}
}

int LegalIP::IsLegalIP(const string &str)
{
	vector<int> vec;
	GetField(str, vec);
	if (vec.size() < 4)
		return -1;
	else
	{
		int num = vec[0];
		if (num >= 1 && num <= 127)
			return 0;
		else if (num >= 128 && num <= 191)
			return 1;
		else if (num >= 192 && num <= 223)
			return 2;
		else if (num >= 224 && num <= 239)
			return 3;
		else if (num >= 240 && num <= 255)
			return 4;
	}


/*
	int flag = -1;
	int i;
	int cnt = 0;

	while (str[i] != '.') ++i;
	string sr = str.substr(0, i);
	int num = atoi(sr.c_str());
	if (num >= 1 && num <= 255)
	{
		++cnt;
		++i;
		int key = i;
		for (; i < str.length(); ++i)
		{
			if (str[i] == '.')
			{
				string sr = str.substr(key, i - key);
				if (atoi(sr.c_str()) < 0 || atoi(sr.c_str()) > 255) 
					break;
				key = ++i;
				++cnt;
			}
		}

		if (i == str.length())
		{
			if (num >= 1 && num <= 127)
				flag = 0;
			else if (num >= 128 && num <= 191)
				flag = 1;
			else if (num >= 192 && num <= 223)
				flag = 2;
			else if (num >= 224 && num <= 239)
				flag = 3;
			else if (num >= 240 && num <= 255)
				flag = 4;

		}

	}
	return flag;
	*/
}

bool LegalIP::IsLegalMask(const string &str)
{
	vector<int> vec;
	GetField(str, vec);

	if (vec.size() < 4)
		return false;
	else
	{
		int i;
		for (i = 0; i < vec.size(); ++i)
		{
			if (vec[i] == 255)
				continue;
			else
			{
				if (vec[i] - 1 | vec[i] == 0xff)

				{
					for (int j = vec.size() - 1; j > i; --j)
					{
						if (vec[j] == 0)
							continue;
						else
							return false;
					}
					return true;
				}
				else
					return false;
			}
		}
		return true;
	}

	/*
	int key = 0;
	int i;
	for (i = 0; i < str.length(); ++i)
	{
		if (str[i] == '.' )
		{
			string sr = str.substr(key, i - key);
			key = ++i;
			if (atoi(sr.c_str()) == 255)
			{
				continue;
			}
			else
			{
				if (atoi(sr.c_str()) - 1 | atoi(sr.c_str()) == 0xff)
				{
					return true;
				}
				else
				{
					return false;
				}
			}
		}
	}
	if (i == str.length())
	{
		string sr = str.substr(key, i - key);
		if (atoi(sr.c_str()) == 255)
			return true;
		else
			return false;
	}
*/
}

bool LegalIP::IsPrivateIP(const string &str)
{
	vector<int> vec;
	GetField(str, vec);

	if (vec[0] == 10)
		return true;
	else
	{
		if (vec[0] == 172 && vec[1] >= 16 && vec[1] <= 31)
			return true;
		else if (vec[0] == 192 && vec[1] == 168)
			return true;
		else
			return false;
	}
	
	/*
	int i = 0; 
	while (str[i] != '.')
		++i;
	string sr = str.substr(0, i);

	int num = atoi(sr.c_str());
	if (num == 10)
	{
		return true;
	}
	else
	{
		if (num == 172 || num == 192)
		{
			int key = ++i;
			while (str[i] != '.')
				++i;
			sr = str.substr(key, i - key);

			if (num == 172 && atoi(sr.c_str()) >= 16 && atoi(sr.c_str()) <= 31)
				return true;
			else if (num == 192 && atoi(sr.c_str()) == 168)
				return true;
			else
				return false;
		}
	}
	*/
}

void LegalIP::GetIPMask(const string &str, string &ip, string &mask)
{
	int i = 0; 
	while (str[i] != '~') ++i;

	ip = str.substr(0, i);
	++i;
	mask = str.substr(i, str.length() - i);
}

void LegalIP::GetField(const string &str, vector<int> &vec)
{
	int key = 0;
	int i;
	for (i = 0; i < str.length(); ++i)
	{
		if (str[i] == '.')
		{
			string sr = str.substr(key, i - key);
			if (atoi(sr.c_str()) >= 0 && atoi(sr.c_str()) <= 255)
				vec.push_back(atoi(sr.c_str()));
			key = ++i;
		}
	}
	if (i == str.length())
	{
		string sr = str.substr(key, i - key);
		if (atoi(sr.c_str()) >= 0 && atoi(sr.c_str()) <= 255)
				vec.push_back(atoi(sr.c_str()));
	}
}

int main()
{
	LegalIP judgeIP;

	judgeIP.CountIP();

	judgeIP.Print();
}
