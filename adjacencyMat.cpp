#include<bits/stdc++.h>
using namespace std;

struct graph{
	int **mat;
	int v;
	graph(int v)
	{
		this->v = v;
		mat = new int*[v];
		for(int i=0; i<v; i++)
			mat[i] = new int[v]{0};
	}
	void show()
	{
		for(int i=0; i<v; i++)
		{
			for(int j=0; j<v; j++)
				cout<<mat[i][j]<<" ";
			cout<<endl;
		}		
	}
	void edge(int s, int e)
	{
		mat[s][e] = 1;
		mat[e][s] = 1;
	}
};

main()
{
	cout<<"Enetr the number of vertex : ";
	int v;
	cin>>v;
	graph g1(v);
	cout<<"\nEnter the number of edges : ";
	int e;
	cin>>e;
	for(int i=0; i<e; i++)
	{
		int s,e;
		cout<<"Enter starting vertex : ";
		cin>>s;
		cout<<"Enter ending vertex : ";
		cin>>e;
		g1.edge(s,e);
	}
	g1.show();
}
