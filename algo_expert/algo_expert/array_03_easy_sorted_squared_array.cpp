#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> sorted_squared_array(vector<int>& arr)
{
	int n = arr.size();
	vector<int> result(n, 0);
	int left = 0;
	int right = n - 1;
	int idx = n - 1;
	while (left <= right)
	{
		int left_sq = arr[left] * arr[left];
		int right_sq = arr[right] * arr[right];
		if (left_sq >= right_sq)
		{
			result[idx] = left_sq;
			left++;
		}
		else
		{
			result[idx] = right_sq;
			right--;
		}
		idx--;
	}
	return result;
}

int main()
{
	vector<int> arr{ -1, 3,4,5,6,-10 };
	sort(arr.begin(), arr.end());
	vector<int> result = sorted_squared_array(arr);
	for (const auto& x : result)
		cout << x << endl;
	return 0;
}