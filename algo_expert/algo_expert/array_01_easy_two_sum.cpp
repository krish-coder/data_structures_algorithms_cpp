#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

// Time O(NlogN)
// Space O(1)
vector<int> two_number_sum(vector<int>& arr, int target_sum)
{
	vector<int> result;
	int n = arr.size();
	sort(arr.begin(), arr.end());
	
	int idx1 = 0, idx2 = n - 1;
	while (idx1 < idx2)
	{
		int sum = arr[idx1] + arr[idx2];
		if (sum < target_sum)
		{
			idx1++;
		}
		else if (sum > target_sum)
		{
			idx2--;
		}
		else
		{
			result.push_back(arr[idx1]);
			result.push_back(arr[idx2]);
			idx1++;
			idx2--;
		}
	}
	return result;
}
// Time O(N) 
// Space O(N)
vector<int> two_number_sum_map(vector<int>& arr, int target_sum)
{
	vector<int> result;
	map<int, int> mp;
	int n = arr.size();
	for (int i = 0; i < n; i++)
	{
		int value = target_sum - arr[i];
		if (mp.find(arr[i])!= mp.end())
		{
			result.push_back(mp[arr[i]]);
			result.push_back(arr[i]);
		}
		else
		{
			mp[value] = arr[i];
		}
	}
	return result;
}

int main()
{
	vector<int> input{3, 5, -4, 8, 11, 1, -1, 6};
	int target_sum = 10;
	vector<int> result = two_number_sum_map(input, target_sum);
	for (const auto& x : result)
	{
		cout << x << " ";
	}
	cout << endl;
	return 0;
}