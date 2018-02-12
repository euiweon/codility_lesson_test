/*
We draw N discs on a plane. The discs are numbered from 0 to N − 1. A zero-indexed array A of N non-negative integers, specifying the radiuses of the discs, is given. The J-th disc is drawn with its center at (J, 0) and radius A[J].

We say that the J-th disc and K-th disc intersect if J ≠ K and the J-th and K-th discs have at least one common point (assuming that the discs contain their borders).

The figure below shows discs drawn for N = 6 and A as follows:

A[0] = 1
A[1] = 5
A[2] = 2
A[3] = 1
A[4] = 4
A[5] = 0


There are eleven (unordered) pairs of discs that intersect, namely:

discs 1 and 4 intersect, and both intersect with all the other discs;
disc 2 also intersects with discs 0 and 3.
Write a function:

int solution(vector<int> &A);

that, given an array A describing N discs as explained above, returns the number of (unordered) pairs of intersecting discs. The function should return −1 if the number of intersecting pairs exceeds 10,000,000.

Given array A shown above, the function should return 11, as explained above.

Assume that:

N is an integer within the range [0..100,000];
each element of array A is an integer within the range [0..2,147,483,647].
Complexity:

expected worst-case time complexity is O(N*log(N));
expected worst-case space complexity is O(N), beyond input storage (not counting the storage required for input arguments).
Copyright 2009–2018 by Codility Limited. All Rights Reserved. Unauthorized copy
*/
#include <vector>

using namespace std;


//https://app.codility.com/demo/results/training3TNUBM-TCN/
// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)
	int result = 0;


	for (int i = 0; i < A.size() - 1; i++)
	{
		int max = i + A[i];
		int min = i - A[i];

		for (int j = i + 1; j < A.size(); j++)
		{
			if (max >= (j - A[j]))
				result++;
		}
	}

	if (result > 10000000)
		result = -1;
	return result;

}
/////////////////////////////////////
// 25분
// 62% 
// 겹쳐지는 부분에 대한 문제를 이해 못해서 오래 걸림
// 문제점
// int 값이 넘어가는 오버플로우
// 빈 배열처리
// N*M의 연산속도가 아니라 N*log(N) 수준으로 줄여야함


int solution2(vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)
	if (A.empty())
		return 0;

	int result = 0;


	for (long long i = 0; i < A.size() - 1; i++)
	{
		long long max = i + A[i];
		long long min = i - A[i];

		for (long long j = i + 1; j < A.size(); j++)
		{
			if (max >= (j - (long long)A[j]))
				result++;
		}
	}
	if (result > 10000000)
		result = -1;
	return result;

}

/////////////////////////////////////
// 25분
// 81% 
// 오버플로우 문제와 빈 배열문제는 처리
// 문제점
// N*M의 연산속도가 아니라 N*log(N) 수준으로 줄여야함



