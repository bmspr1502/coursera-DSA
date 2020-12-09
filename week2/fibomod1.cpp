#include <iostream>
#include <vector>

using namespace std;
int period(long long m){
    int third,previous = 0, current = 1;
    //cout<<"finding period";
    for(int i=0; i<m*m; i++){
        third = previous + current;
        previous = current;
        current = third%m;
        //cout<<"\ni = "<<i<<" current = "<<current;
        if(previous==0 && current==1){
            //cout<<"\nperiod = "<<i+1;
            return i+1;
        }
    }
}

long long fibomod(long long n, long long m){
    int count = period(m);
    long long previous = 0, current = 1, third;
    n = n%count;

    if(n==0)
        return 0;
    if(n==1)
        return 1;

    for(int i=0; i<n-1; i++){
        third = previous + current;
        previous = current;
        current = third%m;
        //cout<<"\ni = "<<i<<" current = "<<current;
    }
    return current%m;
}

int main(){
    long long n,m;
    cin>>n>>m;

    cout<<fibomod(n,m);
}