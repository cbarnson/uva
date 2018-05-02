// 10892 - LCM Cardinality
// Accepted solution
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b)
{
    return a * (b / gcd(a, b));
}

vector<int> getDivisors(int n)
{
    vector<int> v;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (n / i == i)
            {
                v.push_back(i);
            }
            else
            {
                v.push_back(i);
                v.push_back(n / i);
            }
        }
    }
    sort(v.begin(), v.end());
    return v;
}

void printAll(vector<int> &v)
{
    for (auto i : v)
    {
        printf("%d ", i);
    }
    printf("\n");
}

int main()
{
    int n;

    while (cin >> n && n)
    {
        // get all divisors of the number
        int c = 1;
        vector<int> divs = getDivisors(n);
        for (unsigned int i = 0; i < divs.size() - 1; i++)
        {
            for (unsigned int j = i + 1; j < divs.size(); j++)
            {
                if (lcm(divs[i], divs[j]) == n)
                {
                    c++;
                }
            }
        }
        printf("%d %d\n", n, c);
    }

    return 0;
}
