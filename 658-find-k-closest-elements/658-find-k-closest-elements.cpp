class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {

    // using min_heap
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minh;
    int n=arr.size();
	for (int i = 0; i < n; i++)
    {
		minh.push({abs(arr[i] - x), arr[i]});
    }
	vector<int> v;
	for (int i = 0; i < k; i++)
	{
		v.push_back(minh.top().second);
		minh.pop(); 
	}

	sort(v.begin(), v.end());
	return v;
    }
};