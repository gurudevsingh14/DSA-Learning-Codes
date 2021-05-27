/*
print all possible binary strings of length n
without consecutive 1's using recursion

example input : 3
        output: 000
                001
                010
                100
                101

*/
#include<bits/stdc++.h>
using namespace std;
void binary(int n, int i, string s)
{
    if (i == n - 1) {
        cout << s << endl;
        return;
    }
    if (s[i] == '0') {
        binary(n, i + 1, s + "0");
        binary(n, i + 1, s + "1");
    }
    else if (s[i] == '1')
    {
        binary(n, i + 1, s + "0");
    }
}
/*
 beginning :  with zero :-        with one :-
                 0                   1
                / \                 /
              00   01              10
             /  \    \            /  \
           000  001  010         100  101    }- all binary strings of length 3.

*/
int main()
{
    binary(3, 0, "0");//call to print all possible binary strings beginning with 0;
    binary(3, 0, "1");//call to print all possible binary strings beginning with 1;
    return 0;
}