#include <iostream>
using namespace std;
int main()
{
    // int content[4][5]={0};
    // for (int i = 0; i < 3; ++i)
    // {
    //     for (int j = 0; j < 4; ++j)
    //     {
    //         cin >> content[i][j];
    //     }
    // }
    // for (int i = 0; i < 3; ++i)
    // {
    //     for (int j = 0; j < 4; ++j)
    //     {
    //         content[i][4]+=content[i][j];
    //         content[3][j]+=content[i][j];
    //         cout<<content[i][j]<<"  ";
    //     }
    //     cout<<"row_sum:" <<content[i][4]<<endl;
    // }
    // cout<<"colum_sum:"<<endl;
    // cout<<content[3][0]<<"  "<<content[3][1]<<"  "<<content[3][2]<<"  "<<content[3][3]<<endl;
    int a =5,b=5,i,j;
    i = (a++)+(a++);
    j = (++b)+(++b);
    cout<<i<<"+++"<<j<<endl;
    system("pause");
    return 0;
}