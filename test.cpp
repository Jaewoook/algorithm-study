#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
bool eratos_field[10001] = { 0, };
int prime[10001] = { 0, };
int pn = 0;

void eratos(void)//에라토스테네스의 체 구현하기
{
    for (long long int i = 2; i <= sqrt(10001); i++)
    {
        if (eratos_field[i] == false)
        {
            prime[pn++] = i;
        }
        for (int j = i + i; j <= 10001; j += i)
        {
            eratos_field[j] = true;
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    eratos();
    int n, t;
    cin >> t;

    while (t--)
    {
        cin >> n;
        int min_gap = 10000,gap=0,l_ans,r_ans;
        if (n == 0)
        {
            return 0;
        }
        else
        {
            for (int i = 0; prime[i]<=n/2; i++)
            {
                cout << prime[i] << "\n";
                if (eratos_field[n - prime[i]] == false)
                {
                    gap = (n-prime[i])-prime[i];
                    if (min_gap > gap)
                    {
                        min_gap = gap;
                        l_ans = n - prime[i];
                        r_ans = prime[i];
                        cout << '\n' << r_ans << ' ' << l_ans << "   " << min_gap << '\n';
                    }
                }
            }
        }
        cout << "\n=======================\n";
        cout <<r_ans << ' ' << l_ans;
        cout << "\n=======================\n";
    }
    return 0;
}