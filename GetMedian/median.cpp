#include<iostream>
#include<vector>

using namespace std;

double GetMedian(vector<int> &arra, vector<int> &arrb)
{
	int arraLen = arra.size();
	int arrbLen = arrb.size();
	int midIndex = (arraLen + arrbLen) / 2;
	
	int midLeft = -1;
	int midRight = -1;
	
	
	//int i = 0, j = 0;
	for (int k = 0, i = 0, j = 0; k <= midIndex; ++k)
	{
		if (i < arraLen && (arra[i] < arrb[j] || j >= arrbLen))	
		{
			midLeft = midRight;
			midRight = arra[i++];
		}	
		else
		{
			midLeft = midRight;
			midRight = arrb[j++];
		}
	}
	if ((arrbLen + arraLen) % 2)
	{
		return midRight;
	}
	else 
	{
		return (midLeft + midRight) / 2.0;
	}
}

int main()
{
	int arra[] = {
		//1, 12, 15, 26, 38
		1, 2
	};
	int arrb[] = {
		//2, 13, 17, 30, 45
		3
	};
	
	vector<int> veca(arra, arra + sizeof(arra) / sizeof(int));
	vector<int> vecb(arrb, arrb + sizeof(arrb) / sizeof(int));	
	double median = GetMedian(veca, vecb);
	
	cout << median << endl;
}