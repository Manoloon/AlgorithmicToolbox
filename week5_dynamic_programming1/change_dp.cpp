#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

int get_change(int m) {
  //write your code here
  std::vector<int> dp(m + 1, INT_MAX);
  std::vector<int> coins = {1,3,4};
  dp[0] = 0;
  for(int i = 1; i <= m; i++){
	  for(int coin : coins)
	  {
		  if(i - coin >= 0 && dp[i - coin] != INT_MAX){
			dp[i] = std::min(dp[i], dp[i - coin] +1);
		  }
	  }
  }
  
  return dp[m] == INT_MAX ? -1 : dp[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
