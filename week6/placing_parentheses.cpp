#include <iostream>
#include <cassert>
#include <string>
#include <vector>
#include <climits>
#define expsize 20
using namespace std;

long long minval[expsize][expsize], maxval[expsize][expsize];

long long max(long long a, long long b, long long c, long long d, long long e){
  long long val = a;
  if (b>val)
    val = b;
  if(c>val)
    val = c;
  if(d>val)
    val = d;
  if (e>val)
    val = e;

  return val;
}

long long min(long long a, long long b, long long c, long long d, long long e){
  long long val = a;
  if (b<val)
    val = b;
  if(c<val)
    val = c;
  if(d<val)
    val = d;
  if (e<val)
    val = e;

  return val;
}

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    //cout<<op<<endl;
    //return 0;
    assert(0);
  }
}

void MinAndMax(vector <long long> &a, string &op, int i, int j){

  long long maximum = LLONG_MIN;
  long long minimum = LLONG_MAX;
  long long maxmax, maxmin,minmax, minmin;

  for(size_t x = i; x<j; x++){
    //cout<<"x = "<<x<<"op = "<<op[x]<<endl;
    maxmax = eval(maxval[i][x], maxval[x+1][j], op[x]);
    maxmin = eval(maxval[i][x], minval[x+1][j], op[x]);
    minmax = eval(minval[i][x], maxval[x+1][j], op[x]);
    minmin = eval(minval[i][x], minval[x+1][j], op[x]);

    maximum = max(maximum, maxmax, maxmin, minmax, minmin);
    minimum = min(minimum, maxmax, maxmin, minmax, minmin);
  }

  minval[i][j] = minimum;
  maxval[i][j] = maximum;
}



long long get_maximum_value(const string &exp) {

  int n=exp.length();

  
  //write your code here
  
  vector <long long> a;
  string op;

  for(size_t i=0; i<n; i++){
    if(exp[i] >=48)
      a.push_back((long long) (exp[i] - 48));
    else 
      op.push_back(exp[i]);
  }
  op.push_back('\0');
  /*
  for(size_t i=0; i<n/2; i++){
      cout<<op[i];
  }
  */
  n = a.size();
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      maxval[i][j] = 0;
      minval[i][j] = 0;
    }
  }

  for(size_t i=0; i<n; i++){
    minval[i][i] = a[i];
    maxval[i][i] = a[i];
  }

  for(size_t x=0; x<n; x++){
    for(size_t i=0; i<n-x-1; i++){
      size_t j = i+x+1;
      //cout<<i<<", "<<j<<endl;
      MinAndMax(a,op,i,j);
    }
  }
  /*
  cout<<"Maxval: \n";
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cout<<maxval[i][j]<<"\t";
    }
    cout<<endl;
  }
  cout<<"Minval: \n";
  for(int i=0; i<n; i++){
    for(int j=0; j<n; j++){
      cout<<minval[i][j]<<"\t";
    }
    cout<<endl;
  }
  */

  
  return maxval[0][n-1];
}

int main() {
  string s;
  getline(cin, s);
  std::cout << get_maximum_value(s) << '\n';
}
