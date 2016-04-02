//Problem 3.60 from 3rd Edition of Computer Systems Bryant, O'Halloran
long loop(long x, long n)
{
	long result = 0;
	long mask;
	for(mask = 1; mask != 0; mask = mask << (n & 0xFF))
	{
		result |= (x&mask);
	}
	return result;
}
