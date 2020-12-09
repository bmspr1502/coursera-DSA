#include<iostream>
#include<cstdlib>
#include<vector>
#include<ctime>

using namespace std;
/*
long long max_product(vector <int>& x){
    int n = x.size();
    int ind = 0;
    long long product;

    for (int i=0; i<n; i++){
        if(x[ind]<x[i])
            ind = i;
    }
    int ind2 = 0;
     for (int j=0; j<n; j++){
        if((j!=ind)&& (x[ind2]<x[j]))
            ind2 = j;
    }

    cout<<"first = "<<x[ind]<<" second = "<<x[ind2]<<endl;
    product = (long long) x[ind] * x[ind2];
    return product;
}
*/

long long max_product(vector <int>& x){
    long long big = 0,second = 0;
    int n = x.size();
    for(int i=0;i<n; i++){
        if(x[i]>big){
            second = big;
            big = x[i];
        } else if(second<=x[i]){
            second = x[i];
        }
    }
    //cout<<"big = "<<big<<"\nsecond = "<<second<<"\n";
    return big*second;
}

/*
long long max_product_slow(vector <int>& x){
    long long big=-1, second = -1;
    int n = x.size();
    for(int i=0; i<n; i++){
        if(x[i]>big)
            big = x[i];
    }
    for(int i = 0; i<n; i++){
        if((second<=x[i]) && (x[i]<big))
            second = x[i];
    }

    return big*second;
}
*/

int main(){

    /*while (true){
        srand((unsigned) time(0));
        int n= rand() %10 + 2;
        cout<<n<<endl;
        vector <int> a;
        for(int i=0; i<n; i++)
            a.push_back(rand() % 100000);
        
        for(int i=0; i<n; i++)
            cout<<a[i]<<" ";

        long long res1 = max_product(a);
        long long res2 = max_product_slow(a);

        if(res1!=res2){
            cout<<"\nWRONG OUTPUT "<<res1<<" "<<res2<<endl;
            break;
        } else {
            cout<<"\nOK\n";
        }
      
    }
    */
    
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0; i<n; i++)
        cin>>a[i];

    long long result = max_product(a);
    cout<<result;
    
}