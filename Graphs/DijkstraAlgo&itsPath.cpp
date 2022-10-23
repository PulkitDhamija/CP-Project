#include "bits/stdc++.h"
using namespace std;
// Weighted Graph
void addEdge(int x, int y, int dist, vector<vector<pair<int, int>>>&graph)
{
	graph[x].push_back({y, dist});
	graph[y].push_back({x, dist});
}
void printpath(vector<int>&parent, int start, int end)
{
	if(end == start)
	{
		cout << start;
		return;
	}
	printpath(parent, start, parent[end]);
	cout << "->" << end;
}
void DijkstraAlgo(vector< vector< pair<int, int> > >&graph, int start)
{
	vector<int>parent(graph.size());
	vector<int>dist(graph.size(), INT_MAX/20);
	priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
	parent[start] = -1;
	dist[start] = 0;
	pq.push({0, start});
	while(!pq.empty())
	{
		int temp = pq.top().second;
		pq.pop();
		for(int i = 0; i < graph[temp].size(); i++)
		{
			if(dist[graph[temp][i].first] > dist[temp] + graph[temp][i].second)
			{
				dist[graph[temp][i].first] = dist[temp] + graph[temp][i].second;
				parent[graph[temp][i].first] = temp;
				pq.push({dist[i], graph[temp][i].first});
			}
		}
	}
	for(int i = 0; i < graph.size(); i++)
	{
		printpath(parent, start, i);
		cout << " shortest distance - " << dist[i];
		cout << endl;
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
		vector< vector< pair<int, int> > >graph(n, vector<pair<int, int>>());
		cin >> n;
		for(int i = 0; i < n; i++)
		{
			int x, y, dist;
			cin >> x >> y >> dist;
			addEdge(x, y, dist, graph);
		}
		int start; cin >> start;
		DijkstraAlgo(graph, start);
		if(t != 0) cout << endl;
	}
 	return 0;
}