#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_map>
using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  int majority = std::floor(a.size() / 2);
  
  std::unordered_map<int,int> map;
  for(int i = 0; i < a.size();i++){
	  map[a[i]]++;
  }
  for(auto pair : map){
	  if(pair.second > majority) return 1;
	  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
