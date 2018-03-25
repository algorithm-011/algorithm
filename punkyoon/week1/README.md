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

# 이항계수

## 참고 자료

https://en.wikipedia.org/wiki/Binomial_coefficient

## 정의

이항계수는 주어진 크기의 순서 없는 조합의 가짓수다. 즉, n개의 원소에서 k개의 원소를 뽑아내는 방법의 수를 나타낸다.

자연수 n과 정수 k가 주어졌을때, 이항계수 ![bionomial](https://wikimedia.org/api/rest_v1/media/math/render/svg/20897631d805059d3e86b791c9d6b96c0f20abf4)는 다음과 같이 정의 된다.

![bionomial coefficient](https://wikimedia.org/api/rest_v1/media/math/render/svg/af575850eec19a2efa2ac71d38c3a4c7af88bf5d)

이항계수는 ![nCk](https://wikimedia.org/api/rest_v1/media/math/render/svg/846dc3e79abc1db020c2588140a418703f524e9d)로 쓰이기도 한다.

이항계수의 값을 나열한 표를 `파스칼의 삼각형`이라고 한다.

![triangle](https://upload.wikimedia.org/wikipedia/commons/f/f6/Pascal%27s_triangle_5.svg)

이항계수는 다음과 같은 항등식을 만족시킨다.

![identity](https://wikimedia.org/api/rest_v1/media/math/render/svg/9c1be4c4c9a68f088f7e13fe0b16135695cc638c)

또한, 다음과 같은 점화식이 성립하는데, 이는 `파스칼의 법칙`이라고 한다.

![pascal's rule](https://wikimedia.org/api/rest_v1/media/math/render/svg/3027846f5d02235fd0759030edbeae293b76d2e7)

이항계수를 이용하여 피보나치 수를 나타내면 다음과 같다.

![fibonacci](https://wikimedia.org/api/rest_v1/media/math/render/svg/456dc5d1752a1ad898b34c0234fd0c8aaf33d266)

## 재귀를 사용한 구현

간단하게 재귀를 사용하면 다음과 같다.

```cpp
#include <iostream>

using namespace std;

int bionomial(int n, int k)
{
    if(n == k || k == 0)
        return 1;
    return bionomial(n-1, k-1) + bionomial(n-1, k);
}

int main(void)
{
    cout << bionomial(10, 2) << endl;
    return 0;
}
```

`memoization`을 사용하면 다음과 같다.

```cpp
#include <iostream>

using namespace std;

int memo[50][50];

int bionomial(int n, int k)
{
    if (memo[n][k] != 0)
        return memo[n][k];
    else if(n == k || k == 0)
        return memo[n][k] = 1;
    else
        return memo[n][k] = bionomial(n-1, k-1) + bionomial(n-1, k);
}

int main(void)
{
    cout << bionomial(10, 2) << endl;
    return 0;
}
```

# GCD와 LCM

- GCD: 최대공약수
- LCM: 최소공배수

## 유클리드 호제법

최대공약수를 구하는 알고리즘이다.

1. 입력은 m, n(m>n)이다.
2. n이 0이라면 m을 출력하고 종료한다.
3. m이 n으로 나누어 떨어지면, n을 출력하고 알고리즘을 종료한다.
4. 그렇지 않으면, m을 n으로 나눈 나머지를 새롭게 m에 대입하고나서 m과 n을 바꾼 후 3번 과정으로 돌아간다.

## 구현

```cpp
#include <iostream>

using namespace std;

int gcd(int x, int y)
{
    while(true)
    {
        int temp = x % y;
        if(temp == 0)
            return y;
        else
        {
            x = y;
            y = temp;
        }
    }
}

int lcm(int x, int y)
{
    return x * y / gcd(x, y);
}

int main(void)
{
    cout << gcd(50, 40) << endl;
    cout << lcm(5, 6) << endl;

    return 0;
}
```

# 오일러 φ 함수

## 참고 자료

1. https://en.wikipedia.org/wiki/Euler%27s_totient_function
2. https://ko.khanacademy.org/computing/computer-science/cryptography/modern-crypt/v/euler-s-totient-function-phi-function

## 정의

> 오일러 파이함수

1부터 n까지의 양의 정수 중에서 n과 서로소인 것의 개수를 나타내는 함수. φ(n)으로 표기한다.

소수 p의 경우 오일러 파이 함수의 값은 다음과 같이 정의 된다.

![euler's phi function](https://wikimedia.org/api/rest_v1/media/math/render/svg/9f222be570dc2170ecd7c23259f90ab6e0247330)

**예시**

`n = 1`인 경우, `φ(n) = 1`
`n = 10`인 경우, `φ(n) = 4` (1, 3, 7, 9)

## 구현

```cpp
#include <iostream>

using namespace std;

int euler(int n)
{
    int p_cnt = 0;
    int cnt = 1;

    while(cnt <= n)
    {
        int m = n, d = cnt;

        while(m != 0)
        {
            int temp = d;
            d = m;
            m = temp % m;
        }

        if(d == 1)
            p_cnt++;
        cnt++;
    }

    return p_cnt;
}

int main(void)
{
    cout << euler(1) << endl;
    cout << euler(10) << endl;

    return 0;
}
```
