#include<iostream>
#include<vector>

using namespace std;

int GetKth(vector<int> &veca, vector<int> &vecb, int k)
{
	int lena = veca.size();
	int lenb = vecb.size();
	
	if (k > lena + lenb)
		exit(EXIT_FAILURE);
	
	if (lena == 0)
	{
		return vecb[k - 1];
	}
	if (lenb == 0)
	{
		return veca[k - 1];
	}
	if (veca[lena / 2] > vecb[lenb / 2])
	{
		return GetKth(vecb, veca, k);
	}
	
	if (k <= lena / 2 + lenb / 2 + 1)
	{
		//vector<int> vecaa(veca.begin(), veca.end());
		vector<int> vecbb(vecb.begin(), vecb.begin() + lenb / 2);
		return GetKth(veca, vecbb, k);
	}
	else 
	{
		vector<int> vecaa(veca.begin() + lena / 2 + 1, veca.end());
		return GetKth(vecaa, vecb, k - lena / 2 - 1);
	}
}

int main()
{
	int arra[] = {
		3, 5, 7
	};
	int arrb[] = {
		2, 4, 6
	};
	
	vector<int> veca(arra, arra +sizeof(arra) / sizeof(int));
	vector<int> vecb(arrb, arrb + sizeof(arrb) / sizeof(int));
	
	int ans = GetKth(veca, vecb, 3);
	cout << ans << endl;
}