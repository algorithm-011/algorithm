# 피보나치 수

## 참고 자료

1. https://en.wikipedia.org/wiki/Fibonacci_number
2. https://en.wikipedia.org/wiki/Pascal%27s_triangle
3. https://www.acmicpc.net/blog/view/28
4. https://www.holaxprogramming.com/2014/04/24/algorithms-fibo-and-dynamic-programming/
5. https://www.ted.com/talks/arthur_benjamin_the_magic_of_fibonacci_numbers

## 정의

피보나치 수는 다음과 같은 점화식으로 정의된다.

![fibonacci number](https://wikimedia.org/api/rest_v1/media/math/render/svg/00008893a71eebbf4e7d89a0c162fe6359f5ac8c)

행렬 표현을 이용하면 다음과 같이 정의된다.

![fibonacci number matrix](https://wikimedia.org/api/rest_v1/media/math/render/svg/f90aae99d109a6d152d80d03d0353a5e849c560e)

파스칼의 삼각형에서 대각선의 합을 구하면 피보나치 수를 구할 수 있다.

![pascal's triangle](https://upload.wikimedia.org/wikipedia/commons/b/bf/PascalTriangleFibanacci.svg)


## Pisano Period

피사노 주기는 피보나치 수의 주기를 나타낸다.

피보나치 수열의 10번째 항까지의 값들을 11로 나누면 다음과 같다.

n | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10
------------ | ------------- | ------------- | ------------- | ------------- | ------------- | ------------- | ------------- | ------------- | ------------- | -------------
F(n) | 1 | 1 | 2 | 3 | 5 | 8 | 13 | 21 | 34 | 55
F(n) mod 11 | 1 | 1 | 2 | 3 | 5 | 8 | 2 | 10 | 1 | 0

나머지 연산을 했기 때문에 수열에서 주기가 나타날 수 있으며, `K(m)`을 반복하는 부분 수열의 길이라고 하면, `K(11) = 10`임을 알 수 있다.

## 계산

간단하게 재귀를 사용하여 피보나치 수를 구하는 코드는 다음과 같다.

```cpp
#include <iostream>

using namespace std;

int fibonacci(int n)
{
    if(n <= 1)
        return n;
    else
        return fibonacci(n-2) + fibonacci(n-1);
}

int main(void)
{
    for(int i=0; i<10; i++)
        cout << fibonacci(i) << " ";
    cout << endl;

    return 0;
}
```

재귀를 사용하면 중복연산이 발생하므로, 이를 줄이기 위해 `memoization`을 사용하면 다음과 같다.

```cpp
#include <iostream>

using namespace std;

int memo[20];

int fibonacci(int n)
{
    if(n <= 1)
        return n;
    else if(memo[n] != 0)
        return memo[n];
    else
        return memo[n] = fibonacci(n-2) + fibonacci(n-1);
}

int main(void)
{
    for(int i=0; i<10; i++)
        cout << fibonacci(i) << " ";
    cout << endl;
}
```

# Prime number

## 참고 자료

1. https://en.wikipedia.org/wiki/Prime_number
2. 
3. 

## 정의

약수가 1과 자기 자신 뿐인 1보다 큰 자연수로 정의된다.

소수의 개수는 무한하며, 소수를 찾는 가장 간단한 방법은 `에라토스테네스의 체`가 있다.

## 에라토스테네스의 체

1. 찾고자 하는 범위의 자연수를 나열한다.
2. 2부터 시작하여, 2의 배수를 지워나간다.
3. 소수의 배수를 모두 지운다.

이 과정을 반복하여 마지막까지 지우면, 남는 수들이 소수가 된다.

이를 코드로 나타내면 다음과 같다.

```cpp
#include <iostream>

using namespace std;

int eratosthenes(int n)
{
    if(n == 1)
        return 0;

    for(int i=2; i*i<=n; i++)
    {
        if(n % i == 0)
            return 0;
    }

    return n;
}

int main(void)
{
    int n[168] = {0, }, cnt = 0;

    for(int i=2; i<1000; i++)
    {
        if(eratosthenes(i) == i)
        {
            n[cnt] = i;
            cnt++;
        }
    }

    cout << "count: " << cnt << endl;

    for(int i=0; i<168; i++)
    {
        if(i % 10 == 0)
            cout << endl;
        cout << n[i] << " ";
    }
    cout << endl;

    return 0;
}
```
