/*
A non-empty zero-indexed array A consisting of N integers is given. The product of triplet (P, Q, R) equates to A[P] * A[Q] * A[R] (0 ≤ P < Q < R < N).

For example, array A such that:

A[0] = -3
A[1] = 1
A[2] = 2
A[3] = -2
A[4] = 5
A[5] = 6
contains the following example triplets:

(0, 1, 2), product is −3 * 1 * 2 = −6
(1, 2, 4), product is 1 * 2 * 5 = 10
(2, 4, 5), product is 2 * 5 * 6 = 60
Your goal is to find the maximal product of any triplet.

Write a function:

int solution(vector<int> &A);

that, given a non-empty zero-indexed array A, returns the value of the maximal product of any triplet.

For example, given array A such that:

A[0] = -3
A[1] = 1
A[2] = 2
A[3] = -2
A[4] = 5
A[5] = 6
the function should return 60, as the product of triplet (2, 4, 5) is maximal.

Assume that:

N is an integer within the range [3..100,000];
each element of array A is an integer within the range [−1,000..1,000].
Complexity:

expected worst-case time complexity is O(N*log(N));
expected worst-case space complexity is O(1), beyond input storage (not counting the storage required for input arguments).
*/
#include <vector>

using namespace std;

// you can use includes, for example:
#include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)

	int result = 0;

	int sumdata1 = 0;
	int sumdata2 = 0;

	std::sort(A.begin(), A.end());

	sumdata1 = A.at(A.size() - 1) *A.at(A.size() - 2) * A.at(A.size() - 3);
	sumdata2 = A.at(0) *A.at(1) * A.at(A.size() - 1);             // 음수일 경우

	if (sumdata1 > sumdata2)
		result = sumdata1;
	else
		result = sumdata2;

	return result;

}

