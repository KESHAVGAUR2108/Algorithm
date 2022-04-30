//IMPLEMENTATION OF INSERTION SORT

#include<iostream>
using namespace std;

template <class T>
class Array{

    private:
        T *A;
        int size;
        int comp_count;
    public:
        Array();
        void insert_elem();
        void insertion_sort();
        void display();
        int comparisons();
};

template <class T>
Array<T> :: Array(){
    
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
void Array<T> :: insert_elem(){
 
    cout<<"\nEnter "<<size<<" elements in the array : ";
    for(int i=0;i<size;i++)
        cin>>A[i];
}    
    
template <class T>
void Array<T> :: insertion_sort(){
    
    int i,j;
    T key;

    for(j = 1;j<size;j++){
        key = A[j];
    // Insert A(j into the sorted sequence A[1...j -1].
        i = j - 1;
        while(i>=0){
            comp_count++;     //keep track of number of comparisons
            if( A[i] > key){
                A[i+1] = A[i];    //shifting element
                i--;
            }
            else
               break;
        }    
        A[i+1] = key;     //placing element to its correct position
    }
}

template <class T>
void Array<T> :: display(){

    cout<<"[ ";
    for(int i=0;i<size;i++)
        cout<<A[i]<<" ";
    cout<<"]\n";      
}    

template <class T>
int Array<T> :: comparisons(){
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
                Array<int> a;

                a.insert_elem();
                
                cout<<"\nEntered array : ";
                a.display();

                cout<<"\n----------IMPLEMENTING INSERTION SORT-----------\n";
                a.insertion_sort();

                cout<<"\nFinal Sorted array : ";
                a.display();
            
                cout<<"Total number of comparisons : "<<a.comparisons();
                break;
            }
        case 'b':{
                Array<float> a;

                a.insert_elem();
                
                cout<<"\nEntered array : ";
                a.display();

                cout<<"\n----------IMPLEMENTING INSERTION SORT-----------\n";
                a.insertion_sort();

                cout<<"\nFinal Sorted array : ";
                a.display();
            
                cout<<"Total number of comparisons : "<<a.comparisons();
                break;
        }
        case 'c':{
                Array<char> a;

                a.insert_elem();
                
                cout<<"\nEntered array : ";
                a.display();

                cout<<"\n----------IMPLEMENTING INSERTION SORT-----------\n";
                a.insertion_sort();

                cout<<"\nFinal Sorted array : ";
                a.display();
            
                cout<<"Total number of comparisons : "<<a.comparisons();
                break;
        }                
        default:{
                cout<<"\nInvalid input!!!";
        }    
    }    
 return 0;   
}