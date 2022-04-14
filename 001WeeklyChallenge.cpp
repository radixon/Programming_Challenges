/**************************************************************************
* Pretend the following problem was given to you as a take home assessment. 
* Complete it and comment with a link to the submission and I'll review it!
*
* Problem: You are climbing a staircase. It takes n steps to reach the top. 
* Each time you can either climb 1 or 2 steps. In how many distinct ways can 
* you climb to the top?
*
* Example 1: Input: n = 2 Output: 2 Explanation: There are two ways to climb 
* to the top.
*
* 1 step + 1 step
* 2 steps
* Example 2: Input: n = 3 Output: 3 Explanation: There are three ways to climb 
* to the top.
*
* 1 step + 1 step + 1 step
* 1 step + 2 steps
* 2 steps + 1 step
*******************************************************************************/

	#include <iostream>
	#include <cmath>
	
	int factorial(unsigned int n, unsigned int m);
	int bruteForce(int minimum_step_size, int maximum_step_size, const int steps_to_top);
	int efficientSolution(const int n);
	
	int main(void){
		int minimum_step_size(0);
		int maximum_step_size(0);
		int steps_to_top(0);
		unsigned int answer(0);
		
		std::cout << "Minimum number of steps that can be taken: ";
		std::cin >> minimum_step_size;
		
		std::cout << "Maximum number of steps that can be taken: ";
		std::cin >> maximum_step_size;
		
		std::cout << "How many steps to the top of the staircase: ";
		std::cin >> steps_to_top;
		std::cout << "\n" ;
		
		answer = bruteForce(minimum_step_size, maximum_step_size, steps_to_top);
		
		std::cout << "Minimum number of steps: " << minimum_step_size << "\n";
		std::cout << "Maximum number of steps: " << maximum_step_size << "\n";
		std::cout << "Number of steps to the top: " << steps_to_top << "\n";
		std::cout << "answer: " << answer << std::endl;
		
		std::cout << "\n";
		std::cout << "Solving the stated problem in an efficient manner!" << "\n";
		std::cout << "How many steps to the top: ";
		std::cin >> steps_to_top;
		
		answer = efficientSolution(steps_to_top);
		std::cout << "answer: " << answer << std::endl;
		
	}
	
	int factorial(unsigned int n, unsigned int m=1)
	{
		unsigned int x(1);
		n = abs(n);
		if (n <= 1)
		{
			return 1;
		}
		else
		{
			for(int i = m+1; i <= n; i++)
			{
				x *= i;
			}
		}
		
		return x;
	}
	
	int bruteForce(int minimum_step_size, int maximum_step_size, const int steps_to_top)
	{
		int min_max_step_ratio(0);
		int count_minimum_step_size(0);
		int count_maximum_step_size(0);
		int total_count_of_numbers_in_permutation(0);
		int m(0);
		unsigned int x(0);
		
		// How many of the minimum step size is require to reach the top
		count_minimum_step_size = steps_to_top/minimum_step_size;
		
		// How many of the maximum stpe sizes can be made without overreaching
		count_maximum_step_size = steps_to_top/maximum_step_size;
		
		// How many sep sizes have ot be removed per maximum step size
		min_max_step_ratio = maximum_step_size/minimum_step_size;
		
		// Start with the maximum number of minimum steps
		total_count_of_numbers_in_permutation = count_minimum_step_size;
		
		while(m <= count_maximum_step_size)
		{
			x += factorial(total_count_of_numbers_in_permutation, count_minimum_step_size)/factorial(m);
			m++;
			count_minimum_step_size -= min_max_step_ratio;
			total_count_of_numbers_in_permutation = count_minimum_step_size + m;
		}
		
		return x;
	}
	
	int efficientSolution(const int n)
	{
		int x(0);
		int y = abs(n);		
		int fib[n];
		
		while(x <= 1 && x <= y)
		{
			fib[x] = 1;
			x++;
		}
		
		if(y > 1)
		{
			for(int i = 2; i <= y; i++)
			{
				fib[i] = fib[i-1] + fib[i-2]; 
			} 
		}
		
		return fib[n];
		
	}
