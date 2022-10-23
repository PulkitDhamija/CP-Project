#include "bits/stdc++.h"
using namespace std;
// Kosaraju's Algo
void addEdge(vector< vector<int> >&graph, int x, int y)
{
	graph[x].push_back(y);
	//graph[y].push_back(x);
}
void TopoSort(vector<vector<int>>&graph, vector<bool>&visited, stack<int>&s, int v)
{
	visited[v] = true;
	for(int i = 0; i < graph[v].size(); i++)
	{
		if(!visited[graph[v][i]])
		{
			TopoSort(graph, visited, s, graph[v][i]);
		}
	}
	s.push(v);
}
void DFS(vector<vector<int>>&Tgraph, vector<bool>&visited, int v)
{
	cout << v << " ";
	visited[v] = true;
	for(int i = 0; i < Tgraph[v].size(); i++)
	{
		if(!visited[Tgraph[v][i]]) DFS(Tgraph, visited, Tgraph[v][i]);
	}
}
void Kosaraju(vector<vector<int>>&graph)
{
	stack<int>s;
	vector<bool>visited(graph.size(), false);
	for(int i = 1; i < graph.size(); i++)
	{
		if(!visited[i]) TopoSort(graph, visited, s, i);
	}
	vector<vector<int>>Tgraph(graph.size(), vector<int>());
	for(int i = 1; i < graph.size(); i++)
	{
		for(int j = 0; j < graph[i].size(); j++)
		{
			addEdge(Tgraph, graph[i][j], i);
		}
	}
	for(int i = 0; i < graph.size(); i++) visited[i] = false;
	while(!s.empty())
	{
		int start = s.top();
		if(!visited[start]) {DFS(Tgraph, visited, start); cout << endl;}
		s.pop();
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
		vector< vector<int> > graph(n+1, vector<int>());
		cin >> n;
		for(int i = 0; i < n; i++)
		{
			int x, y;
			cin >> x >> y;
			addEdge(graph, x, y);
		}
		Kosaraju(graph);
		//if(t != 0) cout << endl;
	}
 	return 0;
}