#include <iostream>
#include <cassert>
#include <climits>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::max;
using std::min;

/*
Parentheses(d,op,d2,op2,d3,op3....dx,opx):
	for i from 1 to n:
		min(i,i) = di
		max(i,i) = di
	for s from 1 to n-1:
		for i from 1 to n-s:
			j = i + s
			min(i,j) 
			max(i,j) = MinAndMax(i,j)
	return max(1,n)
*/

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}

int MinAndMax(int i, int j){
	int min = INT_MAX;
	int max = -INT_MAX;
	
	for(int k = 0; k  < i && k < (j-1); k++){
		
	}
}

long long get_maximum_value(const string &exp) {
  //write your code here
  return 0;
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
