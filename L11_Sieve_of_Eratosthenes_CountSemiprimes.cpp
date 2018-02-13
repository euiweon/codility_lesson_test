/*

A prime is a positive integer X that has exactly two distinct divisors: 1 and X. The first few prime integers are 2, 3, 5, 7, 11 and 13.

A semiprime is a natural number that is the product of two (not necessarily distinct) prime numbers. The first few semiprimes are 4, 6, 9, 10, 14, 15, 21, 22, 25, 26.

You are given two non-empty zero-indexed arrays P and Q, each consisting of M integers. These arrays represent queries about the number of semiprimes within specified ranges.

Query K requires you to find the number of semiprimes within the range (P[K], Q[K]), where 1 ≤ P[K] ≤ Q[K] ≤ N.

For example, consider an integer N = 26 and arrays P, Q such that:

P[0] = 1    Q[0] = 26
P[1] = 4    Q[1] = 10
P[2] = 16   Q[2] = 20
The number of semiprimes within each of these ranges is as follows:

(1, 26) is 10,
(4, 10) is 4,
(16, 20) is 0.
Write a function:

vector<int> solution(int N, vector<int> &P, vector<int> &Q);

that, given an integer N and two non-empty zero-indexed arrays P and Q consisting of M integers, returns an array consisting of M elements specifying the consecutive answers to all the queries.

For example, given an integer N = 26 and arrays P, Q such that:

P[0] = 1    Q[0] = 26
P[1] = 4    Q[1] = 10
P[2] = 16   Q[2] = 20
the function should return the values [10, 4, 0], as explained above.

Assume that:

N is an integer within the range [1..50,000];
M is an integer within the range [1..30,000];
each element of arrays P, Q is an integer within the range [1..N];
P[i] ≤ Q[i].
Complexity:

expected worst-case time complexity is O(N*log(log(N))+M);
expected worst-case space complexity is O(N+M), beyond input storage (not counting the storage required for input arguments).

*/

// you can use includes, for example:
// #include <algorithm>

#include <map>
#include <set>
#include <cmath>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

vector<int> solution(int N, vector<int> &P, vector<int> &Q) {
	// write your code in C++14 (g++ 6.2.0)

	vector<int> result;

	int min = 50000;
	int max = 0;

	// 소수를 구할 범위를 지정하자
	for (int i = 0; i < (int)P.size(); i++)
	{
		if (P[i] < min)
			min = P[i];

		if (Q[i] > max)
			max = Q[i];
	}

	if (min < 2)
		min = 2;


	// 전체 소수를 구하자
	set<int> primecheck;
	vector<int> primeList;
	set<int> semiprimeList;
	for (int i = min; (double)i <= sqrt(max); i++)
	{
		if (primecheck.find(i) != primecheck.end())
			continue;
		for (int j = i + i; j <= max; j += i)
		{
			primecheck.insert(j);
		}
	}

	for (int i = min; i <= max; i++)
	{
		if (primecheck.find(i) == primecheck.end())
		{
			primeList.push_back(i);
		}
	}


	// 최대 범위의 semiPrime 을 구하자
	for (auto prime1 : primeList)
	{
		for (auto prime2 : primeList)
		{
			if (prime1*prime2 <= max && semiprimeList.find(prime1*prime2) == semiprimeList.end())
			{
				semiprimeList.insert(prime1*prime2);

			}
		}
	}

	// 범위 카운트
	for (int i = 0; i < (int)P.size(); i++)
	{
		int count = 0;

		for (auto semiprime : semiprimeList)
		{
			if (P[i] <= semiprime && Q[i] >= semiprime)
				count++;
		}

		result.push_back(count);
	}

	return result;
}
//////////////////////////////////////////////
// 55%
// 40분
// 문제 이해도 오래걸렸고, 에라토스테네스의 채를 이용하는 부분에서 시간이 좀 걸렸다
// 문제점 
// 일단 연산 속도... 줄일 방안을 생각하자



