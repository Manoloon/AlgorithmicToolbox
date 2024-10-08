#include <iostream>
#include <algorithm>
#include <vector>

using std::vector;

// Karatsuba approach
vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size(),0);
  vector<std::pair<int,char>> events;
  vector<std::pair<int,int>> point_indices;
  
  // collect segments starts,ends and points in their indices
  for(int start : starts){
	events.push_back({start,'L'});  
  }
  for(int end : ends){
	events.push_back({end,'R'});  
  }
  for(int i = 0; i < points.size();i++){
	  point_indices.push_back({points[i],i});
	events.push_back({points[i],'P'});  
  }
  
  std::sort(std::begin(events),std::end(events),
			[](const std::pair<int,char>& a, const std::pair<int,char>& b){
					if(a.first == b.first)
						return a.second < b.second;
					return a.first < b.first;
			});
			
	int segment_count = 0;
	for(const auto& e : events){
		if(e.second == 'L') segment_count++;
		else if (e.second == 'R') segment_count--;
		else if (e.second == 'P') {
			auto it = std::lower_bound(std::begin(point_indices),std::end(point_indices),std::make_pair(e.first,-1));
			int point_index = it - std::begin(point_indices);
			cnt[point_indices[point_index].second] = segment_count;
		}
	}
  return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  //use fast_count_segments
  vector<int> cnt = naive_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
}
