/*************************************************************
*    Implement FizzBuzz:
*
*    If a number is a multiple of 3, print Fizz.
*    If a number is a multiple of 5, print Buzz.
*	 If a number is a multiple of 3 and 5, print FizzBuzz
*
*************************************************************/

	#include <iostream>
	
	void fizzbuzz(int n, int x = 3, int y = 5)
	{
		// Start with the the multiples of both 3 and 5 so the program prints and exits if a multiple of both
		// Check for zero as zero is not a multiple of 3 or 5
		if(n % (x*y) == 0 && n != 0)
			std::cout << "FizzBuzz" << '\t';
		
		// Check for the highest multiple for readability.  Descending in order makes the logic easier to follow
		// Check for zero as zero is not a multiple of 3 or 5
		else if(n % y == 0 && n != 0)
			std::cout << "Buzz" << '\t';
			
		// Check for the lowest multiple for readability.  Descending in order makes the logic easier to follow
		// Check for zero as zero is not a multiple of 3 or 5
		else if(n % x == 0 && n != 0)
			std::cout << "Fizz" << '\t';
			
		// Print input if the input is not a multiple of 3 or 5
		else 
			std::cout << n << '\t';
	}
	
	int main(void)
	{
		
		for(int i = 0; i < 151; i++)
			fizzbuzz(i);
		
		return 0;
	}
