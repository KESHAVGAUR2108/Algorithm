//COUNTING SORT
// template <class T>
// void RadixSort<T> :: COUNTING_SORT(){

//     T *C = new T[k+1];

//     for(int i=0;i<=k;i++)
//         C[i]=0;

//     for(int j=0;j<n;j++)
//         C[A[j]] = C[A[j]] +1;
//     //C[i] now contains the number of elements equal to i.
 
//     for(int i=1;i<=k;i++)
//         C[i] = C[i] + C[i-1];
//     //C[i] now contains the number of elements less than or equal to i.
    
//     for(int j=n-1;j>=0;j--){
//         B[C[A[j]]-1] = A[j];
//         C[A[j]] = C[A[j]]-1;
//     } 
// }