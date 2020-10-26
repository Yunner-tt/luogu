#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    string result[101];
    string content;
    cin >> n;
    cin >> content;
    for (int i = 1; i <= n; ++i)
    {
        int p;
        string tmp;
        cin >> p;
        switch (p)
        {
        case 1:
            cin >> tmp;
            content+=tmp;
            result[i] = content;
            break;
        case 2:
            int begin, len;
            cin >> begin >> len;
            result[i] = content.substr(begin, len);
            content=result[i];
            break;
        case 3:
            int location;
            cin >> location >> tmp;
            result[i] = content.insert(location, tmp);
            content=result[i];
            break;
        case 4:
            cin >> tmp;
            if(content.find(tmp)!=content.npos){
                int pp = content.find(tmp);
                stringstream ss;
                ss<<pp;
                result[i] = ss.str();
            }
            else result[i]="-1";
            break;
        }
    }
    for(int i=1;i<=n;i++){
        cout<<result[i]<<endl;
    }
    system("pause");
    return 0;
}
/*似乎是一道教会我们使用函数的题目*/