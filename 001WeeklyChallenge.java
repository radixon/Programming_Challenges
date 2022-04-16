
public class WeeklyChallenge {
	// This method calculates the factorial
	// For efficiency factorial will be for range of division of two factorials
	// i.e. 7!/4! = 7 * 6 * 5
	public static int factorial(int n, int m)
	{
		// x will be used in multiplication so initialize to 1
		int x = 1; 
		
		// If going upstairs is positive and going downstairs is negative
		// The math doesn't change, so use absolute value
		n = Math.abs(n);
		
		// The question is how many ways to get to the goal
		// If you start at the goal, 0!, there is only one way to
		// get to the top. If you are one step from the goal, 1!,
		// then there is only one way to make it to the top.
		if(n <= 1)
		{
			return (1);
		}
		// If there is more than one way to the top, then the factorial
		// multiplies the permutation numerator.
		else
		{
			// The total number in the permutation divided by 
			// the number of repeated minimum steps.  This 
			// equates to starting at the number one higher
			// than the minimum steps and stops at the total
			// count in the permutation.
			for(int i =m+1; i <= n; i++)
			{
				x *= i;
			}
		}
		
		return (x);
	}
	
	public static int bruteForce(int minimum_step_size, int maximum_step_size, int steps_to_top)
	{
		int min_max_step_ratio = 0;
		int count_minimum_step_size = 0;
		int count_maximum_step_size = 0;
		int total_count_of_numbers_in_permutation = 0;
		int m = 0;
		int x = 0;
		
		// The total number of minimum steps to reach the goal.
		count_minimum_step_size = steps_to_top/minimum_step_size;
		
		// The total number of maximum steps to reach the goal.
		count_maximum_step_size = steps_to_top/maximum_step_size;
		
		// This calculates how many minimum steps has to be removed
		// to add a maximum steps.
		min_max_step_ratio = maximum_step_size/minimum_step_size;
		
		// The permutation will start with minimum steps only.
		total_count_of_numbers_in_permutation = count_minimum_step_size;
		
		while(m <= count_maximum_step_size)
		{
			// This loop will add all possible permutations of steps to the top.
			// The loop starts with the the maximum number of minimum steps and
			// ends with the maximum number of maximum steps.
			x += factorial(total_count_of_numbers_in_permutation, count_minimum_step_size)/factorial(m,1);
			m++;
			count_minimum_step_size -= min_max_step_ratio;
			total_count_of_numbers_in_permutation = count_minimum_step_size + m;
		}
		
		return x;		
	}
	
	public static int efficientSolution(int n)
	{
		int x = 0;
		// Using the absolute value due to the process being the same
		// going up to the goal or going down to the goal.
		n = Math.abs(n);
		
		// The fibonacci sequence being used starts at zero and ends at
		// n.  This requires an array that has a length of n+1.  Each
		// position of the array holds the answer to how many ways are
		// there to reach the goal.
		int[] fib = new int[n+1];
		
		// This loop initializes the first two possibilities (0! and 1!).
		// If zero is the number of steps then the loop does not go to
		// 1.
		while(x <= 1 && x <= n)
		{
			fib[x] = 1;
			x++;
		}
		
		// For every number greater than 1, the answer can be computed 
		// using the Fibonacci sequence. 
		if(y > 1)
		{
			for(int i = 2; i <= n; i++)
			{
				fib[i] = fib[i-1] + fib[i-2]; 
			} 
		}
		
		return fib[n];
		
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int minimum_step_size = 0;
		int maximum_step_size = 0;
		int steps_to_top = 0;
		int answer = 0;
		
		minimum_step_size = 1;
		maximum_step_size = 3;
		steps_to_top = 9;
		answer = bruteForce(minimum_step_size, maximum_step_size, steps_to_top);
		System.out.println(answer);
		
		steps_to_top = 9;
		answer = efficientSolution(steps_to_top);
		System.out.println(answer);
	}

}
