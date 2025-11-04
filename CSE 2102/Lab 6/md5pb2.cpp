#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    int i = 0;
    while (s[i] == '1')
    {
        s[i] = '0';
        ++i;
    }
    s[i] = '1';
    reverse(s.begin(), s.end());
    cout << s << "\n";
    return 0;
}
