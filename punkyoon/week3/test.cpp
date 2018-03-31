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
