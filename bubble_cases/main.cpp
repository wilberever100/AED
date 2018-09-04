#include <iostream>
#include <stdlib.h>
#include <string>
#include <time.h>


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
//POLIMORFISMO
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



void bubbleSort_pol(int arr[], int n,comparador* p)
{
   int i, j;
   for (i = 0; i < n-1; i++)


       for (j = 0; j < n-i-1; j++)
           if (p->cmp(arr[j],arr[j+1]))
              swap(&arr[j], &arr[j+1]);
}


///////////////////////////////////////////////////////////////////

class asc{
    public:
        asc(){};
        inline bool operator()(int a, int b){
            return a>b;
        }
};
class desc{
    public:
        desc(){};
        inline bool operator()(int a, int b){
            return a<b;
        }
};


template <class T>

class bubble_functor{
    public:
        T op;

        void bubbleSort_func(int arr[], int n)
        {
           int i, j;

           for (i = 0; i < n-1; i++)

               // Last i elements are already in place
               for (j = 0; j < n-i-1; j++)
                   if (op(arr[j],arr[j+1]))
                      swap(&arr[j], &arr[j+1]);
        }

};
/////////////////////////////////////////////////////////////
//PUNTEROS A FUNCIÓN

bool ascendente(int a,int b){
    return a>b;
}
bool descendente(int a,int b){
    return a<b;
}

void bubbleSort_pointer(int arr[], int n, bool(*p)(int,int))
        {
           int i, j;
           ;
           for (i = 0; i < n-1; i++)

               // Last i elements are already in place
               for (j = 0; j < n-i-1; j++)
                   if (p(arr[j],arr[j+1]))
                      swap(&arr[j], &arr[j+1]);
        }








int main()
{

    srand(time(NULL));
    clock_t t0, t1;
    int elementos=300000;

    int* p;
    create(elementos,p);




    t0=clock();

//POLIMORFISMO
    comparador* c;
    mayorque mayor;
    c=&mayor;
    bubbleSort_pol(p,elementos,c);



//POINTER TO FUNCTION
    /*bool(*ptr)(int,int);
    ptr=&ascendente;
    bubbleSort_pointer(p,elementos,ptr);*/

//FUNCTOR
    //bubble_functor <asc>a;
    //a.bubbleSort_func(p,elementos);



    t1=clock();


    //printArray(p,10000);



    cout<<"EL TIEMPO DE EJECUCION ES: "<<double(t1-t0)/CLK_TCK<<endl;
    return 0;
}
