#include <iostream>
#include <cmath>
using namespace std;

long long gcd(long long a, long long b){
    long long q = a/b;
    long long r = a%b;
    if(r==0)
        return b;
    else
        return gcd(b,r);
}
int main(){
    long long a,b,product,hcf,diff,lcm;
    cin>>a>>b;
    product = a*b;
    hcf = gcd(a,b);
    diff = product / pow(hcf,2);
    
    lcm = hcf * diff;

    cout<<lcm;
    return 0;
}