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
};

//defining constructor
Node :: Node(){
	parent = -1;          //initializing parent with -1 for all nodes
	key = INT16_MAX;      //initializing key with max int for all nodes
}

class Graph{
      
	private:
	    Node *n;                //pointer to the object of node class  
		int V,edges,heap_size,size,num_node,cost;     //int variables
		int *Q;                 //pointer to an array that store nodes in sorted order acc. their keys
		int *visited;           //pointer to an array
        
	public:
		Graph();                       //constructor
		void inputEdges();             //to take graph input from user 
		void addEdge(int u,int v);     //to add edge to the graph
		void addWeight(int u,int w);   //to add weight of each edge
		void MST_PRIM(int r);          //MST_PRIM algorithm
		void HeapSort(int *A);			//heapsort algorithm
        void MAX_HEAPIFY(int *A,int i); //for sorting
        void BUILD_MAX_HEAP(int *A);    //for sorting  
		int EXTRACT_MIN(int *A);        //to find node with minimum key
		bool is_in_Q(int *A,int nd);    //to check whether nd is in Q or not
		void displayMST(int src);        //to display MST
		bool is_visited(int n,int indx);  //keep track of the eleminated nodes
};

//defining constructor
Graph :: Graph(){
	//taking num of vertices form user
	cout<<"\nEnter number of vertices : ";
    cin>>V;

    //declating/initializing arrays and variables
    n = new Node [V];
	size = V;
	num_node = 0;
	cost = 0;
	Q = new int[V];
	visited = new int[V];
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
}

//functions used by heapsort to find left and right child of a node
int LEFT(int i){
    return (2*i + 1);
}

int RIGHT(int i){
    return (2*i + 2);
}

void Graph :: MAX_HEAPIFY(int *A,int i){
   
    int largest,l,r;
    
    l = LEFT(i);
    r = RIGHT(i);
    if (l <=heap_size){
        if( n[A[l]].key > n[A[i]].key)
            largest = l;  
        else 
            largest = i;     
    }
    else largest = i;

    if (r <= heap_size){   
        if(n[A[r]].key>n[A[largest]].key)
            largest = r;
    }
    
    if (largest != i){
        int temp;

        temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;

        MAX_HEAPIFY(A,largest);
    }   
}

void Graph :: BUILD_MAX_HEAP(int *A){
    heap_size = size-1;
    for(int i=(size/2)-1;i>=0;i--)
        MAX_HEAPIFY(A,i);
}

void Graph :: HeapSort(int *A){
   
    BUILD_MAX_HEAP(A);
    for(int i=size-1;i>=1;i--){
        int tmp;
        tmp = A[0];
        A[0] = A[i];
        A[i] = tmp;
        
        heap_size = heap_size-1;
        MAX_HEAPIFY(A,0);
    }
}


//defining EXTRACT_MIN() : it will return node with minimum key
int Graph :: EXTRACT_MIN(int *A){

	int nd = A[num_node];
	num_node++;          //keep track of num_node eleminated from A
 return nd;	
}

//defining is_in_Q : check whether a node nd is in A or not
bool Graph :: is_in_Q(int *A,int nd){
	bool flag = false;
	for(int i=num_node;i<V;i++){
		if(A[i]==nd){
			flag = true;       //if yes true
		}
	}
 return flag;	 //otherwise false
}

//MST_PRIM algorithm
void Graph :: MST_PRIM(int r){

	int u;
    list<int>::iterator itr,edge_wt;

	n[r].key = 0;
	for(int i=0;i<V;i++){
		Q[i] = i;
	}

	while(num_node<V){
		HeapSort(Q);          
		u = EXTRACT_MIN(Q);
		cost += n[u].key;
        n[u].key = -1;

		for(itr = n[u].adj_list.begin(),edge_wt = n[u].wt.begin();itr!=n[u].adj_list.end(),edge_wt != n[u].wt.end();itr++,edge_wt++){
			if(is_in_Q(Q,*itr) && *edge_wt <n[*itr].key){
				n[*itr].parent = u;
				n[*itr].key = *edge_wt;
			}
		}

	}
}

//check whether node n is eleminated/visited or not
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
	// bool flag;

    cout<<"\n+---------------MINIMUM COST SPANNING TREE--------------------+\n";
	cout<<"\nSOURCE NODE PARENT :: NULL"<<"\nSOURCE NODE : "<<src<<endl;
    
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
	int src;

	//to take graph input from user
	g.inputEdges();

	//take source node form user
	cout<<"\nEnter source node : ";
	cin>>src;

	cout<<"\n--------------------IMPLEMENTING PRIM'S ALGORITHM---------------------\n";

	g.MST_PRIM(src);

    //displaying MST
	g.displayMST(src);
  
 return 0;
}