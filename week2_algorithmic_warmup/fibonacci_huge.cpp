#include <iostream>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

// Pisano period
long long GetPisanoPeriod(long long m)
{
	long long current = 1;
	long long previous = 0;
	long long period = 0;
	
	for(long long i = 0 ; i < m * m; i++)
	{
		long long temp = (previous + current) % m;
		previous = current;
		current = temp;
		
		if(previous == 0 && current == 1)
		{
			period = i + 1;
			break;
		}
	}
	
	return period;
}

long long get_fibonacci_huge_fast(long long n, int m) 
{
    if (n <= 1)
        return n;
	
	long long period = GetPisanoPeriod(m);
	n = n % period;
	
	if (n <= 1) return n;
	
    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
		previous = current;
		current = (tmp_previous + current) % m;
    }

    return current;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n , m) << '\n';
}
