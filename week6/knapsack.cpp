#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int optimal[10001][301];

int optimal_weight(int W, const vector<int> &w) {
  //write your code here
  int n=w.size();
  

  for (int i=0; i<=W; i++){
    for(int j=0; j<=n; j++){
      if(i==0 || j==0)
        optimal[i][j] = 0;
      else{
        optimal[i][j] = optimal[i][j-1];
        if(i>=w[j-1])
        optimal[i][j] = max(optimal[i-w[j-1]][j-1] + w[j-1], optimal[i][j-1]);
      }
    }
  }

/*
  for(int i=0; i<=W; i++){
    for(int j=0; j<=n; j++){
      cout<<optimal[i][j]<<"\t";
    }
    cout<<endl;
  }
*/
  return optimal[W][n];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
