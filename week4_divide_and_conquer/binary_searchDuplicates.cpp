#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>
#include <cmath>
// output the index of the first occurence .
/*
Input:
7
2 4 4 4 7 7 9
4
9 4 5 2
Output:
6 1 -1 0
*/
using std::vector;

int binary_search(const vector<int> &a, int x) {
  int left = 0, right = (int)a.size(); 
  int pivot = std::floor(right / 2);
 
  if(x <= a[pivot]){
	  for(int i = 0; i <= pivot; i++)
	  {
		  if(x == a[i]) return i;
	  }
  }
  else {
	  for(int i = pivot; i < right; i++)
	  {
		  if( x == a[i]) return i;
	  }
  }
  return -1;
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}
/*
void TestStress()
{
	std::cout << "TESTING" << std::endl;
	std::ifstream input_file("test.txt");
    if (!input_file) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }
	int count = 0;
    int d, m, n = 0;
    while (input_file >> d >> m >> n) {
        std::vector<int> stops(n);
        for (int i = 0; i < n; ++i) {
            input_file >> stops[i];
        }

        int expected_result;
        input_file >> expected_result;

        int result = binary_search(d, m, stops);
		count++;
		std::cout << "Test # " << count << std::endl;
        std::cout << "Distance: " << d << ", Tank: " << m << ", Stops: ";
        for (int stop : stops) {
            std::cout << stop << " ";
        }
        std::cout << "\nExpected: " << expected_result << ", Result: " << result << "\n";
		if(result == expected_result){
        std::cout << "PASS" << "\n\n";
		}
		else{
			std::cout << "FAIL" << "\n\n";
			break;
		}			
    }

    input_file.close();
}*/

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << binary_search(a, b[i]) << ' ';
  }
}
