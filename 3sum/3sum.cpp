#include<iostream>
#include<vector>
//#include<unordered_set>
#include<algorithm>

using namespace std;

/*
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
};*/


class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        vector<vector<int> > ans;
        
        int len = nums.size();
        for (int i = 0; i < len - 2; ++i)
        {
        	if (i > 0 && nums[i] == nums[i - 1]) continue;
        
	        FindTriple(nums, i + 1, len - 1, nums[i], ans);
        }
        return ans;
    }
    
    void FindTriple(vector<int> &nums, int j, int k, int target, vector<vector<int> > &ans)
    {
    	while (j < k)
        {
	       	if (0 - target == nums[j] + nums[k])
	       	{
	       		vector<int> tmp;
	       		tmp.push_back(target);
	       		tmp.push_back(nums[j]);
	       		tmp.push_back(nums[k]);
	       		ans.push_back(tmp);
	       		
	       		while (j < k && nums[j] == nums[j + 1]) ++j;
	       		while (j < k && nums[k] == nums[k - 1]) --k;
	       		++j;
	       		--k;
	       	}
	       	else if (0 - target > nums[j] + nums[k])
	       	{
	       		++j;
	       	}
	       	else
	       	{
	       		--k;
	       	}
     	}
    }
};



int main()
{
	
}