#include<stdio.h>

int count_divide_and_conquer = 0;
int count_naive = 0;

unsigned long long int divide_and_conquer_Power(int a,int n){
    ++count_divide_and_conquer;

    if(n == 1) return a;
    if(n == 0) return 1;

    //Number is odd
    int number = divide_and_conquer_Power(a,n/2);
    if(n&1){
        return number * a * number;
    }
    //Number is even
    else{
        return number * number;
    }
}

unsigned long long int naive_Power(int a,int n){
    if (n==0) return 1;
    if (n==1) return a;
    int num = a;
    ++count_naive;
    for(int i=1;i<n;i++){
        ++count_naive;
        num*=a;
    }
    return num;
}

int main(){
    int a = 2;
    int b = 30;

    unsigned long long int pow1 = divide_and_conquer_Power(a,b);
    unsigned long long int pow2 = naive_Power(a,b);

    printf("%lli %lli\n",pow1,pow2);
    printf("%d %d\n",count_divide_and_conquer,count_naive);
}