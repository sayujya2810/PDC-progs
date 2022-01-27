#include <stdio.h>
#include <stdlib.h>
#include<omp.h>


int main(){

    int * a = (int *)malloc(sizeof(int)*4);
    int * b = (int *)malloc(sizeof(int)*4);
    int * c = (int *)malloc(sizeof(int)*4);
    int no_of_threads = 2;

    for(int i=0;i<4;i++){
        a[i] = i;
    }
    for(int i = 4; i>0 ;i--){
        b[4-i] = -1 * i;
    }

    omp_set_num_threads(no_of_threads);
    int n_per_thread = 4/no_of_threads;
    int i;
    #pragma omp parallel for shared(a,b,c) schedule(static,n_per_thread) private(i)
        for(int i=0;i<4;i++){
            c[i] = a[i] + b[i];
            printf("Thread %d works on element %d \n", omp_get_thread_num(),i);
        }

        printf("---------Result------------\n");
        for(int i=0;i<4;i++){
            printf("%d\n",c[i]);
        }
    return 0;
}


// #include <stdlib.h> //malloc and free

// #include <stdio.h> //printf

// #include <omp.h> //OpenMP

// #define ARRAY_SIZE 4 //Size of arrays whose elements will be added together.

// #define NUM_THREADS 4 //Number of threads to use for vector addition.

// int main (int argc, char *argv[]) //X --- > Y

// { //a1x1+a2x2+a4x4+……+anxn ------- > Y

// int * a;

// int * b;

// int * c;

// int n = ARRAY_SIZE; // number of array elements

// int n_per_thread; // elements per thread

// int total_threads = NUM_THREADS; // number of threads to use

// int i; // loop index

// // allocate spce for the arrays

// a = (int *) malloc(sizeof(int)*n);

// b = (int *) malloc(sizeof(int)*n);

// c = (int *) malloc(sizeof(int)*n);

// // initialize arrays a and b with consecutive integer values

// // as a simple example

// for(i=0; i<n; i++) {

// a[i] = i;

// }

// for(i=0; i<n; i++) {

// b[i] = i;

// }

// omp_set_num_threads(total_threads);

// // determine how many elements each process will work on

// n_per_thread = n/total_threads;

// #pragma omp parallel for shared(a, b, c) private(i) schedule(static, n_per_thread)

// for(i=0; i<n; i++) {

// c[i] = a[i]+b[i];

// // Which thread am I? Show who works on what for this small example

// printf("Thread %d works on element%d\n", omp_get_thread_num(), i);

// }

// printf("i\ta[i]\t+\tb[i]\t=\tc[i]\n");

// for(i=0; i<n; i++) {

// printf("%d\t%d\t\t%d\t\t%d\n", i, a[i], b[i], c[i]);

// }

// // clean up memory

// free(a); free(b); free(c);

// return 0;

// }