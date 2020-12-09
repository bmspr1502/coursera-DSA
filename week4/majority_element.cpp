#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int count_num_elem(vector <int> &a, int x, int low, int high){
  int count=0;

  for(int i=low; i<=high; i++){
    if(a[i]==x)
      count++;
  }
  return count;
}

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  //write your code here
  int mid= (right-left)/2 + left;  
  int leftMaj =  get_majority_element(a, left, mid);
  int rightMaj = get_majority_element(a, mid+1, right);

  if(leftMaj==rightMaj)
    return leftMaj;
  else{
    int left_count = count_num_elem(a,leftMaj, left, mid);
    int right_count = count_num_elem(a,rightMaj, mid+1, right);

    return left_count>right_count? leftMaj: rightMaj;
  }

  return -1;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    cin >> a[i];
  }
  int elem= get_majority_element(a, 0, a.size());
  int count = count_num_elem(a, elem, 0, a.size());
  if(count>(a.size()/2))
    cout<<1;
  else
    cout<<0;

  cout<<endl;
}
