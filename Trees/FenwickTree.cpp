#include "bits/stdc++.h"
using namespace std;
// Fenwick tree
void update(int index, int val, vector<int>&fenwick)
{
	while(index < (int)fenwick.size())
	{
		fenwick[index] = fenwick[index] + val;
		index = index + (index & (-index));
	}
}
int sum(int index, vector<int>&fenwick)
{
	int Sum = 0;
	while(index > 0)
	{
		Sum = Sum + fenwick[index];
		index = index - (index & (-index));
	}
	return Sum;
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector<int>v(n);
		for(int i = 0; i < n; i++) cin >> v[i];
		vector<int>fenwick(n+1, 0);
		for(int i = 0; i < n; i++)
		{
			update(i+1, v[i], fenwick);
		}
		cin >> n;
		for(int i = 0; i < n; i++)
		{
			int x, y;
			cin >> x >> y;
			cout << sum(y, fenwick) - sum(x-1, fenwick) << endl;
		}
    	if(t != 0) cout << endl;
	}
 	return 0;
}
