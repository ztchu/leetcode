#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
		for (int i = 0; i < nums.size(); ++i)
		{
			for (int j = i + 1; j < nums.size(); ++j)
			{
				if (nums[i] + nums[j] == target)
				{
					ans.push_back(i);
					ans.push_back(j);
				}
			}
		}
		return ans;
    }
};

int main()
{
	int arr[] = {2, 7, 11, 15};
	vector<int> nums(arr, arr + sizeof(arr) / sizeof(int));

	int target = 9;

	Solution so;
	vector<int> ans;
	ans = so.twoSum(nums, target);

	for (int i = 0; i < ans.size(); ++i, ++i)
	{
		cout << "[" << ans[i] << "," << ans[i + 1] << "]" << endl;
	}
}