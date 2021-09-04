#include<bits/stdc++.h>

using namespace std;

//////////////////////////////////////////////SOLUTION1//////////////////////////////////////////////////////////

// Time:O(Nlog(logN)) , space:O(N)
vector<long long> SieveOfEratosthenes(long long n) 
{ 
	// Create a boolean array "prime[0..n]" and initialize 
	// all entries it as true. A value in prime[i] will 
	// finally be false if i is Not a prime, else true. 
	bool prime[n+1]; 
	memset(prime, true, sizeof(prime)); 

	for (long long p=2; p*p<=n; p++) 
	{ 
		// If prime[p] is not changed, then it is a prime 
		if (prime[p] == true) 
		{ 
			// Update all multiples of p greater than or 
			// equal to the square of it 
			// numbers which are multiple of p and are 
			// less than p^2 are already been marked. 
			for (long long i=p*p; i<=n; i += p) 
				prime[i] = false; 
		} 
	} 
    vector<long long> ans;
	// Print all prime numbers 
	for (long long p=2; p<=n; p++) 
	    if (prime[p]) ans.push_back(p);
	    
    return ans;		
}

long long log_a_to_base_b(long long a, long long b) 
{ 
    return log(a)/log(b); 
} 

// O(Nlog(logN) + N), space:O(N);
// based on prime factorisation
long long getSmallestDivNum(long long n)
{
    // get all the primes till n
    auto pr=SieveOfEratosthenes(n);
    // for each prime factor take its max power 
    long long ans=1;
    for(auto i:pr) {
        auto t=log_a_to_base_b(n,i);
        ans*=pow(i,t);
    }
    return ans;
}

//////////////////////////////////////////////SOLUTION2//////////////////////////////////////////////////////////

/*
If you observe carefully the ans must be the LCM of the numbers 1 to n.
To find LCM of numbers from 1 to n –

Initialize ans = 1.
Iterate over all the numbers from i = 1 to i = n.
At the i’th iteration ans = LCM(1, 2, …….., i). This can be done easily as LCM(1, 2, …., i) = LCM(ans, i).
Thus at i’th iteration we just have to do –
ans = LCM(ans, i) 
         = ans * i / gcd(ans, i) [Using the below property,
                                 a*b = gcd(a,b) * lcm(a,b)]
*/

// Function returns the lcm of first n numbers 
long long lcm(long long n) 
{ 
	long long ans = 1;	 
	for (long long i = 1; i <= n; i++) 
		ans = (ans * i)/(__gcd(ans, i)); 
	return ans; 
} 

// Driver program to test the above function 
int main() 
{ 
	long long n = 20; 
	cout << lcm(n); 
	return 0; 
} 
