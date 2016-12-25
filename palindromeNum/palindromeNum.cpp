#include<iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
    	int val = x;
        int ans = 0;
        while (val)
        {
        	ans *= 10;
        	ans += val % 10;
        	val /= 10;
        }
        return ans == x ? true : false;
    }
};

int main()
{
	int num;
	Solution so;
	/*while (cin >> num)
	{
		cout << num << ":" ;
		if (so.isPalindrome(num))
		{
			cout << "true" << endl;
		}
		else 
		{
			cout << "false" << endl;
		}
	}*/
	cout << -20 / 10 << endl;
}