#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> >  ans;
        vector<int> temp;
        
        int len = nums.size();
        for (int i = 0; i < len - 2; ++i)
        {
        	for (int j = i + 1; j < len - 1; ++j)
        	{
        		int sum = nums[i] + nums[j];
	        	for (int k = j + 1; k < len; ++k)
	        	{
	        		if (sum + nums[k] == 0)
	        		{
		        		temp.push_back(nums[i]);
		        		temp.push_back(nums[j]);
		        		temp.push_back(nums[k]);
		        		break;
		        	}
	        	}
	        	ans.push_back(temp);
	        	temp.clear();
	        }
        }
        unordered_set<vector<int> > st;
        
        for (int i = 0; i < ans.size(); ++i)
        {
        	st.insert(ans[i]);
        }
        ans.clear();
        for (unordered_set<vector<int> >::iterator iter = st.begin(); iter != st.end(); ++iter)
        {
        	ans.push_back(*iter);
        }
        return ans;
        
        
    }
};

int main()
{
	
}