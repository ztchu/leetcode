#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int lens = s.length();
        int lenp = p.length();
        
        if (lenp == 0)
        {
        	return lenp == lens;
        }
        
        if (lenp == 1)
        {
        	return ((s[0] == p[0] || p[0] == '.') && (lenp == lens));	
        }
        
        if (p[1] == '*')
        {
        	while ((p[0] == s[0] || p[0] == '.') && lens != 0)	 
        	{
        		//if (lens == 0) 
        		//	break;
        		
	        	if (isMatch(s, p.substr(2, lenp - 2)))
	        		return true;
        		s = s.substr(1, lens - 1);
        		lens = s.length();
	        }
	        return isMatch(s, p.substr(2, lenp - 2));
        }
        if (p[0] == s[0] || p[0] == '.')
        {
        	return s[0] == '\0' ? false : isMatch(s.substr(1, lens - 1), p.substr(1, lenp - 1));
        }
        return false;
    }
};

bool isMatchA(char *s, char *p){
    if(*s == '\0' && *p == '\0')
        return true;
        
    if (*(p+1) == '*'){
        while(*p == *s || *p == '.'){ //若*s和*p相等，挨个略过
            if(isMatchA(s++, p+2))
                return true;
        }
        return isMatchA(s, p+2); //若*s和*p不等，直接略过*p；或者当*(p+2) == '\0'时的最后处理
    }
    
    if(*s == *p || *p == '.')
        return *s == '\0' ? false : isMatchA(s+1, p+1);
    
    return false;
}

bool isMatch(const char *s, const char *p) {
        if(*s == '\0'){
            if(*p == '\0') return true;
            if(*p != '*') return false;
        }
        if(*p == '?') return isMatch(++s, ++p);
        else if(*p == '*'){
            while(*(++p) == '*');
            for(; *s != '\0'; ++s){
                if(isMatch(s, p)) return true;
            }
            return isMatch(s, p);
        }else{
            if(*p == *s) return isMatch(++s, ++p);
            return false;
        }
        return false;
    }

int main()
{
	string sr, pat;
	Solution so;
	while (cin >> sr >> pat)
	{
		if (so.isMatch(sr, pat))
		//if (isMatch("acaabbaccbbacaabbbb", "a*.*b*.*a*aa*a*"))
			cout << "true" << endl;
		else 
			cout << "false" << endl;
	}
}

//"acaabbaccbbacaabbbb"
//"a*.*b*.*a*aa*a*"

//"aaa"
//"ab*ac*a"