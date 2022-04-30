//IMPLEMENTATION OF HEAP SORT

#include<iostream>
using namespace std;

template <class T>
class Heap{

    private:
        int size;
        int comp_count;
        int heap_size;

    public:
        T *A;
        Heap();
        void HeapSort(T *A);
        void insert_elem();
        void MAX_HEAPIFY(int i);
        void BUILD_MAX_HEAP();
        void display();     
        int LEFT(int i);
        int RIGHT(int i);
        int comparisons();
};

template <class T>
Heap<T> :: Heap(){
    cout<<"\nEnter size of the array : ";
    cin>>size;

    if(size<=0){
        cout<<"\nError: Size of array should be greater than 0.";
        exit(0);
    }

    A = new T[size];
    comp_count = 0;
}

template <class T>
void Heap<T> :: insert_elem(){
    cout<<"\nEnter "<<size<<" elements in the array : ";
    for (int  i =0;i<size;i++)
        cin>>A[i];
}

template <class T>
void Heap<T> :: display(){

    cout<<"[";
    for (int i =0;i<size;i++)
        cout<<A[i]<<" ";
    cout<<"]\n";    
}

template <class T>
int Heap<T> :: LEFT(int i){
    return (2*i + 1);
}

template <class T>
int Heap<T> :: RIGHT(int i){
    return (2*i + 2);
}

template <class T>
void Heap<T> :: MAX_HEAPIFY(int i){
   
    int largest,l,r;
    
    l = LEFT(i);
    r = RIGHT(i);
    if (l <=heap_size){
        comp_count++;
        if( A[l] > A[i])
            largest = l;  
        else 
            largest = i;     
    }
    else largest = i;

    if (r <= heap_size){
        comp_count++;     
        if(A[r]>A[largest])
            largest = r;
    }
    
    if (largest != i){
        T temp;

        temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;

        MAX_HEAPIFY(largest);
    }   
}

template <class T>
void Heap<T> :: BUILD_MAX_HEAP(){
    heap_size = size-1;
    for(int i=(size/2)-1;i>=0;i--)
        MAX_HEAPIFY(i);
}

template <class T>
void Heap<T> :: HeapSort(T *A){
   
    BUILD_MAX_HEAP();
    for(int i=size-1;i>=1;i--){
        T tmp;
        tmp = A[0];
        A[0] = A[i];
        A[i] = tmp;
        
        heap_size = heap_size-1;
        MAX_HEAPIFY(0);
    }
}

template <class T>
int Heap<T> :: comparisons(){
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
                Heap<int> h;

                h.insert_elem();

                cout<<"\nEntered Array : ";
                h.display();

                cout<<"\n----------IMPLEMENTING HEAP SORT-----------\n";
                h.HeapSort(h.A);
                
                cout<<"\nFinal Sorted Array :: ";
                h.display();

                cout<<"Total Number of comparisons : "<<h.comparisons()<<endl;
                break;
        }
        case 'b':{
                Heap<float> h;

                h.insert_elem();

                cout<<"\nEntered Array : ";
                h.display();

                cout<<"\n----------IMPLEMENTING HEAP SORT-----------\n";
                h.HeapSort(h.A);
                
                cout<<"\nFinal Sorted Array :: ";
                h.display();

                cout<<"Total Number of comparisons : "<<h.comparisons()<<endl;
                break;
        }
        case 'c':{
                Heap<char> h;

                h.insert_elem();

                cout<<"\nEntered Array : ";
                h.display();

                cout<<"\n----------IMPLEMENTING HEAP SORT-----------\n";
                h.HeapSort(h.A);
                
                cout<<"\nFinal Sorted Array :: ";
                h.display();

                cout<<"Total Number of comparisons : "<<h.comparisons()<<endl;
                break;
        }                
        default:{
                cout<<"\nInvalid input!!!";
        }    
    }    
 return 0;
}