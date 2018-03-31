# KMP

## 참고 자료

https://www.geeksforgeeks.org/searching-for-patterns-set-2-kmp-algorithm

## 내용

문자열 검색 알고리즘. O(문자열 크기 + 찾을 문자열 크기) 시간 안에 계산할 수 있다.

기존 주먹구구식 방법으로 한 칸씩 이동하며 문자열을 비교하는 방법을 개선하여, 한 칸씩 이동하며 비교하는 것이 아닌 `Failure function`을 통해 다음 비교 위치로 이동하는 방식이다.

### Failure function

`검색하려는 문자열(S)`의 0 ~ n번째에서, prefix == suffix가 되는 최대 prefix(sufix) 길이.

n | S(i~n) | Pi(n)
------------ | ------------- | -------------
0 | a | 0
1 | ab | 0
2 | `a`b`a` | 1
3 | `abab` | 2
4 | ababc | 0

> 'akaka'의 Pi(4)는 문자열의 절반을 넘는 경우도 계산하기 때문에 1이 아니라 3이다. (`aka`)

### Failure function의 구현

```c++
int* getPi(string str)
{
    int len = str.length(), j = 0;
    int *pi = new int[len];
    pi[0] = 0;

    for (int i=1; i<len; i++)
    {
        while(j > 0 && str[i] != str[j])
            j = pi[j-1];

        if (str[i] == str[j])
            pi[i] = ++j;
    }
    return pi;
}
```

## 구현

```c++
#include <iostream>
#include <vector>

using namespace std;

int* getPi(string str)
{
    int len_p = str.length(), j = 0;
    int *pi = new int[len_p];
    pi[0] = 0;

    for(int i=1; i<len_p; i++)
    {
        while(j > 0 && str[i] != str[j])
            j = pi[j-1];

        if (str[i] == str[j])
            pi[i] = ++j;
    }
    return pi;
}

vector<int> kmp(string t, string p, int * pi)
{
    vector<int> v;
    int j = 0, len_p = (int)p.size(), len_t = (int)t.size();
    for(int i = 0; i < len_t; i++)
    {
        while(t[i] != p[j])
        {
            if(j == 0)
                break;
            j = pi[j - 1];
        }

        if(t[i] == p[j])
        {
            j++;
            if(j == len_p)
            {
                v.push_back(i - len_p + 1);
                j = pi[j - 1];
            }
        }
    }
    return v;
}

int main(void)
{
    string target = "I was lost and beat up. turned out, burned up.";
    string keyword = "up";
    int *pi = getPi(keyword);
    vector<int> v = kmp(target, keyword, pi);

    for(auto iter=v.begin(); iter!=v.end(); iter++)
        cout << *iter << " ";
    cout << endl;

    delete[] pi;
    return 0;
}
```

# Trie

# Aho-corasick

# Rabin-Karp
