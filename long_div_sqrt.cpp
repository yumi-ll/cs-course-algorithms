#include <iostream>

using namespace std;
long long sqrt(long long);
long long power10(long long);

int main()
{
    long long x, ans;
    ans = 0;
    cout << "Input an integer: ";
    cin >> x;
    ans = sqrt(x);
    cout << "The square root of " << x << ": " << ans << "\n";

    return 0;
}

long long sqrt(long long x)
{
    long long ans = 0;
    long long digit2 = 0;

    // find digit2 of dec
    for(int i = 0; ; i += 2)
    {
        if (x - x % power10(i) == 0) break;
        digit2 += 2;
    }
    long long q, r;
    q = r = 0;

    // long division method of sqrt
    for(long long j = digit2 - 2; j >= 0; j -= 2)
    {
        q *= 10;
        r = r + (x - x % power10(j));
        long long i = 0;
        for(; (q + i) * i * power10(j) <= r; i++)
        {
            if (i == 10)
            {
                i = 1;
                break;
            }
        }
        i -= 1;
        ans += i * power10(j / 2);
        x = x % power10(j);
        r = r - (q + i) * i * power10(j);
        q = (q + i) + i;
    }
    return ans;
}

long long power10(long long x)
{
    long long n = 1;
    for (int i = 0; i < x; i++) n *= 10;
    return n;
}
