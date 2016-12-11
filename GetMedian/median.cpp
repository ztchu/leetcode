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

double Median(vector<int> &vec)
{
	int len = vec.size();
	if (len == 0)
	{
		cerr << "wrong input parameters" << endl;
		exit(EXIT_FAILURE);
	}
	if (len % 2)
	{
		return vec[len / 2];
	}
	else 
	{
		return (vec[len / 2] + vec[len / 2 - 1]) / 2.0;
	}
}

double findMedianSortedArrays(vector<int> &veca, vector<int> &vecb)
{
	int lena = veca.size();
	int lenb = vecb.size();
	if (lena == 0 && lenb > 0)
	{
		return Median(vecb);
	}
	else if (lenb == 0 && lena > 0)
	{
		return Median(veca);
	}
	else if (lena == 0 && lenb ==0)
	{
		return 0;
	}
	
	//make sure lena <= lenb
	if (lena > lenb)
	{
		return findMedianSortedArrays(vecb, veca);
	}
	
	double mida = Median(veca);
	double midb = Median(vecb);

	
	if (lena == 1)
	{
		if (lenb % 2 == 0)
		{
			if (veca[0] <= vecb[lenb / 2 - 1])
			{
				return vecb[lenb / 2 - 1];
			}
			else if (veca[0] > vecb[lenb / 2])
				return vecb[lenb / 2];
			else 
				return veca[0];
		}
		else if (lenb == 1)
		{
			return (veca[0] + vecb[0]) / 2.0;
		}
		else 
		{
			if (veca[0] <= vecb[lenb / 2 - 1])
			{
				return (vecb[lenb / 2] + vecb[lenb / 2 - 1]) / 2.0;
			}
			else  if (veca[0] >= vecb[lenb / 2 + 1])
			{
				return (vecb[lenb / 2] + vecb[lenb / 2 + 1]) / 2.0;
			}
			else 
			{
				return (veca[0] + midb) / 2.0;
			}
		}
	}
	if (lena == 2 && lenb % 2 == 0)
	{
		if (veca[0] >= vecb[lenb / 2 - 1] && veca[1] <= vecb[lenb / 2])
			return (veca[0] + veca[1]) / 2.0;
		if (veca[0] <= vecb[lenb / 2 - 1] && veca[1] >= vecb[lenb / 2])
			return (vecb[lenb / 2 - 1] + vecb[lenb / 2]) / 2.0; 
		//return ((veca[0] > vecb[0] ? veca[0] : vecb[0]) + (veca[1] < vecb[1] ? veca[1] : vecb[1])) / 2.0;
	}

	int off = (lena <= lenb) ? (lena / 2) : (lenb / 2 );
	if (mida == midb)
	{
		return mida;
	}
	else if (mida < midb)
	{
		//vector<int>::iterator itera = mida.begin();
		
		
		vector<int> vecSubA(veca.begin() + off, veca.end());
		vector<int> vecSubB(vecb.begin(), vecb.end() - off);
		return findMedianSortedArrays(vecSubA, vecSubB);
	}
	else 
	{
		//int off = (lenb % 2) ? (lenb / 2) : (lenb / 2 - 1);
		vector<int> vecSubB(vecb.begin() + off, vecb.end());
		vector<int> vecSubA(veca.begin(), veca.end() - off);
		return findMedianSortedArrays(vecSubA, vecSubB);
	}
}



int main()
{
	int arra[] = {
		//1, 12, 15, 26, 38
		//1, 2, 6
		1, 2, 6
	//2,8
	};
	int arrb[] = {
		//2, 13, 17, 30, 45
		//3
	//	1,3,4,5,6,7
	3, 4, 5
	};
	
	vector<int> veca(arra, arra + sizeof(arra) / sizeof(int));
	vector<int> vecb(arrb, arrb + sizeof(arrb) / sizeof(int));	
	double median = findMedianSortedArrays(veca, vecb);
	
	cout << median << endl;
}