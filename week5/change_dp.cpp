#include <iostream>
#include <vector>

using namespace std;

int get_change(int m) {
  
  //write your code here
  if(m<=0)
    return 0;

  vector <int> count(m+1), coins(3);
  coins[0]=1;
  coins[1]=3;
  coins[2]=4;
  count[0]=0;

  for(int i=1; i<=m; i++){
    count[i] = count[i-1]+1;
    if(m>2){
      for(int j=1; j<3; j++){
        
        if(count[i-coins[j]]+1 < count[i]){
          count[i] = count[i-coins[j]]+1;
        }
        
      }
    }
  }

  int result = count[m];

  return result;

}

int main() {
  int m;
  std::cin >> m;
  
  std::cout << get_change(m) << '\n';
}
