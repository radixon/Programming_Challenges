public class WeeklyChallenge002 {
	// If a number is a multiple of 3, print Fizz.
	// If a number is a multiple of 5, print Buzz.
	// If a number is a multiple of 3 and 5, print FizzBuzz.
	public static void fizzbuzz(int n)
	{
		// Start with the multiples of both 3 and 5, so the program prints and exits if 
		// a multiple of both 3 and 5 is found.  Check for zero as zero is not a multiple
		// of 3 or 5.
		if(n % (3*5) == 0 && n != 0)
		{
			System.out.print("FizzBuzz" + "\t");
		}
		
		// Check for the highest multiple for readability.  Descending in order makes
		// the logic easier to follow.  Check for zero as zero is not a multiple of 5.
		else if(n % 5 == 0 && n != 0)
		{
			System.out.print("Buzz" + "\t");
		}
		
		// Check for the lowest multiple for readability.  Descending in order makes
		// the logic easier to follow.  Check for zero as zero is not a multiple of 5.
		else if(n % 3 == 0 && n != 0)
		{
			System.out.print("Fizz" + "\t");
		}
		
		// Print input if the input is not a ultiple of 3 or 5.
		else
		{
			System.out.print(n + "\t");
		}
	}
	
	public static void main(String [] args)
	{
		for(int i = 0; i < 151; i++)
		{
			fizzbuzz(i);
		}
	}

}
