#include <iostream>
#include <vector>

using namespace std;
int max(int a, int b){
  return (a>b)?a:b;
}

int lcs2(vector<int> &a, vector<int> &b) {
  int as = a.size();
  int bs = b.size();
  int c[as+1][bs+1];
  c[0][0]=0;

  for(int i=0; i<=as; i++){
    for(int j=0; j<=bs; j++){
      if(i==0 || j==0)
        c[i][j] = 0;

      else if(a[i-1]==b[j-1])
        c[i][j] = c[i-1][j-1] + 1;

      else
      {
          c[i][j] = max(c[i][j-1], c[i-1][j]);
      }
    }
  }
/*
  for(int i=0; i<=as; i++){
    for(int j=0; j<=bs; j++){
      cout<<c[i][j]<<"\t";
    }
    cout<<endl;
  }
  */
  //write your code here
  return c[as][bs];
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
