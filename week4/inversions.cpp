#include <iostream>
#include <vector>

using std::vector;

long long count_of_inversions(vector <int> &arr, size_t low, size_t mid, size_t high){
    long long count = 0;
    size_t s1 = (mid-low)+1;
    size_t s2 = high-mid;
    size_t i,j,k;
    vector <int> leftArr(s1), rightArr(s2);

    for(i=0; i<s1; i++){
      leftArr[i] = arr[low+i];
    }
    
    for(j=0; j<s2; j++){
        rightArr[j] = arr[mid+1+j];
    }
/*
    for(i=0; i<s1; i++){
      for(j=0; j<s2; j++){
        if(leftArr[i]>rightArr[j])
          count++;
      }
    }
*/
    i=0;
    j=0;
    k=low;


    while(i<s1 && j<s2){
        if(leftArr[i]<=rightArr[j]){
            arr[k++]=leftArr[i++];
        } else {
            //std::cout<<arr[k]<<" -> ";
            arr[k++] = rightArr[j++];
            //std::cout<<arr[k-1]<<"\n";
            count++;
        }
    }

    while(i<s1){
        //std::cout<<arr[k]<<" -> ";
        arr[k++] = leftArr[i++];
        //std::cout<<arr[k-1]<<"\n";
        
        count++;
    }
    
    while(j<s2){
        arr[k++] = rightArr[j++];
        //count++;
    }
    return count;
}

long long get_number_of_inversions(vector<int> &a, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (left<right){
  size_t ave = (left+right)/2;
  number_of_inversions += get_number_of_inversions(a, left, ave);
  number_of_inversions += get_number_of_inversions(a,ave+1, right);
  //write your code here
  number_of_inversions += count_of_inversions(a, left, ave, right);
  }
  return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  for (size_t i=0; i<a.size(); i++){
    std::cout<< i<<" = "<<a[i]<<", ";
  }
  std::cout<<"\n";
  vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, 0, a.size()-1) << '\n';
  for (size_t i=0; i<a.size(); i++){
    std::cout<< i<<" = "<<a[i]<<", ";
  }
  std::cout<<"\n";
}
