#include <iostream>
#include <vector>

using namespace std;

void findMaxPrize(int x){
    int i=0,sum=0,count=0;
    vector <int> a;
    while(sum<x && i<=x){
        if(i>=x){
            i=a.back();
            a.pop_back();
            sum-=i;
        }
        i++;
        
        if(sum+i <= x){
            a.push_back(i);
            sum+=i;
        }
        if(sum==x)
            break;
    }
    cout<<a.size()<<endl;
    for(int j=0; j<a.size(); j++){
        cout<<a[j]<<" ";
    }
    cout<<endl;

}

int main(){
    int n;
    cin>>n;

    findMaxPrize(n);
    return 0;
}