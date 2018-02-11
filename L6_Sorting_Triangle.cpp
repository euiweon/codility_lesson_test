//A zero-indexed array A consisting of N integers is given. A triplet (P, Q, R) is triangular if 0 ≤ P < Q < R < N and:
//
//A[P] + A[Q] > A[R],
//A[Q] + A[R] > A[P],
//A[R] + A[P] > A[Q].
//For example, consider array A such that:
//
//A[0] = 10    A[1] = 2    A[2] = 5
//A[3] = 1     A[4] = 8    A[5] = 20
//Triplet (0, 2, 4) is triangular.
//
//Write a function:
//
//int solution(vector<int> &A);
//that, given a zero-indexed array A consisting of N integers, returns 1 if there exists a triangular triplet for this array and returns 0 otherwise.
//
//For example, given array A such that:
//
//A[0] = 10    A[1] = 2    A[2] = 5
//A[3] = 1     A[4] = 8    A[5] = 20
//the function should return 1, as explained above. Given array A such that:
//
//A[0] = 10    A[1] = 50    A[2] = 5
//A[3] = 1
//the function should return 0.
//
//Assume that:
//
//N is an integer within the range [0..100,000];
//each element of array A is an integer within the range [−2,147,483,648..2,147,483,647].
//Complexity:
//
//expected worst-case time complexity is O(N*log(N));
//expected worst-case space complexity is O(N), beyond input storage (not counting the storage required for input arguments).
#include <iostream>
#include <vector>


// https://app.codility.com/demo/results/training9HH845-V9A/
int solution(std::vector<int> &A)
{
    if(A.size() < 3)
        return 0;
    
    for (int i = 0; i < (int)A.size(); i++)
    {
        for (int j = i+1; j < A.size(); j++)
        {
            for (int k = j+1; k < A.size();k++)
            {
                if (i == j || i == k || j == k)
                    continue;
                if (A[i] + A[j] > A[k] &&A[i] + A[k] > A[j]&&A[j] + A[k] > A[i] )
                    return 1;
                
            }
        }
    }
    return 0;
}
// 윗 코드의 문제점 추론
// 작동 시간이 오래걸림 N^3 -> N*log(N) 수준으로 줄여야 함
// 공간복잡도를 O(N) 수준으로 만들라고 했는데 사용하지 않음.
// int 범위를 벗어난 숫자들의 처리가 안됨.

// 문제 파악
// 삼각형이 존재하는지 여부만 구하면 됨.
// int -> int64_t

//https://app.codility.com/demo/results/trainingX2BS6J-2KD/
#include <algorithm>
int solution_final(std::vector<int> &A)
{
    if(A.size() < 3)
        return 0;
    
    
    // 정렬
    std::sort(A.begin(),A.end(), [](const int & A,
                                    const int & B) -> bool  {
        return A<B;
    });
    
    
    for (int i = 2; i < A.size(); i++)
    {
        if ((int64_t)A[i-2] + (int64_t)A[i-1] > (int64_t)A[i])
            return 1;
    }
    return 0;
}



//int main()
//{
//    std::vector<int> A;
//    A.resize(4);
//
//    A[0]= 10;
//    A[1] = 50;
//    A[2] = 5;
//    A[3] = 1;
//
//    int result = solution_final(A);
//
//    std::cout << "solution result 1 " <<result << std::endl ;
//
//
//    A.resize(6);
//
//    A[0] = 10;
//    A[1] = 2;
//    A[2] = 5;
//    A[3] = 1;
//    A[4] = 8;
//    A[5] = 20;
//    result = solution_final(A);
//
//    std::cout << "solution result 2 " <<result << std::endl ;
//
//    return 0;
//}

