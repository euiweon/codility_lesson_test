/*
You are given two non-empty zero-indexed arrays A and B consisting of N integers. Arrays A and B represent N voracious fish in a river, ordered downstream along the flow of the river.

The fish are numbered from 0 to N − 1. If P and Q are two fish and P < Q, then fish P is initially upstream of fish Q. Initially, each fish has a unique position.

Fish number P is represented by A[P] and B[P]. Array A contains the sizes of the fish. All its elements are unique. Array B contains the directions of the fish. It contains only 0s and/or 1s, where:

0 represents a fish flowing upstream,
1 represents a fish flowing downstream.
If two fish move in opposite directions and there are no other (living) fish between them, they will eventually meet each other. Then only one fish can stay alive − the larger fish eats the smaller one. More precisely, we say that two fish P and Q meet each other when P < Q, B[P] = 1 and B[Q] = 0, and there are no living fish between them. After they meet:

If A[P] > A[Q] then P eats Q, and P will still be flowing downstream,
If A[Q] > A[P] then Q eats P, and Q will still be flowing upstream.
We assume that all the fish are flowing at the same speed. That is, fish moving in the same direction never meet. The goal is to calculate the number of fish that will stay alive.

For example, consider arrays A and B such that:

A[0] = 4    B[0] = 0
A[1] = 3    B[1] = 1
A[2] = 2    B[2] = 0
A[3] = 1    B[3] = 0
A[4] = 5    B[4] = 0
Initially all the fish are alive and all except fish number 1 are moving upstream. Fish number 1 meets fish number 2 and eats it, then it meets fish number 3 and eats it too. Finally, it meets fish number 4 and is eaten by it. The remaining two fish, number 0 and 4, never meet and therefore stay alive.

Write a function:

int solution(vector<int> &A, vector<int> &B);

that, given two non-empty zero-indexed arrays A and B consisting of N integers, returns the number of fish that will stay alive.

For example, given the arrays shown above, the function should return 2, as explained above.

Assume that:

N is an integer within the range [1..100,000];
each element of array A is an integer within the range [0..1,000,000,000];
each element of array B is an integer that can have one of the following values: 0, 1;
the elements of A are all distinct.
Complexity:

expected worst-case time complexity is O(N);
expected worst-case space complexity is O(N), beyond input storage (not counting the storage required for input arguments).
*/

#include <vector>

int solution(vector<int> &A, vector<int> &B) {
	// write your code in C++14 (g++ 6.2.0)

	int count = (int)A.size();


	if (A.size() < 2)
		return (int)A.size();
	// 두 물고기가 마주치는 경우는 밑에 있는 물고기가 올라가고
	// 위에 있는 물고기가 내려 갈때만...
	// 위 아래가 서로 [1,0] 인지 검사 후
	// 위에 있는 물고기의 크기가 더 크다 싶으면
	// 한칸 밑으로 값을 내려 보냄. 
	// 반대의 경우는 값을 삭제...
	// 이렇게 루프를 돌리면서 -1이 아닌 수를 카운트 하면 살아남은 물고기 수

	for (int i = 0; i < count - 1; i++)
	{
		if (B[i] == 1 && B[i + 1] == 0)
		{
			if (A[i] < A[i + 1])
			{
				B[i] = 0;
				A[i] = -1;
			}
			else
			{
				B[i + 1] = B[i];
				A[i + 1] = A[i];
				B[i] = 0;
				A[i] = -1;
			}
		}
	}


	int result = 0;
	for (int i = 0; i < count; i++)
	{
		if (A[i] != -1)
			result++;
	}


	return result;
}

/////////////////////////////////////////
// 37%
// 24분
// 문제 파악하는데 오래 걸림
// 문제점
// 총체적 난국... ㅠ.ㅠ 
// 일단 스택을 활용하자


// https://app.codility.com/demo/results/trainingXQWV7W-6V9/
int solution_final(vector<int> &A, vector<int> &B) {
	// write your code in C++14 (g++ 6.2.0)

	int count = (int)A.size();


	vector<int> fishdownlist;
	int upcount = 0;

	for (int i = 0; i < count; i++)
	{
		if (B[i] == 1) {
			fishdownlist.push_back(A[i]);
		}
		else if (B[i] == 0)
		{
			if (fishdownlist.empty())
			{
				upcount++;
			}
			else
			{
				while (1)
				{
					// 밑으로 내려가는 건 다 먹혔으므로 
					// upcount ++;
					if (fishdownlist.empty())
					{
						upcount++;
						break;
					}
					else if (fishdownlist.back() < A[i]) {
						fishdownlist.pop_back();
					}
					else
						break;
				}

			}

		}
	}

	int result = upcount + fishdownlist.size();



	return result;
}

/////////////////////////////////////////
// 100%
// 최종결과로 위로가는 물고기를 앞쪽에 정렬 시키고, 아래로 가는 물고기는 뒤에 정렬
// 앞쪽에 있는 물고기 + 뒷쪽에 있는 물고기 해서 결과값 구함. 

