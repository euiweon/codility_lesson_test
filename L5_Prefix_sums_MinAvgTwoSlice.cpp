#include "stdafx.h"


#include <iostream>
#include <algorithm>

#include <vector>

/*
A non-empty zero-indexed array A consisting of N integers is given. A pair of integers (P, Q), such that 0 ≤ P < Q < N, is called a slice of array A (notice that the slice contains at least two elements). The average of a slice (P, Q) is the sum of A[P] + A[P + 1] + ... + A[Q] divided by the length of the slice. To be precise, the average equals (A[P] + A[P + 1] + ... + A[Q]) / (Q − P + 1).

For example, array A such that:

    A[0] = 4
    A[1] = 2
    A[2] = 2
    A[3] = 5
    A[4] = 1
    A[5] = 5
    A[6] = 8
contains the following example slices:

slice (1, 2), whose average is (2 + 2) / 2 = 2;
slice (3, 4), whose average is (5 + 1) / 2 = 3;
slice (1, 4), whose average is (2 + 2 + 5 + 1) / 4 = 2.5.
The goal is to find the starting position of a slice whose average is minimal.

Write a function:

int solution(vector<int> &A);
that, given a non-empty zero-indexed array A consisting of N integers, returns the starting position of the slice with the minimal average. If there is more than one slice with a minimal average, you should return the smallest starting position of such a slice.

For example, given array A such that:

    A[0] = 4
    A[1] = 2
    A[2] = 2
    A[3] = 5
    A[4] = 1
    A[5] = 5
    A[6] = 8
the function should return 1, as explained above.

Assume that:

N is an integer within the range [2..100,000];
each element of array A is an integer within the range [−10,000..10,000].
Complexity:

expected worst-case time complexity is O(N);
expected worst-case space complexity is O(N), beyond input storage (not counting the storage required for input arguments).
*/


//https://app.codility.com/demo/results/trainingG7N9SC-RH2/ 
int solution(std::vector<int> &A)
{
	// write your code in C++14 (g++ 6.2.0)
	double result = 10000;
	int result_pos = 0;
	std::vector<int> sumdatalist;
	for (int i = 0; i < (int)A.size() - 1; i++)
	{
		int sum = A[i];
		int count = 1;
		for (int j = i + 1; j < (int)A.size(); j++)
		{
			sum += A[j];
			count++;
			if (result >(float)sum / (float)count)
			{
				result = (float)sum / (float)count;
				result_pos = i;
			}
		}
	}
	return result_pos;
}

/////////////////////////////////////////////////
// 걸린 시간 20분 (50%)
// 문제점
// 시간 복잡도문제가 해결 되지 않음. 
// 해결 방안 
// 문제는 최소값이 되는 시작점의 인덱스만 구하면 되는것
//
//
// 해결 방안을 못 찾아서 풀이법을 찾아보니 최소값 slice 되는 것은 2,3 둘중 하나이므로, 두개의 경우만 검사하면 된다는듯...
// 그래서 만든 코드
// https://app.codility.com/demo/results/trainingNPQNBB-7WM/
int solution_final(std::vector<int> &A)
{
	// write your code in C++14 (g++ 6.2.0)
	double result = 10000;
	int result_pos = 0;
	std::vector<int> sumdatalist;
	for (int i = 0; i < (int)A.size() - 2; i++)
	{
		if (result > (A[i] + A[i + 1] + A[i + 2]) / 3.0f)
		{
			result = (A[i] + A[i + 1] + A[i + 2]) / 3.0f;
			result_pos = i;
		}

		if (result > (A[i] + A[i + 1] ) / 2.0f)
		{
			result = (A[i] + A[i + 1] ) / 2.0f;
			result_pos = i;
		}
	}

	// 마지막 연산이 생략되서 따로 추가... 
	if (result > (A[(int)A.size() - 2] + A[(int)A.size() - 1]) / 2.0f)
	{
		result = (A[(int)A.size() - 2] + A[(int)A.size() - 1]) / 2.0f;
		result_pos = (int)A.size() - 2;
	}

	return result_pos;
}



void main()
{
	std::vector<int> A;
	A.resize(7);
	A[0] = 4;
	A[1] = 2;
	A[2] = 2;
	A[3] = 5;
	A[4] = 1;
	A[5] = 5;
	A[6] = 8;

	int result = solution(A);
	std::cout << "Result : " << result << std::endl;

}
