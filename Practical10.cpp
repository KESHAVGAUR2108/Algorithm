//PROGRAM TO SOLVE THE WEIGHTED INTERVAL SCHEDULIING PROBLEM

#include<iostream>
using namespace std;

//CREATED A CLASS
class WeightedIntervalScheduling{

    public:
        int n,heapsize;              //NUMBER OF INTERVALS
        int *Pj;                     //INTERVALS COMPATIBLE TO AN INTERVAL 'I'
        float *startTime,*finishTime,*weight,*M;

        WeightedIntervalScheduling();          //constructor
        void Intervalinput();                 //taking interval input from user
        void MAX_HEAPIFY(float *A,int i);     
        void BUILD_MAX_HEAP(float *A);
        int LEFT(int i);
        int RIGHT(int i);
        void HeapSort(float *A);              //sorting intervals according to finish time
        void calculatePj();                   //calculate P(n) value for each interval
        int Iterative_Compute_Opt(int j);             //Memoized or iterative version of weighting interval scheduling to calculate optimal weight
        float max(int a,int b);               //max flunction to find max of two numbers
        void Find_Solution(int j);            //function to find optimal interval solution
};

//defining constructor
WeightedIntervalScheduling :: WeightedIntervalScheduling(){
    
    //taking no. of intervals from user
    cout<<"\nEnter number of Intervals : ";
    cin>>n;

    //array declaration
    startTime = new float[n+1];
    finishTime = new float[n+1];
    weight = new float[n+1];
    Pj = new int[n+1]; 
    M = new float[n+1];

    heapsize = n+1;

    //initializing first element of the array's
    startTime[0] = 0;
    finishTime[0] = -1; 
    weight[0] = 0;
    Pj[0] = 0;
    Pj[1] = 0;

    for(int i=0;i<=n;i++){
        M[i] = -1;
    }
}

//defining Intervalinput function to take iput form the user
void WeightedIntervalScheduling :: Intervalinput(){

    cout<<"\n+----------------------------------------------------------------+\n";
    cout<<"|             INTERVAL             | Start_T | Finish_T | Weight |\n";
    cout<<"+----------------------------------------------------------------+\n";

    for(int i=1;i<=n;i++){
        cout<<"|          For Interval "<<i<<"          |    ";
        cin>>startTime[i]>>finishTime[i]>>weight[i];
        cout<<"+----------------------------------------------------------------+\n";    
     
        //check whether entered values are greater than 0 
        if(startTime[i]<0 || finishTime[i]<0 || weight[i]<0){
            cout<<"\nError : Invalid input.\nPlease enter positive value only.";
            exit(0);
        }
    }
}

int WeightedIntervalScheduling :: LEFT(int i){
    return (2*i + 1);
}

int WeightedIntervalScheduling :: RIGHT(int i){
    return (2*i + 2);
}

void WeightedIntervalScheduling :: MAX_HEAPIFY(float *A,int i){
   
    int largest,l,r;
    
    l = LEFT(i);
    r = RIGHT(i);
    if (l <=heapsize){
        if( A[l] > A[i])
            largest = l;  
        else 
            largest = i;     
    }
    else largest = i;

    if (r <= heapsize){     
        if(A[r]>A[largest])
            largest = r;
    }
    
    if (largest != i){
        float temp,temp3;

        temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;

        temp3 = startTime[i];
        startTime[i] = startTime[largest];
        startTime[largest] = temp3;

        MAX_HEAPIFY(A,largest);
    }   
}

void WeightedIntervalScheduling :: BUILD_MAX_HEAP(float *A){
    heapsize = n;
    for(int i=(n/2)-1;i>=0;i--)
        MAX_HEAPIFY(A,i);
}

void WeightedIntervalScheduling :: HeapSort(float *A){
   
    BUILD_MAX_HEAP(A);
    for(int i=n;i>=1;i--){
        float tmp;

        tmp = A[0];
        A[0] = A[i];
        A[i] = tmp;

        tmp = startTime[0];
        startTime[0] = startTime[i];
        startTime[i] = tmp;
        
        heapsize = heapsize-1;
        MAX_HEAPIFY(A,0);
    }
}

void WeightedIntervalScheduling :: calculatePj(){
    
    /*
    find number of intervals compatible to an interval 'i'
    */

    int count;
    for(int i=2;i<=n;i++){
        count=0;
        for(int j=1;j<i;j++){
            if(finishTime[j]<=startTime[i])
                count++;
        }
        Pj[i] = count;
    }
}

//function to compute optimal value 
int WeightedIntervalScheduling :: Iterative_Compute_Opt(int j){
   
    M[0] = 0;

    for(int j = 1;j<=n;j++){
        M[j] = max(weight[j]+M[Pj[j]],M[j-1]);
    }
    return M[n]; 
}

float WeightedIntervalScheduling :: max(int a,int b){
    if(a>=b){
        return a;
    }
    return b;
}

//function to find optimal solution
void WeightedIntervalScheduling :: Find_Solution(int j){
    if(j==0){
        return;
    }
    else{
        if(weight[j] + M[Pj[j]] >= M[j-1]){
            cout<<j<<" ";           //display the selected interval
            Find_Solution(Pj[j]);
        }        
        else{
            Find_Solution(j-1);
        }
    }
}

int main(){

    //decalaration of object
    WeightedIntervalScheduling W;
 
    //input from user
    W.Intervalinput();

    //sort the entered intervals according to finish time
    W.HeapSort(W.finishTime);

    //calculate P(n) value for each interval
    W.calculatePj();

    //compute total optimal wieght
    //display total optimal value and selected intervals
    cout<<"\nOptimal solution value = "<<W.Iterative_Compute_Opt(1)<<endl;   
    cout<<"\nOptimal Intervals : ";
    W.Find_Solution(W.n); 

 return 0;   
}

