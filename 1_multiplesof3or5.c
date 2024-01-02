#include <stdio.h>
#include <stdlib.h>

int multiple(int n){
    if ((n%3==0)||(n%5==0)){
        return n;
    }
    else{
    return 0;
}}

int recursivesum(int n){
    if(n==0){
        return 0;
    }
    int sum=multiple(n)+recursivesum(n-1);
    printf("within %d sum is %d\n",n,sum);
    return sum;
}
int main() {
    int s=recursivesum(999);
   printf("%d",s);
    return 0;
}
