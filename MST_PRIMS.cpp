#include<iostream>
#include<list>
using namespace std;

//class for a node
class Node{
	public:
		Node();
		list<int> adj_list,wt;    //adj list to store adjacent vertices and wt for storing weight of the edge
		int parent;               //parent of the node
		int key;				 //key of the node
		int node_num,index;    //index will keep track of position of the node in Q.
};

//defining constructor
Node :: Node(){
	parent = -1;          //initializing parent with -1 for all nodes
	key = INT16_MAX;      //initializing key with max int for all nodes
}

class Graph{
      
	private:
	    Node *n;                //pointer to the object of node class  
		int *Q;
		int V,edges,heap_size,size,num_node,cost;     //int variables
		int *visited;           //pointer to an array
	public:
	   	int src;
		Graph();                       //constructor
		void inputEdges();             //to take graph input from user 
		void addEdge(int u,int v);     //to add edge to the graph
		void addWeight(int u,int w);   //to add weight of each edge
		void MST_PRIM(int r);          //MST_PRIM algorithm
       	void MIN_HEAPIFY(int *Q,int i); //for sorting 
		int EXTRACT_MIN(int *Q);        //to find node with minimum key
		bool is_in_Q(int *Q,int nd);    //to check whether nd is in Q or not
		void displayMST(int src);        //to display MST
		bool is_visited(int n,int indx);  //keep track of the eliminated nodes
		void MIN_HEAP_INSERT(int *Q,int key);    //insert node in min-heap
		void HEAP_DECREASE_KEY(int *Q,int i,int key); //to place node at the right position whose key value is decreased
};

//defining constructor
Graph :: Graph(){
	//taking num of vertices form user
	cout<<"\nEnter number of vertices : ";
    cin>>V;

    //declating/initializing arrays and variables
    n = new Node [V];
	Q = new int[V];
	size = V;
	num_node = 0;
	cost = 0;

	for(int i=0;i<V;i++){
		n[i].node_num = i;
		Q[i] = i;
		n[i].index = i;
	}

	visited = new int[V];
	heap_size = -1;
}

//defining addEdge() : it will add an edge to node[u] {edge 0---1}
void Graph :: addEdge(int u,int v){
	n[u].adj_list.push_back(v);
}

//defining addWeight() : it will add weight to edge(0---weight)
void Graph :: addWeight(int u,int w){
	n[u].wt.push_back(w);
}

//defining inputEdges() : it will take undirected graph from user 
void Graph :: inputEdges(){
	int edges;	
	cout<<"\nEnter number of edges in the graph : ";
	cin>>edges;
    cout<<endl;
	int v,u,wght;


	for(int i=0;i<edges;i++){
		cout<<"\nEnter vertices of edge "<<i+1<<" : ";
		cin>>u>>v; 
		addEdge(u,v);            //adding both edge 0---1 and 1---0
		addEdge(v,u);            //because graph is undirected

        cout<<"Enter weight of edge ("<<u<<","<<v<<") : ";
        cin>>wght;
        addWeight(u,wght);   //adding weight of each edge 0---1
		addWeight(v,wght);   // and 1---0
	}

	//take source node form user
	cout<<"\nEnter source node : ";
	cin>>src;
}

// //functions used by heapsort to find left and right child of a node
int LEFT(int i){
	return (2*i + 1);
}

int RIGHT(int i){
    return (2*i + 2);
}

int PARENT(int i){
	return (i-1)/2;
}

void Graph :: MIN_HEAPIFY(int *Q,int i){
   
    int smallest,l,r;
    l = LEFT(i);
    r = RIGHT(i);

   if (l <=heap_size){
        if(n[Q[l]].key <n[Q[i]].key)
            smallest = l;  
        else 
            smallest = i;     
    }
    else smallest = i;

    if (r <= heap_size){   
        if(n[Q[r]].key<n[Q[smallest]].key)
            smallest = r;
    }
    
    if (smallest != i){
        int temp;

        temp = Q[i];
        Q[i] = Q[smallest];
		n[Q[smallest]].index = i;
        Q[smallest] = temp;
		n[temp].index = smallest;

        MIN_HEAPIFY(Q,smallest);
    }   
}

//defining EXTRACT_MIN() : it will return node with minimum key
int Graph :: EXTRACT_MIN(int *Q){

	int min;
	min = Q[0];        //extracting minimum node from heap
	cost += n[min].key; 

    Q[0] = Q[heap_size];
	n[Q[heap_size]].index = 0;
	heap_size--;
	MIN_HEAPIFY(Q,0);
 return min;	
}

//defining is_in_Q : check whether a node nd is in A or not
bool Graph :: is_in_Q(int *Q,int nd){

	bool flag = false;
	
	for(int i=0;i<=heap_size;i++){
		if(n[Q[i]].node_num==nd){
			flag = true;       //if yes true
		}
	}
 return flag;	 //otherwise false
}

void Graph :: MIN_HEAP_INSERT(int *Q,int key){
	heap_size = heap_size + 1;
	n[Q[heap_size]].key = INT16_MAX;
	HEAP_DECREASE_KEY(Q,heap_size,key);
}

void Graph :: HEAP_DECREASE_KEY(int *Q,int i,int key){
	int temp,parent_indx,child_indx;

	if(key<n[Q[i]].key){
		n[Q[i]].key = key;
		while(i>0 && n[Q[PARENT(i)]].key>n[Q[i]].key){
			int p = PARENT(i);
			temp = Q[p];
			parent_indx = n[temp].index;
			child_indx = n[Q[i]].index;
			Q[p] = Q[i];

			n[Q[i]].index = parent_indx;

			Q[i] = temp;
			n[temp].index = child_indx;

			i = PARENT(i);
		}
	}
}

//MST_PRIM algorithm
void Graph :: MST_PRIM(int r){

	int u,j;
    list<int>::iterator itr,edge_wt;

	for(int i=0;i<V;i++){
		if(i==r)
			MIN_HEAP_INSERT(Q,0);
		else			
			MIN_HEAP_INSERT(Q,INT16_MAX);   
	}

	while(heap_size>=0){
		
		u = EXTRACT_MIN(Q);
	
		for(itr = n[u].adj_list.begin(),edge_wt = n[u].wt.begin();itr!=n[u].adj_list.end(),edge_wt != n[u].wt.end();itr++,edge_wt++){

			if(is_in_Q(Q,*itr) && *edge_wt <n[*itr].key){
				n[*itr].parent = n[u].node_num;
				HEAP_DECREASE_KEY(Q,n[*itr].index,*edge_wt);
			}
		}
	}
}

//(For Displaying MST)check whether node n is eleminated/visited or not
bool Graph :: is_visited(int n,int indx){
	for(int i=0;i<indx;i++){
		if(visited[i]==n)
			return true;		
	}
	visited[indx] = n; //if not visited
 return false;
}

//display MST
void Graph :: displayMST(int src){

	list<int>::iterator i,k;

	for(int j=0;j<V;j++){
		
		if(j!=src && !is_visited(n[j].parent,j)){
			
			cout<<"\nPARENT NODE :: "<<n[j].parent;
			cout<<"\nCHILD NODE : ";
		    for(int l=0;l<V;l++){
				if(n[l].parent == n[j].parent)
					cout<<l<<", ";
			}
			cout<<endl;
		}	
	}
	cout<<"\nSPANNING TREE COST :: "<<cost<<endl;
}

int main()
{
	//Variable declaration
	Graph g;   //object of Graph

	//to take graph input from user
	g.inputEdges();

	cout<<"\n--------------------IMPLEMENTING PRIM'S ALGORITHM---------------------\n";

	g.MST_PRIM(g.src);

    //displaying MST
	g.displayMST(g.src);
  
 return 0;
}