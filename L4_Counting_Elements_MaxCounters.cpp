#include "stdafx.h"

/*
You are given N counters, initially set to 0, and you have two possible operations on them:

increase(X) − counter X is increased by 1,
max counter − all counters are set to the maximum value of any counter.
A non-empty zero-indexed array A of M integers is given. This array represents consecutive operations:

if A[K] = X, such that 1 ≤ X ≤ N, then operation K is increase(X),
if A[K] = N + 1 then operation K is max counter.
For example, given integer N = 5 and array A such that:

A[0] = 3
A[1] = 4
A[2] = 4
A[3] = 6
A[4] = 1
A[5] = 4
A[6] = 4
the values of the counters after each consecutive operation will be:

(0, 0, 1, 0, 0)
(0, 0, 1, 1, 0)
(0, 0, 1, 2, 0)
(2, 2, 2, 2, 2)
(3, 2, 2, 2, 2)
(3, 2, 2, 3, 2)
(3, 2, 2, 4, 2)
The goal is to calculate the value of every counter after all operations.

Write a function:

vector<int> solution(int N, vector<int> &A);
that, given an integer N and a non-empty zero-indexed array A consisting of M integers, returns a sequence of integers representing the values of the counters.

The sequence should be returned as:

a structure Results (in C), or
a vector of integers (in C++), or
a record Results (in Pascal), or
an array of integers (in any other programming language).
For example, given:

A[0] = 3
A[1] = 4
A[2] = 4
A[3] = 6
A[4] = 1
A[5] = 4
A[6] = 4
the function should return [3, 2, 2, 4, 2], as explained above.

Assume that:

N and M are integers within the range [1..100,000];
each element of array A is an integer within the range [1..N + 1].
Complexity:

expected worst-case time complexity is O(N+M);
expected worst-case space complexity is O(N), beyond input storage (not counting the storage required for input arguments).

*/


//https://app.codility.com/demo/results/training8GA9DW-TC2/
#include <iostream>
#include <vector>
std::vector<int> solution(int N, std::vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)
	std::vector<int> result(N, 0);
	int maxcount = 0;
	for (int i = 0; i < (int)A.size(); i++)
	{
		if (A[i] == N + 1)
		{
			for (int j = 0; j < N; j++)
			{
				result[j] = maxcount;
			}
		}
		else if (1 <= A[i] && N > A[i])
		{
			result[A[i] - 1]++;
			if (maxcount < result[A[i] - 1])
				maxcount = result[A[i] - 1];
		}
	}

	return result;
}

/////////////////////////////////////////////////
// 걸린 시간 15분 (66%)
// 문제점
// 시간 복잡도문제 O(N*M)이 아니라 O(N+M)으로 나와야 함
// 하나만 들어 왔을때 예외처리
//
// 해결 방안 
// MAXCounter를 수집해뒀다가 마지막에 일괄 연산
// 1개일 경우에 대해서도 예외처리 하자. 


// https://app.codility.com/demo/results/trainingTX7NZG-NBP/
std::vector<int> solution_final(int N, std::vector<int> &A) {
	std::vector<int> result(N, 0);
	int tempmaxcount = 0;
	int maxcount = 0;

	for (int i = 0; i < (int)A.size(); i++)
	{
		if (A[i] == N + 1)
		{
			maxcount = tempmaxcount;
		}

		else if (1 <= A[i] && N >= A[i])
		{
			if (maxcount > result[A[i] - 1])
				result[A[i] - 1] = maxcount;

			result[A[i] - 1]++;
			if (tempmaxcount < result[A[i] - 1])
				tempmaxcount = result[A[i] - 1];
		}
	}

	for (int i = 0; i < N; i++)
	{
		if (maxcount > result[i])
			result[i] = maxcount;
	}

	return result;
}



void main()
{
	std::vector<int> A(7,0);
	A[0] = 3;
	A[1] = 4;
	A[2] = 4;
	A[3] = 6;
	A[4] = 1;
	A[5] = 4;
	A[6] = 4;

	auto  result = solution(5, A);

	return;
}