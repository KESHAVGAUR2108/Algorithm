//IMPLEMENTATION OF MERGE SORT

#include<iostream>
using namespace std;

template <class T>
class MergeSortClass{

    private:
        int count_comp;
        T* A;

    public:
        int size;
        MergeSortClass();
        void input_elem();
        void display_elem();
        void Merge(int l,int mid,int r);
        void Merge_sort(int l,int r);
        int comparisons();
};

template <class T>
MergeSortClass<T> :: MergeSortClass(){
    
    cout<<"\nEnter array size : ";
    cin>>size;

    if(size<=0){
        cout<<"\nError: Size of array should be greater than 0.";
        exit(0);
    }

    A = new T[size];
    count_comp=0;
}

template <class T>
void MergeSortClass<T> :: input_elem(){

    cout<<"\nEnter "<<size<<" elements in the array : ";
    for(int i=0;i<size;i++)
        cin>>A[i];
}

template <class T>
void MergeSortClass<T> :: display_elem(){

    cout<<"Array : [";
    for(int i=0;i<size;i++)
        cout<<A[i]<<" ";
    cout<<"]\n";    
}

template <class T>
void MergeSortClass<T> :: Merge(int l,int mid,int r){

    int n1,n2;

    n1 = mid-l+1;
    n2 = r - mid;

    int L[n1+1],R[n2+1];
   
    for(int i=0;i<n1;i++){
        L[i] = A[l+i];
    }
    for(int j=0;j<n2;j++){
        R[j] = A[mid+j+1];
    }

    L[n1] = INT32_MAX;
    R[n2] = INT32_MAX;
    
    int i,j;
    i=0;j=0;
    
    for(int k=l;k<=r;k++){
        
        count_comp++;
        if (L[i]<=R[j])
        {
            A[k] = L[i];
            i++;
        }
        else{
            A[k] = R[j];
            j++;
        }
    }    
}

template <class T>
void MergeSortClass<T> :: Merge_sort(int l,int r){
    
    int mid;

    if (l<r){
        mid = (l+r)/2;
        Merge_sort(l,mid);
        Merge_sort(mid+1,r);

        Merge(l,mid,r);
    }
}

template <class T>
int MergeSortClass<T> :: comparisons(){
    return count_comp;
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
                MergeSortClass<int> m;

                m.input_elem();

                cout<<"\nEntered ";
                m.display_elem();

                cout<<"\n----------IMPLEMENTING MERGE SORT-----------\n";
                m.Merge_sort(0,m.size-1);
                
                cout<<"\nFinal Sorted ";
                m.display_elem();

                cout<<"Total Number of comparisons : "<<m.comparisons();
                break;
            }
        case 'b':{
                MergeSortClass<float> m;

                m.input_elem();

                cout<<"\nEntered ";
                m.display_elem();

                cout<<"\n----------IMPLEMENTING MERGE SORT-----------\n";
                m.Merge_sort(0,m.size-1);
                
                cout<<"\nFinal Sorted ";
                m.display_elem();

                cout<<"Total Number of comparisons : "<<m.comparisons();
                break;
            }
        case 'c':{
                MergeSortClass<char> m;

                m.input_elem();

                cout<<"\nEntered ";
                m.display_elem();

                cout<<"\n----------IMPLEMENTING MERGE SORT-----------\n";
                m.Merge_sort(0,m.size-1);
                
                cout<<"\nFinal Sorted ";
                m.display_elem();

                cout<<"Total Number of comparisons : "<<m.comparisons();
                break;
            }                
        default:{
                cout<<"\nInvalid input!!!";
            }    
    }    
return 0;
}