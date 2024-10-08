#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
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

// funcion para calcular el n-esimo numero de fibonacci mod n
int fiboMod(long long n,long long m)
{
	if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
	
	for (long long i = 0; i < n - 1; ++i) {
        int tmp = (previous + current) % m;
        previous = current;
        current = tmp;
    }
	
	return current;
}

int fibonacci_sum_fast(long long from, long long to) {
	
	int period = GetPisanoPeriod(10);
	long long from_mod = (from + 1) % period;
	long long to_mod = (to + 2) % period;
	int fib_from_plus2 = fiboMod(to_mod,10);
    int fib_to_plus1 = fiboMod(from_mod,10);
	return (fib_from_plus2 - fib_to_plus1 + 10) % 10;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << fibonacci_sum_fast(from, to) << '\n';
}
