//IMPLEMENTATION OF BFS

#include <iostream>
#include <list>
#include <stack>
using namespace std;

template <class T>
class Graph{
      
	private:
		int V;
	        list<T> *ls;
        public:
		Graph();
                void addEdge(int v,int u);
		void inputEdges();
		void DFS(int source);
};

template <class T>
Graph<T> :: Graph(){
   cout<<"Enter number of vertices : ";
   cin>>V;
   ls = new list<T>[V];
}

template <class T>
void Graph<T> :: addEdge(int v,int u){
	    ls[v].push_back(u);
}

template <class T>
void Graph<T> :: inputEdges(){
	int edges;	
	cout<<"\nEnter number of edges in the graph : ";
	cin>>edges;

	int v,u;

	for(int i=0;i<edges;i++){
		cout<<"Enter vertices of edge "<<i+1<<" : ";
		cin>>v>>u;
		addEdge(v,u);
	}
}

template <class T>
void Graph<T> :: DFS(int s){

    stack<T> stck;
    
    bool *Explored = new bool[V];
    for(int i = 0; i < V; i++)
        Explored[i] = false;

    list<int>::iterator i;

    stck.push(s);
    
    while (stck.empty() !=1){
       T node = stck.top();
       
       stck.pop();
       if (Explored[node] == false){
           Explored[node] = true;
           cout<<"\nParent : "<<node;
           cout<<"\nChild : ";
           
           for (i = ls[node].begin(); i != ls[node].end(); ++i)
           {
               if (!Explored[*i])
                    cout<<*i<<" , ";
                stck.push(*i);
           }
           cout<<endl;
        }
    }
}
int main()
{
	Graph<int> g;
	int src;	

	g.inputEdges();
	
	cout<<"\nEnter source vertex :: ";
	cin>>src; 

	g.DFS(src); 
return 0;
}
