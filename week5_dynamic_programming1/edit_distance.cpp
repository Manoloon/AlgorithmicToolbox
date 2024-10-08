#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using std::string;

int edit_distance(const string &str1, const string &str2) {
	// Levenshtein distance 
	int Size1 = str1.size();
	int Size2 = str2.size();
	
	std::vector<std::vector<int>> dp(Size1 + 1, std::vector<int>(Size2 + 1));
	
	for(int i = 0; i <= Size1; i++)
	{
		for(int j = 0; j <= Size2; j++){
			if(i == 0) 
				// str1 is empty, insert all chars of str2
				dp[i][j] = j; 
			else if (j == 0)
				// str2 is empty, insert all chars of str1
				dp[i][j] = i;
			else if (str1[i - 1]== str2[j -1])
				// characters match, no op needed
				dp[i][j] = dp[i -1][j-1];
			else
				dp[i][j] = 1 + std::min({dp[i -1][j], // delete
										dp[i][j-1], // insert
										dp[i-1][j-1]});	// replace
		}
	}
	
  return dp[Size1][Size2];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
