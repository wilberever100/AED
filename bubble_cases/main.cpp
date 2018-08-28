#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;


void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)

       // Last i elements are already in place
       for (j = 0; j < n-i-1; j++)
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        cout<< arr[i]<<" ";
}

void create(int n,int* &q){
    int* p=new int[n];
    for(int i=0;i<n;i++){
        *(p+i)=rand() % 100;
    }
    q=p;
}


////////////////////////////////////////////
class comparador{
    public:

        virtual bool cmp(int a,int b)=0;

};
class menorque: public comparador{
    public:
        bool cmp(int a,int b){
            return a<b;
        }

};
class mayorque: public comparador{
    public:
        bool cmp(int a,int b){
            return a>b;
        }

};

//POLIMORFISMO

void bubbleSort_pol(int arr[], int n,comparador* p)
{
   int i, j;
   for (i = 0; i < n-1; i++)


       for (j = 0; j < n-i-1; j++)
           if (p->cmp(arr[j],arr[j+1]))
              swap(&arr[j], &arr[j+1]);
}


///////////////////////////////////////////////////////////////////

class criterio{
    public:
        string op;
        criterio(string k):op(k){};
        bool operator()(int a, int b){
            if(op=="mayor"){return a>b;}
            else{return a<b;}
        }
};
void bubbleSort_func(int arr[], int n, string crit)
{
   int i, j;
   criterio(crit);
   for (i = 0; i < n-1; i++)

       // Last i elements are already in place
       for (j = 0; j < n-i-1; j++)
           if (criterio(arr[j],arr[j+1]))
              swap(&arr[j], &arr[j+1]);
}


/////////////////////////////////////////////////////////////



























int main()
{
    /*comparador* c;
    mayorque mayor;
    c=&mayor;*/

    int* p;
    create(100,p);
    //bubbleSort_pol(p,100,c);
    //bubbleSort_func(p,100,"mayor")

    printArray(p,100);
    return 0;
}
