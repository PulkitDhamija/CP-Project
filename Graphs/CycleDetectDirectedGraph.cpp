#include "bits/stdc++.h"
using namespace std;
// Graphs
void addEdge(vector< vector<int> >&graph, int x, int y)
{
	graph[x].push_back(y);
	//graph[y].push_back(x);
}
// Directed Graph Cycle Detection DFS
bool iTCDFS(vector<vector<int>>&graph, vector<bool>&visited, vector<bool>&dfsvisit, int start, int parent)
{
	visited[start]  = true;
	dfsvisit[start] = true;
	for(int i = 0; i < graph[start].size(); i++)
	{
		if(!visited[graph[start][i]])
		{
			if(iTCDFS(graph, visited, dfsvisit, graph[start][i], start)) return true;
		}
		else
		{
			if(dfsvisit[graph[start][i]]) return true;
		}
	}
	dfsvisit[start] = false;
	return false;
}
bool isThereCycleDFS(vector<vector<int>>&graph)
{
	vector<bool>visited(graph.size(), false);
	vector<bool>dfsvisit(graph.size(), false);
	for(int i = 0; i < graph.size(); i++)
	{
		if(iTCDFS(graph, visited, dfsvisit, i, -1)) return true;
	}
	return false;
}
// Directed Graph Cycle Detection BFS (kahn's Algo)
vector<int> Topo2Sort(vector<vector<int>>&graph)
{
	vector<int>deg(graph.size(), 0);
	vector<int>ans;
	for(int i = 0; i < graph.size(); i++)
	{
		for(int j = 0; j < graph[i].size(); j++)
		{
			deg[graph[i][j]]++;
		}
	}
	queue<int>q;
	for(int i = deg.size()-1; i >= 0; i--)
	{
		if(deg[i] == 0) q.push(i);
	}
	while(!q.empty())
	{
		int temp = q.front();
		q.pop();
		for(int i = 0; i < graph[temp].size(); i++)
		{
			deg[graph[temp][i]]--;
			if(!deg[graph[temp][i]]) q.push(graph[temp][i]);
		}
		ans.push_back(temp);
	}
	return ans;
}
bool isThereCycleBFS(vector<vector<int>>&graph)
{
	vector<int> ans = Topo2Sort(graph);
	if(ans.size() == graph.size()) return false;
	else return true;
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector< vector<int> > graph(n, vector<int>());
		cin >> n;
		for(int i = 0; i < n; i++)
		{
			int x, y;
			cin >> x >> y;
			addEdge(graph, x, y);
		}
		cout << isThereCycleDFS(graph) << endl;
		cout << isThereCycleBFS(graph) << endl;
		if(t != 0) cout << endl;
	}
 	return 0;
}