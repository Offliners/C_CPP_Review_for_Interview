#include<iostream>

using namespace std;

int dc_fibonacci_sequence(int n);

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 9;
    for(int i = 0; i < n; ++i)
        cout << "F(" << i << ") = " << dc_fibonacci_sequence(i) << "\n";

    return 0;
}

int dc_fibonacci_sequence(int n)
{
    if(n < 2)
        return 1;
    else
        return dc_fibonacci_sequence(n - 1) + dc_fibonacci_sequence(n - 2);
}