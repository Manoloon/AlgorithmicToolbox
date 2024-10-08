#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <climits>
#include <cassert>

using std::vector;
using std::string;
using std::pair;
using std::min;

#define assertm(exp, msg) assert(((void)msg, exp))

struct node{
	int x;
	int y;
};
bool isSmaller(const node& a,const node& b){
	return a.x < b.x;
}

double GetDistSquared(const node& a, const node& b){
	return pow((b.x -a.x),2) + pow((b.y - a.y),2);
}

double minimal_distance(vector<int> x, vector<int> y) {
	assert(x.size() == y.size());

	vector<node> nodes;
	for(int i = 0; i < x.size();i++){
		nodes.push_back({x[i], y[i]});
	}
	std::sort(std::begin(nodes),std::end(nodes),isSmaller);
	int HalfNodesSize = nodes.size() /2;
	int d1 = INT_MAX;
	int d2 = INT_MAX;
	
	vector<node> S1;
	S1.assign(nodes.begin(), nodes.begin() + HalfNodesSize);
	std::sort(std::begin(S1),std::end(S1),GetDistSquared);
	
	vector<node> S2;
	S2.assign(nodes.begin() + HalfNodesSize, nodes.end());
	std::sort(std::begin(S2),std::end(S2),GetDistSquared);
	
	std::cout << "S1" << std::endl;
	for(const node& n : S1){
		std::cout << "x :" << n.x << ", " << "y :" << n.y << std::endl;
	}
	
	std::cout << std::endl << "S2" << std::endl;
	for(const node& n : S2){
		std::cout << "x :" << n.x << ", " << "y :" << n.y << std::endl;
	}
	return 0.;
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n);
  vector<int> y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::fixed;
  std::cout << std::setprecision(9) << minimal_distance(x, y) << "\n";
}
