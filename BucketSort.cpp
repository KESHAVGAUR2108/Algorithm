//IMPLEMENTATION OF BUCKET SORT

#include <iostream>
#include <list>
#include <cmath>
using namespace std;

template <class T>
class BucketSort{

    private:
        int n;
        T max;
        list<T> *B;
    
    public:
        T *A;
        BucketSort();
        ~BucketSort();
        void insertElem();
        void displayElem(T *Arr);
        void Bucket_Sort(T *Arr);
        void insertion_sort(int i);
};

template <class T>
BucketSort<T> :: BucketSort(){
    cout<<"\nEnter number of elements in the array : ";
    cin>>n;

    max = INT16_MIN;
    A = new T[n];
    B = new list<T>[10];
}

template<class T>
BucketSort<T> ::~BucketSort(){
    delete A;
    delete B,n;
}

template <class T>
void BucketSort<T> :: insertElem(){
    cout<<"\n***Elements should be in the range [0,1)***\n";
    
    cout<<"\nEnter "<<n<<" elements in array :: ";
    
    for(int i=0;i<n;i++){
        cin>>A[i];
        if(A[i]<0 || A[i]>=1){
            cout<<"\nError : Numbers entered in the array are out of range.";
            exit(0);
        }
    }    
}

template <class T>
void BucketSort<T> :: displayElem(T *Arr){
    cout<<"Array :: [ ";
    for(int i=0;i<n;i++){
        cout<<Arr[i]<<" ";
    }
    cout<<"]\n";
} 

template<class T>                      
void BucketSort<T> :: Bucket_Sort(T *A){
    
    int i,indx;
    list<float>::iterator k;

    for(i=0;i<n;i++){
        indx = floor(A[i]*10);
        B[indx].push_back(A[i]);
    }    

    for(i=0;i<10;i++)
        insertion_sort(i);

    i=0;
    for(indx =0;indx<10;indx++){
        for(k = B[indx].begin(); k != B[indx].end(); ++k){
            A[i] = *k;
            i++;
        }
    }
}

template <class T>
void BucketSort<T> :: insertion_sort(int indx){
    
    T key;

    list<float>::iterator i,j,tmp,tmp2;

    i = B[indx].begin();
    i++;

    for(;i != B[indx].end();++i){
        key = *i;
        tmp = i;
        j = --tmp;
        while(j!=B[indx].begin()){
            if( *j > key){
                tmp2 = j;
                tmp2++;
                *tmp2 = *j;
                --j;
            }
            else{
                break;
            }
        }
        if(j==B[indx].begin() && *j > key){
            tmp2 = j;           //shifting element
            tmp2++;
            *tmp2 = *j; 
        }
        else{j++;}
        *j = key;     //placing element to its correct position
    }
}

int main()
{
    BucketSort<float> bs;

    bs.insertElem();
 
    cout<<"\nEntered ";
    bs.displayElem(bs.A);

    cout<<"\n---------------------IMPLEMENTING BUCKET SORT---------------------\n";

    bs.Bucket_Sort(bs.A);

    cout<<"\nFinal Sorted ";
    bs.displayElem(bs.A);

 return 0;   
}
//0.78 0.17 0.39 0.26 0.72 0.94 0.21 0.12 0.23 0.68