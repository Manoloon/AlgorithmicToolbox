#include <iostream>

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
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

int fibonacci_sum_squares_fast(long long n) 
{
	if (n <= 1)
    return n;
	
	int period = GetPisanoPeriod(10);
	long long reducedN = n % period;
	long long n_plus_1 = (n+1) % period;
	
    int Fib_n = fiboMod(reducedN,10);
	int fib_n_plus1 = fiboMod(n_plus_1,10);
	
    return (Fib_n * fib_n_plus1) % 10;
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares_fast(n);
}
