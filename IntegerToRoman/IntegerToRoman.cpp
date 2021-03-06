#include<iostream>
#include<string>
#include<map>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
    	int flag = 1;
    	string ans("");
    	if (num < 1 || num > 3999)
    		return ans;
        while (num != 0)
        {
        	ans = intToRoman(num % 10, flag) + ans;
        	num /= 10;
        	flag *= 10;
        }
        return ans;
    }
    string intToRoman(int num, int flag)
    {
    	string ans("");
    	map<int, char> mat;
    	mat.insert(make_pair<int, char>(1, 'I'));
    	mat.insert(make_pair<int, char>(5, 'V'));
    	mat.insert(make_pair<int, char>(10, 'X'));
    	mat.insert(make_pair<int, char>(50, 'L'));
    	mat.insert(make_pair<int, char>(100, 'C'));
    	mat.insert(make_pair<int, char>(500, 'D'));
    	mat.insert(make_pair<int, char>(1000, 'M'));
    	
    	if (num == 9)
    	{
	    	ans += mat[flag];
	    	ans += mat[flag * 10];
	    }
	    else if (num > 5)
	    {
    		ans += mat[flag * 5];
    		for (int i = 0; i < num - 5; ++i)
    			ans += mat[flag];
    	}
    	else if (num == 5)
    		ans += mat[flag * 5];
   		else if (num == 4)
   		{
			ans += mat[flag];
			ans += mat[flag * 5];
	    }
	    else 
	    {
    		for (int i = 0; i < num; ++i)
    			ans += mat[flag];
    	}
    	return ans;	
    }
};

int main()
{
	string ans("qingya");
	Solution so;
	ans = so.intToRoman(3999);
	//ans = 'a' + ans;
	cout << ans << endl;
}

