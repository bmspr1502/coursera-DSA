#include <iostream>

using namespace std;

int lastFibo(int n){
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    int first = 0, second = 1;
    int third = first + second;
    for(int i=0; i<n-2; i++){
        first = second;
        second = third;
        third = (first + second)%10;
    }
    return third;
}
int main(){

    int n;
    cin>>n;
    cout<<lastFibo(n);
    return 0;
}