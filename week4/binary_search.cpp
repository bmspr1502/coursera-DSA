#include <bits/stdc++.h> 

using namespace std;

int binary_search(const vector<int> &a, int x) {
  int left = 0, right = (int)a.size()-1;
  
  while(left<=right){ 
  int mid = (int) (left+right)/2;

  if(a[mid]==x)
    return mid;
  if(a[mid]<x){
    left = mid+1;
  }else {
    right = mid - 1;
  }
  }
  return -1;
  //write your code here
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

void stress_test(){
  int res1=0,res2=0;
  int n = rand()%1000 + 1;
    int i;
    vector <int> a(n);
    for(i=0; i<n; i++){
      a[i]= rand()%100000;
    }
    sort(a.begin(), a.end());
  do{
    int x = rand()%100000;
    res1 = linear_search(a,x);
    res2 = binary_search(a,x);

    if(res1==res2){
      cout<<"Both algos are same "<<endl;
    }
    else{
      cout<<"For x = "<<x<<"& a = ";
      for(i=0; i<a.size(); i++){
        cout<<" "<<a[i];
      }
      cout<<" res1 = "<<res1<<" res2 = "<<res2;    

      break;
    }
    
  }while(1);
}

int main() {
  
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << binary_search(a, b[i]) << ' ';
  }
  
 //stress_test();
}
