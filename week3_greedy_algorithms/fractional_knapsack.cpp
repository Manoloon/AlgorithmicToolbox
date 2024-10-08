#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <utility>

using std::vector;
struct item
{
	double UnitValue;
	int TotalWeight;
};

bool compare(const item &a,const item &b){
	return a.UnitValue > b.UnitValue;
}
double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
	double value = 0.0;
	/*
	
	while capacity is not met
		choose the item i with max Value/Weight
		if item fits into capacity, take it all of it.
		otherwise take so much as to fill the capacity
	return total value
	*/
	// pair with unitCost,totalWeight available.
	int numberOfItems = values.size();
	std::vector<item> items(numberOfItems);
	for(int i=0;i < numberOfItems ; i++)
	{
		item currItem = {static_cast<double>(values[i])/weights[i],weights[i]};
		items.emplace_back(currItem);
	}

	std::sort(std::begin(items),std::end(items),compare);
	
	for(int i=0;i < numberOfItems && capacity > 0; i++){
		if(items[i].TotalWeight <= capacity){
			value += items[i].UnitValue * items[i].TotalWeight;
			capacity -= items[i].TotalWeight;
		}
		else{
			value += items[i].UnitValue * capacity;
			capacity =0;
		}
	}
	return value;
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
    int n,c = 0;
    while (input_file >> n >> c) {
		std::vector<int> values(n);
        for (int i = 0; i < n; ++i) {
            input_file >> values[i];
        }
		
        std::vector<int> weights(n);
        for (int i = 0; i < n; ++i) {
            input_file >> weights[i];
        }
		
        double expected_result;
        input_file >> expected_result;

        double result = get_optimal_value(c, weights, values);
		count++;
		std::cout << "Test # " << count << std::endl;
        std::cout << "Number of compounds: " << n << " capacity: " << c << ", Values: ";
		for (int val : values) {
            std::cout << val << " ";
        }
		std::cout << ",Weight: ";
        for (int we : weights) {
            std::cout << we << " ";
        }
		
        std::cout << "\nExpected: " << std::fixed << std::setprecision(4) << expected_result << ", Result: " << std::fixed << std::setprecision(4) << result << "\n";
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
/**/
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout << std::fixed << std::setprecision(4) << optimal_value << std::endl;
  //TestStress();
  return 0;
}
