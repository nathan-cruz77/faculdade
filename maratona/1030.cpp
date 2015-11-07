#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int josephus(int n, int k)
{
  if (n == 1)
    return 1;
  else
    return (josephus(n - 1, k) + k-1) % n + 1;
}

int main(){
    int n, c, k;
    int i, j;

    cin >> n;
    for(i=0; i<n; i++){
        cin >> c >> k;

        cout << "Case " << i+1 << ": " << josephus(c, k) << endl;
    }

    return 0;
}
