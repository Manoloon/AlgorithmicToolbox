#include <iostream>
#include <vector>

using std::vector;
  /* 
	Knapsack(w)
	if w is in hashtable 
		return value(w)
	value(w) = 0
	for i from 1 to n:
		if w[i] <= w:
			val = Knapsack(w - w[i]) + v[i]
			if val > value(w) :
				value(w) = val
	insert value(w) into hashtable with key w
	return value(w)
  */

int optimal_weight(int W, const vector<int> &w) {
	int size = w.size();
	vector<vector<int>> dp(size+1,vector<int>(W+1,0));
	for(int i = 1; i <= size; i++){
		for(int weight = 1; weight <= W; weight++){
			dp[i][weight] = dp[i-1][weight];
			if(w[i-1] <= weight){
				dp[i][weight] = std::max(dp[i][weight],
								dp[i-1][weight - w[i-1]] + w[i-1]);
			}
		}
	}
	return dp[size][W];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
