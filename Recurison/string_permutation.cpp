/*
To print all possible permutations of a string.

Example input : ABC
        output: ABC
                ACB
                BAC
                BCA
                CBA
                CAB
*/
#include<bits/stdc++.h>
using namespace std;
void stringPermutations(string s, int l, int r)
{
    if (l == r)
    {
        cout << s << endl;
        return;
    }
    for (int i = l; i <= r; i++)
    {
        swap(s[i], s[l]);
        stringPermutations(s, l + 1, r);
        swap(s[i], s[l]);
    }
}
/*
                    _______ABC_______
                   /        |        \
                 ABC       BAC       CBA
                /  \      /   \     /   \
             ABC   ACB  BAC   BCA  CBA  CAB                            
*/
int main()
{
    stringPermutations("ABC", 0, 2);
    return 0;
}