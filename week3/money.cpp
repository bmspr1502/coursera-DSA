#include <iostream>
using namespace std;

int find_coin(int x){
    int ten,five,change;
    ten = x/10;
    x = x%10;
    five = x/5;
    x = x%5;
    change = ten+five+x;
    return change; 
}
int main()
{
    int n;
    cin>>n;
    cout<<find_coin(n);
    return 0;
}