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
	if((stops.back() + tank) < dist)
	{
		return -1;
	}
	int refill =0;
	for(int i = 0; i < stops.size();i++)
	{
		if(stops[i] > tank)
		{
			int posDist = stops[i-1]+tank;
			if(stops[i] > posDist) return -1;
			refill++;
		}
	}
	
    return refill;
}

void TestStress()
{
	std::ifstream input_file("test.txt");
    if (!input_file) {
        std::cerr << "Error opening file!" << std::endl;
        return;
    }

    int d, m, n;
    while (input_file >> d >> m >> n) {
        std::vector<int> stops(n);
        for (int i = 0; i < n; ++i) {
            input_file >> stops[i];
        }

        int expected_result;
        input_file >> expected_result;

        int result = compute_min_refills(d, m, stops);

        std::cout << "Distance: " << d << ", Tank: " << m << ", Stops: ";
        for (int stop : stops) {
            std::cout << stop << " ";
        }
        std::cout << "\nExpected: " << expected_result << ", Result: " << result << "\n";
        std::cout << (result == expected_result ? "PASS" : "FAIL") << "\n\n";
    }

    input_file.close();
}

int main() {
	/*
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
	*/
	TestStress();
    return 0;
}
