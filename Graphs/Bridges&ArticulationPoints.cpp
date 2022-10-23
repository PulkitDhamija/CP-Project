#include "bits/stdc++.h"
using namespace std;
// Graphs
void addEdge(vector< vector<int> >&graph, int x, int y)
{
	graph[x].push_back(y);
	graph[y].push_back(x);
}
// Bridges in a graph
void DFS(vector<vector<int>>&graph, vector<bool>&visited, vector<int>&tin, vector<int>&low, int v, int* time, int parent)
{
	visited[v] = true;
	tin[v] = *time;
	low[v] = *time;
	(*time)++;
	for(int i = 0; i < graph[v].size(); i++)
	{
		if(graph[v][i] == parent) continue;
		if(!visited[graph[v][i]]) DFS(graph, visited, tin, low, graph[v][i], time, v);
		if(tin[v] < low[graph[v][i]])
		{
			cout << v << " " << graph[v][i] << endl;
		}
		low[v] = min(low[v], low[graph[v][i]]);
	}
}
void findBridges(vector<vector<int>>&graph)
{
	vector<bool>visited(graph.size(), false);
	vector<int>tin(graph.size());
	vector<int>low(graph.size());
	int t = 0;
	for(int i = 1; i < graph.size(); i++)
	{
		if(!visited[i]) DFS(graph, visited, tin, low, i, &t, -1);
	}
}
set<int>ans;
void DFStraversal(vector<vector<int>>&graph, vector<bool>&visited, vector<int>&tin, vector<int>&low, int v, int* time, int parent)
{
	visited[v] = true;
	tin[v] = *time;
	low[v] = *time;
	(*time)++;
	int cnt = 0;
	for(int i = 0; i < graph[v].size(); i++)
	{
		if(graph[v][i] == parent) continue;
		if(!visited[graph[v][i]])
		{
			DFStraversal(graph, visited, tin, low, graph[v][i], time, v);
			cnt++;
		} 
		if(tin[v] <= low[graph[v][i]] && parent != -1)
		{
			ans.insert(v);
		}
		else if(tin[v] <= low[graph[v][i]] && parent == -1 && cnt > 1) ans.insert(v);
		low[v] = min(low[v], low[graph[v][i]]);
	}
}
void findArticulationPoints(vector<vector<int>>&graph)
{
	vector<bool>visited(graph.size(), false);
	vector<int>tin(graph.size());
	vector<int>low(graph.size());
	int t = 0;
	for(int i = 1; i < graph.size(); i++)
	{
		if(!visited[i]) DFStraversal(graph, visited, tin, low, i, &t, -1);
	}
	for(auto it : ans) cout << it << " ";
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		ans.clear();
		int n;
		cin >> n;
		vector< vector<int> > graph(n+1, vector<int>());
		cin >> n;
		for(int i = 0; i < n; i++)
		{
			int x, y;
			cin >> x >> y;
			addEdge(graph, x, y);
		}
		findBridges(graph);
		findArticulationPoints(graph);
		if(t != 0) cout << endl;
	}
 	return 0;
}