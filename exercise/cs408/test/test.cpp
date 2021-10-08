#include<bits/stdc++.h>
using namespace std;
int main ()
{
    int count = 0;
    for(count = 0; ; count++)
    {
        if( !malloc(1<<20) )
        {
            break;
        }
    }
    printf("%d\n",count);
    return 0;
}