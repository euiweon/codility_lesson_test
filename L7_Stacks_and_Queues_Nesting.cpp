/*
A string S consisting of N characters is called properly nested if:

S is empty;
S has the form "(U)" where U is a properly nested string;
S has the form "VW" where V and W are properly nested strings.
For example, string "(()(())())" is properly nested but string "())" isn't.

Write a function:

int solution(string &S);

that, given a string S consisting of N characters, returns 1 if string S is properly nested and 0 otherwise.

For example, given S = "(()(())())", the function should return 1 and given S = "())", the function should return 0, as explained above.

Assume that:

N is an integer within the range [0..1,000,000];
string S consists only of the characters "(" and/or ")".
Complexity:

expected worst-case time complexity is O(N);
expected worst-case space complexity is O(1) (not counting the storage required for input arguments).

*/

#include <vector>

//https://app.codility.com/demo/results/trainingDWMNM5-GJ9/
int solution(string &S) {
	// write your code in C++14 (g++ 6.2.0)
	int countchar = 0;
	bool firstcheck = false;

	for (int i = 0; i < (int)S.length(); i++)
	{
		if (S.c_str()[i] == '(')
		{
			countchar++;
			firstcheck = true;
		}
		else if (S.c_str()[i] == ')' && !firstcheck)
		{
			return 0;
		}
		else
			countchar--;
	}

	if (countchar == 0)
		return 1;
	else
		return 0;
}

////////////////////////////////////
// 75%
// 문제점
// countchar 변수가 -가 되는 즉시 return 0 를 해야하는 처리를 안했음


//https://app.codility.com/demo/results/training7G84BZ-JJS/
int solution_final(string &S) {
	// write your code in C++14 (g++ 6.2.0)
	int countchar = 0;
	bool firstcheck = false;

	for (int i = 0; i < (int)S.length(); i++)
	{
		if (S.c_str()[i] == '(')
		{
			countchar++;
			firstcheck = true;
		}
		else if (S.c_str()[i] == ')' && !firstcheck)
		{
			return 0;
		}
		else
			countchar--;

		if (countchar < 0)
			return 0;
	}

	if (countchar == 0)
		return 1;
	else
		return 0;
}
