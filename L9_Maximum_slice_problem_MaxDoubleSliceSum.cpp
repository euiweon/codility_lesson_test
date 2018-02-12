/*
A non-empty zero-indexed array A consisting of N integers is given.

A triplet (X, Y, Z), such that 0 ≤ X < Y < Z < N, is called a double slice.

The sum of double slice (X, Y, Z) is the total of A[X + 1] + A[X + 2] + ... + A[Y − 1] + A[Y + 1] + A[Y + 2] + ... + A[Z − 1].

For example, array A such that:

A[0] = 3
A[1] = 2
A[2] = 6
A[3] = -1
A[4] = 4
A[5] = 5
A[6] = -1
A[7] = 2
contains the following example double slices:

double slice (0, 3, 6), sum is 2 + 6 + 4 + 5 = 17,
double slice (0, 3, 7), sum is 2 + 6 + 4 + 5 − 1 = 16,
double slice (3, 4, 5), sum is 0.
The goal is to find the maximal sum of any double slice.

Write a function:

int solution(vector<int> &A);

that, given a non-empty zero-indexed array A consisting of N integers, returns the maximal sum of any double slice.

For example, given:

A[0] = 3
A[1] = 2
A[2] = 6
A[3] = -1
A[4] = 4
A[5] = 5
A[6] = -1
A[7] = 2
the function should return 17, because no double slice of array A has a sum of greater than 17.

Assume that:

N is an integer within the range [3..100,000];
each element of array A is an integer within the range [−10,000..10,000].
Complexity:

expected worst-case time complexity is O(N);
expected worst-case space complexity is O(N), beyond input storage (not counting the storage required for input arguments).

*/
#include <vector>

using namespace std;



int solution(vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)
	std::vector<int> frontsum(A.size(), 0);
	std::vector<int> backsum(A.size(), 0);

	int result = 0;


	for (int i = 1; i < A.size() - 1; i++) {
		frontsum[i] = frontsum[i - 1] + A[i];
		if (frontsum[i] <  0)
			frontsum[i] = 0;
	}

	for (int i = A.size() - 2; i > 0; i--)
	{

		backsum[i] = backsum[i + 1] + A[i];

		if (backsum[i] <  0)
			backsum[i] = 0;
	}

	for (int i = 0; i < frontsum.size(); i++)
	{
		if (result < backsum[i + 1] + frontsum[i - 1])
			result = backsum[i + 1] + frontsum[i - 1];
	}


	return result;

}
//////////////////////////////////////////////
// 69% 
// 25분
// 의외로 로직 자체는 금방 생각났는데, 코드로 옮기는데 시간이 좀 걸림
// 문제점 
// 마지막에 for 돌리는 범위가 잘못 되었음. 



//https://app.codility.com/demo/results/trainingM2PXDK-6N5/
int solution_final (vector<int> &A) {
	// write your code in C++14 (g++ 6.2.0)
	std::vector<int> frontsum(A.size(), 0);
	std::vector<int> backsum(A.size(), 0);

	int result = 0;


	for (int i = 1; i < A.size() - 1; i++) {
		frontsum[i] = frontsum[i - 1] + A[i];
		if (frontsum[i] <  0)
			frontsum[i] = 0;
	}

	for (int i = A.size() - 2; i > 0; i--)
	{

		backsum[i] = backsum[i + 1] + A[i];

		if (backsum[i] <  0)
			backsum[i] = 0;
	}

	for (int i = 1; i < frontsum.size() - 1; i++)
	{
		if (result < backsum[i + 1] + frontsum[i - 1])
			result = backsum[i + 1] + frontsum[i - 1];
	}


	return result;

}
