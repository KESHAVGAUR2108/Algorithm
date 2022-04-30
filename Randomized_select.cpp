//IMPLEMENTATION OF Randomized-Select ALGORITHM

#include<iostream>
#include<stdlib.h>
#include<ctime>
using namespace std;

template <class T>
class R_Select{

    public:
        R_Select();
        void insert_elem();
        void display_elem();
        int RANDOMIZED_PARTITION(T arr[],int p,int r);
        T RANDOMIZED_SELECT(T arr[],int p,int r,int i);
        int PARTITION(T arr[],int p,int r);
        void exchange(T arr[],int i,int j);
        int size,i;
        T* A;
};

template <class T>
R_Select<T> :: R_Select(){
    
    cout<<"\nEnter size of the array : ";
    cin>>size;
  
    if(size<=0){
        cout<<"\nError: Size of array should be greater than 0.";
        exit(0);
    }

    A = new T[size];
}

template <class T>
void R_Select<T> :: insert_elem(){

    cout<<"\nEnter "<<size<<" elements in the array : ";
    for (int i=0;i<size;i++)
        cin>>A[i];

    cout<<"\nEnter rank of the element(i) : ";  
    cin>>i;  
    if(i<0 || i>size){
        cout<<"\nError :: INVALID!! VALUE FOR 'i'\n";
        exit(0);
    }
}

template <class T>
void R_Select<T> :: display_elem(){

    cout<<"Array : [";
    for(int i=0;i<size;i++)
        cout<<A[i]<<" ";
    cout<<"]\n";    
}

template <class T>
int R_Select<T> :: RANDOMIZED_PARTITION(T arr[],int p,int r){
    int i;
    srand(time(NULL));
    i = (rand() % (r - p + 1) + p);
    exchange(arr,r,i);
    return PARTITION(arr,p,r);    
}


template <class T>
T R_Select<T> :: RANDOMIZED_SELECT(T arr[],int p,int r,int i){

    int q,k;
    if (p==r){
        return A[p];
    }
    q = RANDOMIZED_PARTITION(arr,p,r);
    k = q-p+1;
    if (i==k)
        return A[q];
    else if(i<k){
        return RANDOMIZED_SELECT(arr,p,q-1,i);
    } 
    else{
        return RANDOMIZED_SELECT(arr,q+1,r,i-k);
    }
}

template <class T>
int R_Select<T> :: PARTITION(T arr[],int p,int r){

    T pivot = arr[r];
    int i = p-1;

    for (int j=p;j<r;j++){
        
        if (arr[j]<=pivot){
            i++;
            exchange(arr,i,j);
        }

    } 
    exchange(arr,i+1,r);   
 return i+1;
}

template <class T>
void R_Select<T> :: exchange(T arr[],int i,int j){

    T temp;
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void menu(){

    cout<<"\n-----------MENU-----------\n";
    cout<<"(a) For Integer.\n";
    cout<<"(b) For Float.\n";
    cout<<"(c) For Char.\n";
    cout<<"Enter your choice : ";
}

int main()
{
    char choice;

    menu();
    cin>>choice;

    switch(choice){
        case 'a':{
                R_Select<int> q;
                int elem;
                q.insert_elem();

                cout<<"\nEntered ";
                q.display_elem();

                cout<<"\n---------IMPLEMENTING RANDOMIZED_SELECT--------------\n";

                elem = q.RANDOMIZED_SELECT(q.A,0,q.size-1,q.i);

                cout<<"\n"<<q.i<<"th smallest element in the array : "<<elem<<endl; 
                q.display_elem();
                break;
        }
        case 'b':{
                R_Select<float> q;
                float elem;
                q.insert_elem();

                cout<<"\nEntered ";
                q.display_elem();

                cout<<"\n---------IMPLEMENTING RANDOMIZED_SELECT--------------\n";

                elem = q.RANDOMIZED_SELECT(q.A,0,q.size-1,q.i);

                cout<<"\n"<<q.i<<"th smallest element in the array : "<<elem<<endl;  
                q.display_elem();

                break;
        }
        case 'c':{
                R_Select<char> q;
                char elem;
                q.insert_elem();

                cout<<"\nEntered ";
                q.display_elem();

                cout<<"\n---------IMPLEMENTING RANDOMIZED_SELECT--------------\n";

                elem = q.RANDOMIZED_SELECT(q.A,0,q.size-1,q.i);

                cout<<"\n"<<q.i<<"th smallest element in the array : "<<elem<<endl; 
                q.display_elem();

                break;
        }                
        default:{
                cout<<"\nInvalid input!!!";
        }    
    }
 return 0;  
}