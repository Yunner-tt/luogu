#include <bits/stdc++.h>
using namespace std;

int main()
{
    // int n = 7000;
    // int **arr = NULL;
    // arr = (int **)malloc(sizeof(int *) * n);
    // for (int i = 0; i < n; ++i)
    // {
    //     arr[i] = (int *)malloc(sizeof(int) * n);
    // }
    // for (int i = 0; i < n; ++i)
    // {
    //     for (int j = 0; j < n; ++j)
    //     {
    //         arr[i][j] = 4;
    //     }
    // }
    // for (int i = 0; i < n; ++i)
    // {
    //     for (int j = 0; j < n; ++j)
    //     {
    //         cout<<arr[i][j]<<endl;
    //     }
    // }
    // if (arr == NULL)
    // {
    //     cout << "ÎÒÊÇ¿ÕµÄ" << endl;
    // }
    // delete[] arr;
    int *a = (int*)malloc(sizeof(int)*100);
    for(int i=0;i<100;++i){
        a[i]=5;
    }
    // memset(a,0,sizeof(a));
    for(int i=0;i<100;++i){
        cout<<a[i]<<endl;
    }
    system("pause");
    return 0;
}
