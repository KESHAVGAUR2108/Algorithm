//IMPLEMENTATION OF QUICKSORT ALGORITHM

#include<iostream>
#include<stdlib.h>
#include<ctime>
using namespace std;

template <class T>
class QuickSort{

    private:
        int comp_count;

    public:
        QuickSort();
        void insert_elem();
        void display_elem();
        int RANDOMIZED_PARTITION(T arr[],int p,int r);
        void RANDOMIZED_QUICKSORT(T arr[],int p,int r);
        int PARTITION(T arr[],int p,int r);
        int comparisons();
        void exchange(T arr[],int i,int j);
        int size;
        T* A;
};

template <class T>
QuickSort<T> :: QuickSort(){
    
    cout<<"\nEnter size of the array : ";
    cin>>size;
  
    if(size<=0){
        cout<<"\nError: Size of array should be greater than 0.";
        exit(0);
    }

    A = new T[size];
    comp_count =0;
}

template <class T>
void QuickSort<T> :: insert_elem(){

    cout<<"\nEnter "<<size<<" elements in the array : ";
    for (int i=0;i<size;i++)
        cin>>A[i];
}

template <class T>
void QuickSort<T> :: display_elem(){

    cout<<"Array : [";
    for(int i=0;i<size;i++)
        cout<<A[i]<<" ";
    cout<<"]\n";    
}

template <class T>
int QuickSort<T> :: RANDOMIZED_PARTITION(T arr[],int p,int r){
    int i;
    srand(time(NULL));
    i = (rand() % (r - p + 1) + p);
    exchange(arr,r,i);
    return PARTITION(arr,p,r);    
}


template <class T>
void QuickSort<T> :: RANDOMIZED_QUICKSORT(T arr[],int p,int r){

    int q;
    if (p<r){
        q = RANDOMIZED_PARTITION(arr,p,r);
        RANDOMIZED_QUICKSORT(arr,p,q-1);
        RANDOMIZED_QUICKSORT(arr,q+1,r);
    }
}

template <class T>
int QuickSort<T> :: PARTITION(T arr[],int p,int r){

    T pivot = arr[r];
    int i = p-1;

    for (int j=p;j<r;j++){
        
        comp_count++;
        
        if (arr[j]<=pivot){
            i++;
            exchange(arr,i,j);
        }

    } 
    exchange(arr,i+1,r);   
 return i+1;
}

template <class T>
void QuickSort<T> :: exchange(T arr[],int i,int j){

    T temp;
    temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

template <class T>
int QuickSort<T> :: comparisons(){
    return comp_count;
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
                QuickSort<int> q;
                q.insert_elem();

                cout<<"\nEntered ";
                q.display_elem();

                cout<<"\n---------IMPLEMENTING QUICKSORT--------------\n";

                q.RANDOMIZED_QUICKSORT(q.A,0,q.size-1);

                cout<<"\nFinal Sorted "; 
                q.display_elem();

                cout<<"\nTotal number of comparisons : "<<q.comparisons();
                break;
        }
        case 'b':{
                QuickSort<float> q;
                q.insert_elem();

                cout<<"\nEntered ";
                q.display_elem();

                cout<<"\n---------IMPLEMENTING QUICKSORT--------------\n";

                q.RANDOMIZED_QUICKSORT(q.A,0,q.size-1);

                cout<<"\nFinal Sorted "; 
                q.display_elem();

                cout<<"\nTotal number of comparisons : "<<q.comparisons();
                break;
        }
        case 'c':{
                QuickSort<char> q;
                q.insert_elem();

                cout<<"\nEntered ";
                q.display_elem();

                cout<<"\n---------IMPLEMENTING QUICKSORT--------------\n";

                q.RANDOMIZED_QUICKSORT(q.A,0,q.size-1);

                cout<<"\nFinal Sorted "; 
                q.display_elem();

                cout<<"\nTotal number of comparisons : "<<q.comparisons();
                break;
        }                
        default:{
                cout<<"\nInvalid input!!!";
        }    
    }
 return 0;  
}