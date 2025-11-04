#include <bits/stdc++.h>
using namespace std;
int Conjecture(int n)
{
    cout << n << " ";
    if (n == 1)
        return 1;
    if (n % 2)
        return Conjecture(3 * n + 1);
    else
        return Conjecture(n / 2);
}
int main()
{
    int n;
    cin >> n;
    Conjecture(n);
}
