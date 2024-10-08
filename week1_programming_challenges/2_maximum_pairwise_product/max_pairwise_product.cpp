#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <algorithm>

long long MaxPairwiseProduct(const std::vector<int>& numbers) {
    long long result = 0;
    int n = numbers.size();

    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
			if(((long long) numbers[first]) * numbers[second] > result)
			{
				result = ((long long)(numbers[first])) * numbers[second];
			}
        }
    }
    return result;
}

long long MaxPairwiseProductFast(const std::vector<int>& numbers)
{
	long long result=0;
	int size = numbers.size();
	if(size > 1)
	{
	std::vector<int> vec = numbers;
	std::sort(std::begin(vec),std::end(vec));	
	result = ((long long)vec[size-1]) * vec[size-2];
	}
	return result;
}

int main() {
	//stress test
	
  /*   while(true)
	{
		int n = rand() % 4 + 2;
		std::cout << "\n";
		std::vector<int> vec;
		for(int i = 0; i < n ; i++)
		{
			vec.emplace_back(rand() % 1000);
		}
		for(int i = 0; i < n ; i++)
		{
		std::cout << vec[i] << ' ';
		}
		std::cout << std::endl;
		long long res1 = MaxPairwiseProduct(vec);
		long long res2 = MaxPairwiseProductFast(vec);
		if(res1 != res2)
		{
			std::cout << "Wrong result: " << res1 << ' ' << res2 << std::endl;
			break;
		}
		else
		{
			std::cout << "OK\n";
		}
	} */
	int n;
	std::cin >> n;
	std::vector<int> numbers(n);
	for(int i=0;i<n;i++)
	{
		std::cin >> numbers[i];
	}
	long long result = MaxPairwiseProductFast(numbers);
	std::cout << result << "\n";
    return 0;
}