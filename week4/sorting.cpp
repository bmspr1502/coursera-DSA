#include <iostream>
#include <vector>
#include <cstdlib>

using std::vector;
using std::swap;
/*
int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}
*/
/*
void partition3(vector<int> &a, int l, int r, int &i, int &j) {
  i = l-1;
  j=r;
  int p=l-1, q=r;
  int x = a[l];
  while(true){

    while(a[++i]<x);
  
    while(x<a[--j])
      if(j==l)
        break;

    if(i>=j)
      break;

    swap(a[i], a[j]);

    if(a[i]==x){
      p++;
      swap(a[p], a[i]);
    }
    if(a[j]==x){
      q--;
      swap(a[j], a[q]);
    }
  }

  swap(a[i], a[l]);

  j=i-1;
  for(int k=l; k<p; k++, j--){
    swap(a[k], a[j]);
  }
  i = i+1;
  for(int k=r-1; k>q; k--, i++){
    swap(a[i], a[k]);
  }
}
*/
void partition3(vector <int> &a, int l, int r, int& i, int& j)
{
    i = l - 1, j = r;
    int p = l - 1, q = r;
    int v = a[r];
 
    while (true) {
        // From left, find the first element greater than
        // or equal to v. This loop will definitely
        // terminate as v is last element
        while (a[++i] < v)
            ;
 
        // From right, find the first element smaller than
        // or equal to v
        while (v < a[--j])
            if (j == l)
                break;
 
        // If i and j cross, then we are done
        if (i >= j)
            break;
 
        // Swap, so that smaller goes on left greater goes
        // on right
        swap(a[i], a[j]);
 
        // Move all same left occurrence of pivot to
        // beginning of array and keep count using p
        if (a[i] == v) {
            p++;
            swap(a[p], a[i]);
        }
 
        // Move all same right occurrence of pivot to end of
        // array and keep count using q
        if (a[j] == v) {
            q--;
            swap(a[j], a[q]);
        }
    }
 
    // Move pivot element to its correct index
    swap(a[i], a[r]);
 
    // Move all left same occurrences from beginning
    // to adjacent to arr[i]
    j = i - 1;
    for (int k = l; k < p; k++, j--)
        swap(a[k], a[j]);
 
    // Move all right same occurrences from end
    // to adjacent to arr[i]
    i = i + 1;
    for (int k = r - 1; k > q; k--, i++)
        swap(a[i], a[k]);
}
 
/*  
void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  int m = partition2(a, l, r);

  randomized_quick_sort(a, l, m - 1);
  randomized_quick_sort(a, m + 1, r);
}
*/
void randomized_quick_sort_3(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }
  int m1=0, m2=0;

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  partition3(a, l, r, m1, m2);

  randomized_quick_sort_3(a, l, m2);
  randomized_quick_sort_3(a, m1, r);
}


int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  randomized_quick_sort_3(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
