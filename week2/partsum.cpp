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

int find_diff(long long x, long long y){
    int a = fibomod(x+1,10);
    if(a==0)
        a= 10;
    int b = fibomod(y+2,10);
    if(b==0)
        b= 10;
    
    int c = b-a;
    if (c<0){
        c = 10+c;
    }
    return c;
}
int main(){
    long long a,b;
    cin>>a>>b;

    cout<<find_diff(a,b);
}