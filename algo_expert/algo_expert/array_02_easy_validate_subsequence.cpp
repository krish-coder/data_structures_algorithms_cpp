#include<iostream>
#include <vector>
using namespace std;

// Time O(N)
// Space O(1)
bool valid_subsequence(vector<int>& arr, vector<int>& seq)
{
	int n1 = arr.size();
	int n2 = seq.size();
	int idx = 0;
	for (int i = 0; i < n1; i++)
	{
		if (arr[i] == seq[idx])
		{
			idx++;
			if (idx == n2)
				return true;
		}
	}
	return false;
}

int main()
{
	vector<int> arr{5,1,22,25,6,-1,8,10 };
	vector<int> seq{1,6,-1,11};
	cout << valid_subsequence(arr, seq) << endl;
	return 0;
}