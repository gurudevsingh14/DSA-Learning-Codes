/*
Question : print the first n+1 whole numbers in lexicographical order.

example input : 13
        output: 0 1 10 11 12 13 2 3 4 5 6 7 8 9
*/
#include<bits/stdc++.h>
using namespace std;

void lexicoOrder(int n, int i)
{
  if (i > n)
    return;
  cout << i << " ";
  for (int j = (i == 0) ? 1 : 0; j <= 9; j++)
    lexicoOrder(n, 10 * i + j);
}
/*
                            0
             /                         / ...so on      \
            1                         2                 9
           / \                       /  \              /  \
         10   2 3..9               20   3 4..9        90  91....so on
        /    \                    /  \                /
      100    11 12..19           200  21 22 ..29      .....so on
     /    \                       /
   1000   101 102 103...109      ....so on
   /
   ....so on
 */
int main()
{
  lexicoOrder(13, 0);
  return 0;
}