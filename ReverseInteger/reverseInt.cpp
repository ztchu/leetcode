#include<iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
    	
    	bool flag = false;
    	if (x == -2147483648)
        	return 0;
        if (x < 0)
        {
        	x = 0 - x;
       		flag = true;
        }
        
        
        long long ans = 0;
       	while (x)
       	{
       		ans *= 10;
   	 		ans += x % 10;
   	 		x /= 10;
        }
        if (ans > 2147483647)  {
            return 0;
         }
        return flag ? (0 - ans) : ans;
       	
    }
};

int main()
{
	Solution so;
	int ans = so.reverse(1235678);
	cout << ans << endl;
}