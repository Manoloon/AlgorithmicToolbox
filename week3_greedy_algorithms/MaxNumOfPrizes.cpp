#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  int currentSum = 0;
  int nextNum = 1;
  while(currentSum + nextNum <= n){
	summands.emplace_back(nextNum);
	currentSum += nextNum;
	nextNum++;
  }
  if(currentSum < n){
	summands.back() += n - currentSum;
  }
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
