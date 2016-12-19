#include<iostream>
#include<unordered_map>
#include<string>

using namespace std;

struct Error
{
	string name;
	int line_num;
	int error_count;
};

class ErrorCount
{
public:
	ErrorCount();
	void OpHandleError();
	void Print();

private:
	void GetFileNameNum(const string &str, string & ans, int &num);

private:
	//unordered_map<pair<string, int>, int> m_errorCount;
	vector<Error> m_error;

};

ErrorCount::ErrorCount()
{

}

void ErrorCount::OpHandleError()
{
	string str;
	while (getline(cin, str))
	{
		//int i;
		//for (i = 0; str[i] != ' '; ++i) ;
		//string sr1 = str.substr(0, i);
		string name;
		int num;
		GetFileNameNum(str, name, num);

		//vector<Error>::iterator iter 
		int i;
		for (i = 0; i < m_error.size(); ++i)
		{
			if (m_error[i].name == name && m_error[i].line_num == num)
			{
				++m_error[i].error_count;
				break;
			}
		}
		if (i == m_error.size())
		{
			if (m_error.size() == 8)
			{
				m_error.erase(m_error.begin());
			}
			Error er;
			er.name = name;
			er.line_num = num;
			er.error_count = 1;
			m_error.push_back(er);
		}

		//unordered_map<pair<string, int>, int>::iterator iter 
		//	      = m_errorCount.find(pair<string, int>(name, num));
		/*
		if (iter == m_errorCount.end())
		{
			if (m_errorCount.size() == 8)
				m_errorCount.erase(m_errorCount.begin());

			//m_errorCount.insert(pair<pair<string, int>, int>((name, num), 1));
			m_errorCount.insert(make_pair(pair<string, int>(name, num), 1));
		}
		else
		{
			++iter->second;
		}*/

	}

}

void ErrorCount::GetFileNameNum(const string &str, string & ans, int &num)
{
	int key = 0;
	//bool flag = true;

	string name; //file name
	int line_num;    //line num
	int  i;
	for (i = 0; i < str.length(); ++i)
	{
		if (str[i] == '\\')
		{
			key = i + 1;
		}
		if (str[i] == ' ' )
		{
			//flag = false;
			string sr = str.substr(key, i - key);
			
			if (sr.length() > 16)
			{
				name = sr.substr(sr.length() - 16, 16);
			}
			else
			{
				name = sr;
			}
			break;
		}
	}

	line_num = atoi(str.substr(i, str.length()).c_str());
	ans = name;
	num = line_num;
}

void ErrorCount::Print()
{
	/*for (unordered_map<pair<string, int>, int>::iterator iter = m_errorCount.begin();
		iter != m_errorCount.end(); ++iter)
	{
		cout << iter->first.first << " "  << iter->first.second << " "
			<< iter->second << endl;
	}*/
	for (int i = 0; i < m_error.size(); ++i)
	{
		cout << m_error[i].name << " " << m_error[i].line_num << " " << m_error[i].error_count << endl;
	}
}


int main()
{
	ErrorCount ec;
	ec.OpHandleError();
	ec.Print();
}
