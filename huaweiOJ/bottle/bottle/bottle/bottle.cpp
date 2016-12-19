#include<iostream>
#include<vector>

using namespace std;

class Bottle
{
public:
	void Input();
	int DealOneGroup(int num) const;
	void DealAll() const;
private:
	vector<int> m_bot;
};

void Bottle::Input()
{
	int num;
	for (cin >> num; num != 0; )
	{
		m_bot.push_back(num);
		cin >> num;
	}
}

int Bottle::DealOneGroup(int num) const
{
	int empty_bol = num;
	int drink = 0;

	for (; empty_bol >= 3; )
	{
		int temp = empty_bol / 3;
		drink += temp;
		empty_bol = temp + empty_bol % 3;
	}

	if (empty_bol == 2)
	{
		drink += 1;
	}
	//cout << drink << endl;
	return drink;
}

void Bottle::DealAll() const
{
	for (int i = 0; i < m_bot.size(); ++i)
	{
		int temp = DealOneGroup(m_bot[i]);
		cout << temp << endl;
	}
}

int main()
{
	Bottle bt;
	bt.Input();
	bt.DealAll();
}