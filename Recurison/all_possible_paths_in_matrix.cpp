/*
Print all possible paths in rigthward and downward direction from
top left cell(0,0) to bottom rigth cell(n-1,m-1) of n x m matrix.
R depicts rigth
D depicts down

example input : 3
        output: RRDD
                RDRD
                RDDR
                DRRD
                DRDR
                DDRR
*/
#include<bits/stdc++.h>
using namespace std;

int totalPaths = 0;
void path(int n, int m, int i, int j, string s)
{
    if (i == n || j == m) {
        return;
    }
    if (i == n - 1 && j == m - 1) {
        cout << s << endl;
        totalPaths++;
        return;
    }
    path(n, m, i, j + 1, s + "R");
    path(n, m, i + 1, j, s + "D");
}
/*
Recursion Tree :-

                  _______________[0,0]_________________
                 /                                     \
          _____[0,1]_____                           ______[1,0]________
         /               \                         /                   \
      [0,2]                [1,1]                  [1,1]                [2,0]
      /   \              /        \             /        \            /      \
     X   [1,2]       [1,2]         [2,1]      [1,2]      [2,1]       [2,1]    X
          /  \        / \          /   \       /  \       /   \       /   \
         X   [2,2]   X  [2,2]    [2,2]  X     X   [2,2]  X   [2,2]  [2,2]  X

X -> out of boundary(no call made further and call is returned).
*/
int main()
{
    path(3, 3, 0, 0, "");
    cout << "Total Paths = " << totalPaths << endl;
    return 0;
}