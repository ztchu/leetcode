#include<iostream>
#include<vector>

using namespace std;
/*
class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int ans = 0;
        for (int i = 0; i < len; ++i)
        {
        	for (int j = i + 1; j < len; ++j)
        	{
	        	int temp = (j - i) * min(height[i], height[j]);
	        	if (ans < temp)
	        		ans = temp;
	        }
        }
        return ans;
    }
};*/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int ans = 0;
        for (int i = 0, j = len - 1; i < j; )
        {
        	int temp = (j - i) * min(height[i], height[j]);
        	if (temp > ans)
        		ans = temp;
       		height[i] < height[j] ? ++i : --j;
        }
        return ans;
    }
};

int main()
{
	int arr[] = {
		3, 5, 7, 4, 9
	};
	vector<int> vec(arr, arr + sizeof(arr) / sizeof(int));
	Solution so;
	int ans = so.maxArea(vec);
	cout << ans << endl;
}