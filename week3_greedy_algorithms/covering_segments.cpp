#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
};

bool isLower(const Segment& a,const Segment& b){
	return a.end < b.end;
}

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  
  std::sort(std::begin(segments),std::end(segments),isLower);
  int currentPoint = -1;
  //write your code here
  for (size_t i = 0; i < segments.size(); ++i) {
	if(currentPoint == -1 || segments[i].start > currentPoint){
		currentPoint = segments[i].end;
		points.push_back(segments[i].end);
	}
  }
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
