#include <iostream>

using namespace std;

long long Fibo(int n){
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    long long first = 0, second = 1;
    long long third = first + second;
    for(int i=0; i<n-2; i++){
        first = second;
        second = third;
        third = first + second;
    }
    return third;
}
int main(){

    int n;
    cin>>n;
    cout<<Fibo(n);
    return 0;
}