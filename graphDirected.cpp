#include<bits/stdc++.h>
using namespace std;

struct graphD
{
	int v;
	vector<vector<int>> adj;
	bool *visited;
	int *inDegree;
	
	graphD(int x)
	{
		v=x;
		adj.resize(v);
		visited = new bool[v]{false};
		inDegree = new int[v]{0};
	}
	
	void edge(int s, int e)
	{
		adj[s].push_back(e);
		inDegree[e]++;
	}
	
	void show()
	{
		for(int i=0; i<v; i++)
		{
			cout<<i;
			for(int j=0; j<adj[i].size(); j++)
			{
				cout<<"->"<<adj[i][j];
			}
			cout<<endl;
		}	
	}
	
	void ta()
	{
		for(int i=0; i<v; i++)
			visited[i]=false;
	}
	
	bool isCyclicrec(int s, bool *recSt)
	{
		visited[s]=true;
		recSt[s]=true;
		for(int u : adj[s])
		{
			if(!visited[u] && isCyclicrec(u, recSt))
				return true;
			else if(recSt[u])
				return true;
		}
		recSt[s]=false;
		return false;
	}
	bool isCyclic(int s)
	{
		bool recSt[v]{false};
		if(isCyclicrec(s, recSt))
		{
			ta();
			return true;
		}
		for(int i=0; i<v; i++)
		{
			if(!visited[i] && isCyclicrec(i, recSt))
			{
				ta();
				return true;
			}
		}
		ta();
		return false;
	}
	
	void ptTopologicalOrder()
	{
		queue<int> q;
		for(int i=0; i<v; i++)
		{
			if(inDegree[i]==0)
				q.push(i);
		}
		
		while(!q.empty())
		{
			int u = q.front();
			cout<<u<<" ";
			q.pop();
			for(int t : adj[u])
			{
				inDegree[t]--;
				if(inDegree[t]==0)
					q.push(t);
			}
		}
	}
};

main()
{
	cout<<"Enter the number of vertex : ";
	int v;
	cin>>v;
	graphD g1(v);
	cout<<"Enter the number of edges : ";
	int e;
	cin>>e;
	while(e--)
	{
		int s,e;
		cout<<"Enter the starting vertex : ";
		cin>>s;
		cout<<"Enter the ending edge : ";
		cin>>e;
		g1.edge(s,e);
	}
	g1.show();
	if(g1.isCyclic(0))
		cout<<"Cyclic";
	else
		cout<<"Not Cyclic";
	cout<<endl;
	g1.ptTopologicalOrder();
}
