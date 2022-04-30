//IMPLEMENTATION OF BFS

#include <iostream>
#include <list>
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
		void BFS(int source);
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
void Graph<T> :: BFS(int s){

 bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
 
    // Create a queue for BFS
    list<T> queue;
 
    // Mark the current node as visited and enqueue it
    visited[s] = true;
    queue.push_back(s);
 
    // 'i' will be used to get all adjacent
    // vertices of a vertex
    list<int>::iterator i;
    
    cout<<"\nBFS TRAVERSAL :: ";
	
    while(!queue.empty())
    {
        // Dequeue a vertex from queue and print it
        s = queue.front();
        cout <<"\nPARENT : "<< s << " ";
        queue.pop_front();

 	cout<<" child : ";
        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        for (i = ls[s].begin(); i != ls[s].end(); ++i)
        {
            if (!visited[*i])
            {	cout<<*i<<" , ";
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
    cout<<"\n";
}

int main()
{
	Graph<int> g;
	int src;	

	g.inputEdges();
	
	cout<<"\nEnter source vertex :: ";
	cin>>src; 

	g.BFS(src); 
return 0;
}
