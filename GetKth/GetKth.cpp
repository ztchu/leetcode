#include<iostream>
#include<vector>

using namespace std;

int GetKth(vector<int> &veca, vector<int> &vecb, int k)
{
	int lena = veca.size();
	int lenb = vecb.size();
	
	if (k > lena + lenb)
		exit(EXIT_FAILURE);
	
	if (lena > lenb)
	{
		return GetKth(vecb, veca, k);
	}
	if (lena == 0)
	{
		return vecb[k - 1];
	}
	/*if (lenb == 0)
	{
		return veca[k - 1];
	}*/
	if (veca[lena / 2] > vecb[lenb / 2])
	{
		return GetKth(vecb, veca, k);
	}
	
	if (k <= lena / 2 + lenb / 2 + 1)
	{
		vector<int> vecbb(vecb.begin(), vecb.begin() + lenb / 2);
		return GetKth(veca, vecbb, k);
	}
	else 
	{
		vector<int> vecaa(veca.begin() + lena / 2 + 1, veca.end());
		return GetKth(vecaa, vecb, k - lena / 2 - 1);
	}
}

// http://blog.csdn.net/yutianzuijin/article/details/11499917

int GetKthA(vector<int> &veca, vector<int> &vecb, int k)
{
	int lena = veca.size();
	int lenb = vecb.size();
	
	if (k > lenb + lena)
	{
		exit(EXIT_FAILURE);
	}
	
	if (lena > lenb)
	{
		return GetKthA(vecb, veca, k);
	}
	if (lena == 0)
	{
		return vecb[k - 1];
	}
	if (k == 1)
	{
		return min(veca[0], vecb[0]);
	}
	
	int pa = min(lena, k / 2);
	int pb = k - pa;
	
	if (veca[pa - 1] < vecb[pb - 1])
	{
		vector<int> vecaa(veca.begin() + pa, veca.end());
		return GetKthA(vecaa, vecb, k - pa);
	}
	else if (veca[pa - 1] > vecb[pb - 1])
	{
		vector<int> vecbb(vecb.begin() + pb, vecb.end());
		return GetKthA(veca, vecbb, k - pb);
	}
	else 
	{
		return veca[pa - 1];
	}
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
{
    int len = nums1.size() + nums2.size();
	if (len & 0x01)    
	{
		return GetKthA(nums1, nums2, len / 2 + 1);
	}
	else 
	{
		return (GetKthA(nums1, nums2, len / 2 + 1) + 
		        GetKthA(nums1, nums2, len / 2)) / 2.0;
	}
}

int main()
{
	int arra[] = {
		//3, 5, 7
		1, 3
	};
	int arrb[] = {
		//2, 4, 6, 8, 9
		2
	};
	
	vector<int> veca(arra, arra +sizeof(arra) / sizeof(int));
	vector<int> vecb(arrb, arrb + sizeof(arrb) / sizeof(int));
	//int res = GetKth(veca, vecb, 5);
	//cout << "res: " << res << endl;
	//int ans = GetKthA(veca, vecb, 5);
	//cout << ans << endl;
	
	double median = findMedianSortedArrays(veca, vecb);
	cout << "median:" << median << endl;
}