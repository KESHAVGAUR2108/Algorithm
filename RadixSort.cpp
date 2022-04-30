//IMPLEMENTATION OF RADIX SORT

#include <iostream>
#include <cmath>
using namespace std;

template <class T>
class RadixSort{
    
    private:
        T *A;
        int k,d;
        T highest;
        
    public:
        T *B;
        int n;
        RadixSort();
        void insertElem();
        int dvalue();
        void COUNTING_SORT(int d);
        void displayElem();
        void Radix_Sort(int d);
};

template<class T>
RadixSort<T> :: RadixSort(){
    cout<<"\nEnter number of elements in the array : ";
    cin>>n;
    k = 9; //assuming value of k will be in range 0 to 9
    d=0;
    A = new T[n];
    B = new T[n];
}

template<class T>
void RadixSort<T> :: insertElem(){
    
    highest = INT16_MIN;
    cout<<"\nEnter "<<n<<" elements in the array : ";
    for(int i=0;i<n;i++){
        cin>>A[i] ;
        
        if(A[i]>highest){
            highest = A[i];
        }
    }    
}

template<class T>
int RadixSort<T> :: dvalue(){
    while((highest = (int)highest/10) != 0)
        d++;
    d++;
 return d; //return highest order digit count
}

template<class T>
void RadixSort<T> :: displayElem(){
    cout<<"\nEntered array :: [ ";
    for(int i=0;i<n;i++)
    cout<<A[i]<<" ";
    cout<<"]\n";
}

template <class T>
void RadixSort<T> :: COUNTING_SORT(int indx){
    
    T *C = new T[k+1];

    for(int i=0;i<=k;i++)
        C[i]=0;

    int modulo,divide;
    
    //POWER FUNCTION WAS GIVING VALUE LESS BY 1 FOR EVEN VALUE OF 'indx' variable
    if (indx%2==0){
        modulo = pow(10,indx) + 1;
        divide = pow(10,indx-1) + 1;
    }
    else{
        modulo = pow(10,indx);
        divide = pow(10,indx-1);
    }

    //TO GET nth DIGIT OF A NUMBER
    for(int j=0;j<n;j++) {
        C[(int)((A[j]%modulo)/divide)] = C[(int)((A[j]%modulo)/divide)] +1;
    }
    //C[i] now contains the number of elements equal to i.
   
    for(int i=1;i<=k;i++){
        C[i] = C[i] + C[i-1];
    //C[i] now contains the number of elements less than or equal to i.
    }

    //put the elements in B at the right position
    for(int j=n-1;j>=0;j--){
        B[C[(int)((A[j]%modulo)/divide)]-1] = A[j];
        C[(int)((A[j]%modulo)/divide)] = C[(int)((A[j]%modulo)/divide)]-1;
    } 
   
    //updating array A with sorted values
    for(int i=0;i<n;i++){
        A[i] = B[i];
    }    
}

template<class T>
void RadixSort<T> :: Radix_Sort(int d){
    cout<<"\n----------------IMPLEMENTING RADIX-SORT---------------------\n";
    for(int i=1;i<=d;i++){
       COUNTING_SORT(i);
    }
}

int main(){

    RadixSort<int> rs;
    
    rs.insertElem();

    rs.displayElem();

    rs.Radix_Sort(rs.dvalue());
    
    cout<<"\nFinal Sorted Array :: [ ";
    for(int i=0;i<rs.n;i++)
        cout<<rs.B[i]<<" ";
    cout<<"]"<<endl;
 
 return 0;   
}