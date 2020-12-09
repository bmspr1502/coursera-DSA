#include <iostream>
#include <iomanip>
#include <vector>

using std::vector;

int find_max(vector <int> weights, vector <int> values){
  double max = 0;
  int index = -1;
  for(int i=0; i<weights.size(); i++){
    if(weights[i]==0)continue;
    double div = (double) values[i]/weights[i];
    if(div>max){
      max = div;
      index = i;
    }
  }
  return index;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double finvalue = 0.0;
  //std::cout<<"i am here\n";
  // write your code here
  for(int i=0; i<weights.size(); i++){
    //std::cout<<"boo";
    int index = find_max(weights,values);
    if(index==-1)break;
    double a;
    if(weights[index]<=capacity){
      a = weights[index];
    } else {
      a = capacity;
    }
    finvalue = finvalue + a*((double) values[index] / weights[index]);
    weights[index] = weights[index] - a;
    capacity = capacity - a;
    //std::cout<<" vfw["<<i<<"] = "<<vfw[index];
    //std::cout<<"\n a = "<<a<<"\n";
    //std::cout<<i<<" = finvalue = "<<finvalue<<std::endl;
    
  }
  return finvalue;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  //printf("%")
  std::cout << optimal_value << std::endl;
  return 0;
}
