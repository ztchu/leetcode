#include<iostream>
#include<string>
#include<map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> mt;
        CreateMap(mt);
        
        int len = s.length();
        int ans = 0;
        for (int i = len - 1; i >= 0;)
        {
        	int j = i;
        	while (j > 0 && mt[s[j]] >= mt[s[j-1]]) --j;
        	string tp = s.substr(j, i - j + 1);
        	ans += romanToInt(tp, mt);
        	i = j - 1;
        }
        return ans;
    }
    int romanToInt(string s, map<char, int> &mt) 
    {
    	int len = s.length();
    	if (len == 2 && mt[s[1]] > mt[s[0]])
    		return mt[s[1]] - mt[s[0]];
   		int ans = 0;
   		for (int i = 0; i < len; ++i)
   		{
		   	ans += mt[s[i]];
	    }
	    return ans;
    }
    void CreateMap(map<char, int> &mt)
    {
    	mt.insert(make_pair<char, int>('I', 1));
    	mt.insert(make_pair<char, int>('V', 5));
    	mt.insert(make_pair<char, int>('X', 10));
    	mt.insert(make_pair<char, int>('L', 50));
    	mt.insert(make_pair<char, int>('C', 100));
    	mt.insert(make_pair<char, int>('D', 500));
    	mt.insert(make_pair<char, int>('M', 1000));
    }
};

int main()
{
	string sr("MMMCMXCIX");
	Solution so;
	int ans = so.romanToInt(sr);
	cout << ans << endl;
}