#include <bits/stdc++.h>
using namespace std;
int main()
{
    string content;
    string aim;
    int num = 0, pos = 0;
    getline(cin, aim);
    getline(cin, content);
    transform(aim.begin(), aim.end(), aim.begin(), ::tolower);
    transform(content.begin(), content.end(), content.begin(), ::tolower);
    // stringstream ss(content);
    // while (ss >> content)
    // {
    //     if(aim==content){
    //         num++;
    //     }
    //     if(!num) {
    //         pos+=content.size();
    //         pos++;
    //     }
    // }
    aim=aim+' ';
    content.insert(content.begin(),' ');
    aim.insert(aim.begin(),' ');
    while (content.find(aim) != -1)
    {
        if (!num)
            pos = content.find(aim);
        num++;
        content = content.substr(content.find(aim) + aim.size() - 1);
    }

    if (num!=0)
        cout << num << " " << pos << endl;
    else
        cout << "-1" << endl;
    system("pause");
    return 0;
}
/*想到这个匹配方法的真是个鬼才，这里我想了很久，如果逐个提取匹配的话，又会因为第一个输入的不是字母而出现位置的错误，所以苦恼了很久啊，在目标字符前后加空格字符不就行了吗！！！！*/