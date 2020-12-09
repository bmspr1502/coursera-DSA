#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
/*
vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}


int min(int a, int b, int c){
  if(a<b && a<c)
    return 1;

  if (b<c)
    return 2;

    return 3;
}
*/
vector <int> optimal_sequence(int n) {
  int count[n+1][2];
  count[0][0]= 0;
  count[0][1] = 0;
  count[1][0] = 0;
  count[1][1] = 0; 

  //sequence[0]=1;
  for(int i=2; i<=n; i++){
    count[i][0]= count[i-1][0]+1;
    count[i][1] = i-1;

    if(i%3==0 && (count[i][0] > count[i/3][0] +1)){
        count[i][0]= count[i/3][0]+1;
        count[i][1] = i/3;
    }
    
    if(i%2==0 && (count[i][0] > count[i/2][0] +1)){
        count[i][0]= count[i/2][0]+1;
        count[i][1] = i/2;
    }
    //cout<<i<<" = "<<count[i]<<"\n";
  }

  //cout<<count[n][0]<<"\n";
  vector <int> sequence;
  int i=n;
  while(i>=1){
    sequence.push_back(i);
    i = count[i][1];
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;

}


int main() {
  int n;
  std::cin >> n;
  //optimal_sequence_pran(n);
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
  std::cout<<std::endl;
  
}
