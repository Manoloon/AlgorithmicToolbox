#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
	if(dist <= tank) return 0;
	int refill =0;
	
	stops.insert(std::begin(stops),0);
	stops.emplace_back(dist);
	int numStops = stops.size() -1 ;
	
	for(int i = 0; i < numStops; ++i){
		if((stops[i + 1] - stops[i]) > tank){
			return -1;
		}
		int PrevRefill = i;
		while(i < numStops && stops[i + 1] - stops[PrevRefill] <= tank){
			++i;
		}
		if(i < numStops){
			++refill;
			--i;
		}
	}
    return refill;
}

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

        int result = compute_min_refills(d, m, stops);
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
}

int main() {
	
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";
	
	//TestStress();
    return 0;
}
