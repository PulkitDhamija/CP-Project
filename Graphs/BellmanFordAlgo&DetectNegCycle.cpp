#include "bits/stdc++.h"
using namespace std;
// Bellman Ford Algo & To Detect Negative wt. cycle
// To detect negative cycle run the loop one more time and if the dist
// decreases one more time for any iteration than it contains a negative
// cycle
struct edge
{
	int start, end, wt;
};
edge GetEdge(int x, int y, int z)
{
	edge E;
	E.start = x;
	E.end = y;
	E.wt = z;
	return E;
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n; cin >> n;
		int src; cin >> src;
		vector<int>dist(n, INT_MAX);
		dist[src] = 0;
		int nedges; cin >> nedges;
		vector<edge>v;
		for(int i = 0; i < nedges; i++)
		{
			int x, y, z;
			cin >> x >> y >> z;
			v.push_back(GetEdge(x, y, z));
		}
		for(int i = 0; i < n-1; i++)
		{
			int flag = 0;
			for(int j = 0; j < nedges; j++)
			{
				if(dist[v[j].start] != INT_MAX &&  dist[v[j].start] + v[j].wt < dist[v[j].end])
				{
					dist[v[j].end] = dist[v[j].start] + v[j].wt;
					flag = 1;
				}
			}
			if(flag == 0) break;
		}
		for(int i = 0; i < dist.size(); i++)
		{
			cout << i << " " << dist[i] << endl;
		}
	}
 	return 0;
}