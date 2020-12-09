#include <iostream>
#include <string>

using namespace std;

int minimum(int a, int b, int c){
  if(a<=b && a<=c)
    return a;

  else if(b<=c)
    return b;

  return c;
}

int edit_distance(const string &str1, const string &str2) {
  //write your code here
  int l1= str1.length();
  int l2 = str2.length();
  //cout<<l1<<" "<<l2<<endl;
  int edit[l1+ 1][l2 + 1];

  edit[0][0]=0;
  for(int i=1; i<=l1; i++){
    edit[i][0]=i;
  }
  for(int i=1; i<=l2; i++){
    edit[0][i] = i;
  }

  for(int i=1; i<=l1; i++){
    for(int j=1; j<=l2; j++){
      int diff=1;
      if(str1[i-1]==str2[j-1])
        diff=0;
      
      edit[i][j] = minimum(edit[i-1][j]+1, edit[i][j-1] +1, edit[i-1][j-1] + diff);
    }
  }
/*
  for(int i=0; i<=l1; i++){
    for(int j=0; j<=l2; j++){
      cout<<edit[i][j]<<"\t";
    }
    cout<<endl;
  }

*/
  return edit[l1][l2];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
