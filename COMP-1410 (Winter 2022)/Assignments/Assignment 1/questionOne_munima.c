#include <stdio.h>
#include <assert.h>

// choose(n,m) returns how many ways there are to choose m items from
//   a set of n items
// requires: 0 <= m, 0 <= n
int choose(int n, int m) 
{       
    if (m == 0 || m == n)
        return 1;

    else if (m > n)
        return 0;
    
    else
        return choose(n - 1, m) + choose(n - 1, m - 1);
}

int main(void)
{
    assert(choose(0,0) == 1);
    assert(choose(4,2) == 6);
    assert(choose(4,4) == 1);
    assert(choose(2,4) == 0);
    assert(choose(10, 0) == 1);
    assert(choose(0, 10) == 0);
    
    puts("All tests passed.");
    return 0;
}