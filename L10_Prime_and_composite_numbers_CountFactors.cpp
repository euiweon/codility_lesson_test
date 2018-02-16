/*
 A positive integer D is a factor of a positive integer N if there exists an integer M such that N = D * M.
 
 For example, 6 is a factor of 24, because M = 4 satisfies the above condition (24 = 6 * 4).
 
 Write a function:
 
 int solution(int N);
 
 that, given a positive integer N, returns the number of its factors.
 
 For example, given N = 24, the function should return 8, because 24 has 8 factors, namely 1, 2, 3, 4, 6, 8, 12, 24. There are no other factors of 24.
 
 Assume that:
 
 N is an integer within the range [1..2,147,483,647].
 Complexity:
 
 expected worst-case time complexity is O(sqrt(N));
 expected worst-case space complexity is O(1).

*/

#include <iostream>
#include <vector>

using namespace std;

// https://app.codility.com/demo/results/trainingM4GV3D-E4E/
int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    long long result = 0;
    for (int i = 1; i * i <= (long long)N ; i++ )
    {
        if (N%i == 0)
        {
            if (N/i == i)
                result++;
            else
                result += 2;
        }
    }
    return (int)result;
}

///////////////////////////////////
// 92%
// int 범위 넘어가는 것 처리 제대로 안함.


int solution_final(int N) {
    // write your code in C++14 (g++ 6.2.0)
    long long result = 0;
    for (long long i = 1; i * i <= (long long)N ; i++ )
    {
        if (N%i == 0)
        {
            if (N/i == i)
                result++;
            else
                result += 2;
        }
    }
    return (int)result;
}

