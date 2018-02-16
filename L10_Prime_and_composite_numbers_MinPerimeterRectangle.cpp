/*
 An integer N is given, representing the area of some rectangle.
 
 The area of a rectangle whose sides are of length A and B is A * B, and the perimeter is 2 * (A + B).
 
 The goal is to find the minimal perimeter of any rectangle whose area equals N. The sides of this rectangle should be only integers.
 
 For example, given integer N = 30, rectangles of area 30 are:
 
 (1, 30), with a perimeter of 62,
 (2, 15), with a perimeter of 34,
 (3, 10), with a perimeter of 26,
 (5, 6), with a perimeter of 22.
 Write a function:
 
 int solution(int N);
 
 that, given an integer N, returns the minimal perimeter of any rectangle whose area is exactly equal to N.
 
 For example, given an integer N = 30, the function should return 22, as explained above.
 
 Assume that:
 
 N is an integer within the range [1..1,000,000,000].
 Complexity:
 
 expected worst-case time complexity is O(sqrt(N));
 expected worst-case space complexity is O(1).

*/

#include <iostream>
#include <vector>

using namespace std;

// https://app.codility.com/demo/results/trainingAWGAFR-MZE/
int solution(int N) {
    // write your code in C++14 (g++ 6.2.0)
    int result =1000000000;
    
    for(long long i = 1; i * i < N ; i++)
    {
        if (N%i == 0)
        {
            int a = N/i;
            int b = i;
            
            if (result > 2 * (a+b) )
                result = 2 * (a+b);
        }
    }
    
    return result;
}

///////////////////////////////////
// 62%
// 잘못된 계산 및 예외처리...



// https://app.codility.com/demo/results/trainingK3GYFV-334/
int solution_final(int N) {
    // write your code in C++14 (g++ 6.2.0)
    int result =-1;
    
    for(long long i = 1; i * i <= N ; i++)
    {
        if (N%i == 0)
        {
            int a = N/i;
            int b = i;
            
            if (result == -1)
                result = 2 * (a+b);
            else if (result > 2 * (a+b) )
                result = 2 * (a+b);
        }
    }
    
    return result;
}
