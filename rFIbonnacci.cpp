#include <iostream>
long fibonacci(long n)
{
    if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
    else
        return fibonacci(n-1) + fibonacci(n-2);
}

int main(void)
{
    long number=9;
	std::cout<<"Noven números de la sucesion de FIbonacci"<<"\n";
	for(int i = 0; i <= number;i++)
	{
		std::cout<<fibonacci(i)<<"\n";
	}
    return 0;
}