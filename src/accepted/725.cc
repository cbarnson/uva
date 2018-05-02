// 725 - Division
// Accepted solution
#include <iostream>

using namespace std;

int main()
{
    int n;
    bool first = true;
    while (cin >> n && n)
    {
        if (first)
        {
            first = false;
        }
        else
        {
            cout << endl;
        }
        int c = 0;
        for (int f = 1234; f <= 98765 / n; f++)
        {
            int a = f * n;
            int used = (f < 10000);
            int tmp = a;
            while (tmp)
            {
                used |= 1 << (tmp % 10);
                tmp /= 10;
            }
            tmp = f;
            while (tmp)
            {
                used |= 1 << (tmp % 10);
                tmp /= 10;
            }
            if (used == (1 << 10) - 1)
            {
                c++;
                printf("%0.5d / %0.5d = %d\n", a, f, n);
            }
        }
        if (!c)
        {
            printf("There are no solutions for %d.\n", n);
        }
    }

    return 0;
}