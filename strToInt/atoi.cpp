#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    int myAtoi(string str) {
    	int i = 0;
    	while (str[i] == ' ') ++i;
    	
    	bool flag = false;
    	if (str[i] == '+')
    		++i;
   		else if (str[i] == '-')
   		{
		   	++i;
		   	flag = true;
	    }
	    
	    long long ans = 0;
	   // bool overFlow = false;
	    for (int j = i, num = 0, len = str.length(); j < len; ++j)
	    {
    		if (isdigit(str[j]))
    		{
		    	ans *= 10;
		    	ans += str[j] - '0';
		    	if (ans >= INT_MAX && !flag)
		    	{
	    			return INT_MAX;
	    		}
	    		if (ans - 1 >= INT_MAX && flag)
	    			return 0 - INT_MAX - 1;
		    }
		    else 
	    	{
	    		break;
	    	}
    	}
    	if (flag)
   		{
   			return 0 - ans;
    	}
    	else
   			return ans;
	    //return 0;
    }
};
//const long long MAX_INT = 2147483647;
/*
class Solution {
public:
	
	
    int myAtoi(string str) {
        int len = str.length();
        if (len == 0)
        {
        	return 0;
        }
        
        bool flag = false;
        
        int i = 0;
        for (; str[i] == ' '; ++i);
        int start = i;
        
        if (str[i] == '-')
        {
        	flag = true;
        	start = i + 1;
        }
        if (str[i] == '+')
        	start = i + 1;
        
        long long ans = 0;
        for (int i = start; i < len; ++i)
        {
        	
        	if (isdigit(str[i]))
        	{
	        	ans *= 10;
	        	ans += (str[i] - '0');
	        }	
       		else 
       			break;
        }
        if (flag && (ans - 1 <= INT_MAX))
        {
        	return 0 - ans;
        }
        if (flag && (ans - 1 > INT_MAX))
        {
        	return -2147483648;
        }
        if (ans <= INT_MAX)
        {
        	return ans;
        }
        if (ans > INT_MAX)
        {
        	return INT_MAX;
        }
        return 0;
    }
};*/

int main()
{
	Solution so;
	string sr("  -0012a42");
	int ans = so.myAtoi(sr);
	cout << ans << endl;
}