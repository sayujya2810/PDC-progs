#include<omp.h>

#include<stdio.h>

int main(){

printf("Before parallel - Welcome to PDC lab\n");

#pragma omp parallel

{

printf("After Welcome to PDC lab\n");

}

}