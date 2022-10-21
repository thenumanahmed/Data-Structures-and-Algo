#include <iostream>
#include <algorithm>
using namespace std;
bool decresing_order(int x, int y)
{
    return x > y;
}
int main()
{
    int a[4] = {256, 33, 5, 63};
    sort(a, a + 4, decresing_order); // sorts in descending order
    for (auto x : a)
        cout << x << endl;
    return 0;
}
