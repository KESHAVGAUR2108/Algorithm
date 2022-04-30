//PROGRAM TO SOLVE THE 0-1 KNAPSACK PROBLEM 

#include<iostream>
using namespace std;

//created a class
class KnapSack{

    public:
        //Variable declaration
        int n,W;   
        int **M;
        int *w;

        KnapSack();                     //constructor
        int Subset_Sum(int n,int W);    //function to find all subset problems value and optimal solution value
        int max(int a,int b);           //to find max of two numbers
};

//defining constructor
KnapSack :: KnapSack(){

    //no. of item input from user
    cout<<"\nEnter number of items : ";
    cin>>n;

    //array declaration
    w = new int[n]; 

    //taking weight of each item from user
    cout<<"\n";
    for(int i=1;i<=n;i++){
        cout<<"Enter weight of item "<<i<<" : ";
        cin>>w[i];
    }

    //taking weight bound from user
    cout<<"\nEnter maximum weight : ";
    cin>>W;

    //2D array declaration
    M = new int*[n+1];
    for(int i=0;i<=n;i++)
        M[i] = new int[W+1];
}

//defining Subset_Sum function
int KnapSack :: Subset_Sum(int n,int W){
    
    for(int j=0;j<=W;j++){
        M[0][j] = 0;
    }

    for(int i=1;i<=n;i++){
        for(int j=0;j<=W;j++){
            if(j<w[i]){
                M[i][j] = M[i-1][j];
            }
            else{
                M[i][j] = max(M[i-1][j],w[i]+M[i-1][j-w[i]]);
            }
        }
    }
 return M[n][W];
}

//defining max function
int KnapSack :: max(int a,int b){
    
    //return greater element
    if(a>=b){
        return a;
    }
    return b;
}

int main()
{
    //object declaration
    KnapSack K;

    //call to Subset_Sum function
    K.Subset_Sum(K.n,K.W);

    //display output
    cout<<"\nSample instance of the Subset-Sum problem :: \n";
    for(int i=K.n;i>=0;i--){
        for(int j=0;j<=K.W;j++){
            cout<<K.M[i][j]<<" ";
        }
        cout<<endl;
    }
    
    cout<<"\nOptimal solution value : "<<K.M[K.n][K.W];

 return 0;   
}