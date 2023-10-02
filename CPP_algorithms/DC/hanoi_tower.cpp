#include<iostream>

using namespace std;

void dc_hanoi_tower(int, char, char, char);

int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 3;
    dc_hanoi_tower(n, 'A', 'C', 'B');

    return 0;
}

void dc_hanoi_tower(int n, char source, char target, char temp)
{
    if(n == 0)
        return;
    
    dc_hanoi_tower(n - 1, source, temp, target);
    cout << "Move disk " << n << " from rod " << source << " to rod " << target << endl;
    dc_hanoi_tower(n - 1, temp, target, source);
}