#include "bits/stdc++.h"
using namespace std;
// Union-Find & Kruskal's Algo
struct edge
{
	int u, v, wt;
};
edge addEdge(int x, int y, int z)
{
	edge E;
	E.u = x;
	E.v = y;
	E.wt = z;
	return E;
}
bool compare(edge a, edge b)
{
	return a.wt < b.wt;
}
int findParent(vector<int>&parent, int child)
{
	if(parent[child] == child) return child;
	else return parent[child] = findParent(parent, parent[child]);
}
void Union(vector<int>&parent, vector<int>&rank, int start, int end)
{
	int x = findParent(parent, start);
	int y = findParent(parent, end);
	if(rank[x] > rank[y])
	{
		parent[y] = x;
	}
	else if(rank[y] > rank[x])
	{
		parent[x] = y;
	}
	else
	{
		parent[y] = x;
		rank[x]++;
	}
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector<int>parent(n+1);
		for(int i = 1; i < n+1; i++) parent[i] = i;
		vector<int>rank(n+1, 0);
		cin >> n;
		for(int i = 0; i < n; i++)
		{
			int x, y;
			cin >> x >> y;
			Union(parent, rank, x, y);
		}
		cin >> n;
		for(int i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			cout << findParent(parent, x) << endl;
		}
		
		// Finding MST using Kruskal's Algo
		int n;
		cin >> n;
		vector<int>parent(n+1);
		for (int i = 1; i < n+1; ++i) parent[i] = i;
		vector<int>rank(n+1, 0);
		cin >> n;
		vector<edge>edges;
		for(int i = 0; i < n; i++)
		{
			int x, y, z;
			cin >> x >> y >> z;
			edges.push_back(addEdge(x, y, z));
		}
		sort(edges.begin(), edges.end(), compare);
		for(int i = 0; i < n; i++)
		{
			if(findParent(parent, edges[i].u) == findParent(parent, edges[i].v)) continue;
			else
			{
				Union(parent, rank, edges[i].u, edges[i].v);
				cout << edges[i].u << " " << edges[i].v << " " << edges[i].wt;
				cout << endl;
			}
		}
		if(t != 0) cout << endl;
	}
 	return 0;
}