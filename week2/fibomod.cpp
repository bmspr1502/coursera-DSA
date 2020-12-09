#include <iostream>
#include <vector>

using namespace std;
int period(long long m){
  vector <long long> mod;
  mod.push_back(0);
  mod.push_back(1);
    //cout<<"\nfinding period";
    for(int i=2; i<m*m; i++){
        mod.push_back((mod[i-1] + mod[i-2])%m);
        //cout<<"\ni = "<<i<<" current = "<<mod[i];
        if(mod[i-1]==0 && mod[i]==1){
            //cout<<"\nperiod = "<<i-1;
            return i-1;
        }
    }
}

long long fibomod(long long n, long long m){
    int count = period(m);
    vector <long long> fibo;
    n = n%count;
    fibo.push_back(0);
    fibo.push_back(1);
    if(n==0)
        return 0;
    if(n==1)
        return 1;
    int i;
    //cout<<"\nfinding fibo";
    for(i=2; i<n+1; i++){
       fibo.push_back((fibo[i-1] + fibo[i-2])%m);
        //cout<<"\ni = "<<i<<" current = "<<fibo[i];
    }
    return fibo[i-1];
}

int main(){
    long long n,m;
    cin>>n>>m;

    cout<<fibomod(n,m);
}