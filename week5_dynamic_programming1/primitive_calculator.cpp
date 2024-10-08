#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>

using std::vector;

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } 
	if (n % 2 == 0) {
      n /= 2;
    } 
	else {
      n = n - 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

vector<int> dp_optimal(int m){
	vector<int> dp(m+1);
	// for backtracking the optimal op.
	vector<int> previous(m+1);
	
	dp[0] = 0;
	
	for(int i = 2; i <= m; i++){
		// here we initialize the sequence as we only can substract 2
		dp[i] = dp[i -1] +1 ;
		previous[i] = i -1;
		
		// then we check the div by 2 and compare with the substract 1 .
		if(i % 2 == 0){
			if( dp[i /2] + 1 < dp[i]){
				dp[i] = dp[i / 2] + 1;
				previous[i] = i /2;
			}
		}
		// and finally we test with div by 3 against the other options.
		if(i % 3 == 0){
			if(dp[i / 3] + 1 < dp[i]){
				dp[i] = dp[i/3] + 1;
				previous[i] = i /3 ;
			}
		}
  }
  vector<int> sequence;
  for (int i = m;i != 0 ; i = previous[i]){
	sequence.emplace_back(i);
  }
  std::reverse(std::begin(sequence),std::end(sequence));
  return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = dp_optimal(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
