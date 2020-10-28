# 本文档为字符串练习总结文档
> ## 字符串读取
>> ### getchar()
>> 该函数意思为：读取并拿走，一般可以这样使用：<br>`while ((tmp = getchar())!='\n')`
>> 代表逐字符拿取并读出以行为单位

>> ### gets()
>> 该函数配合char数组使用，读取一行直到换行(空格也读):<br>
>> `char a[10]`<br>`gets(a)`<br>
>> 这样通过遍历数据也能达到逐个读取的目的

>> ### getline()
>> 该函数配合string使用，读取一行直到换行(空格也读):<br>
>> `string ss`<br>`getline(cin,ss)`<br>
>> eg:string类型是有[ ]操作符的，跟数组意义一样
---
> ## 字符串处理
>> ### `toupper(int a)`
>> c语言库函数<ctype.h>内容，将char类型转化为大写(小写为**tolower(int a)**)<br>
>> `char a`<br>`toupper(a)`
>> <br>实现源码:
>> ``` 
>> int toupper(int c)  
>> {  
>>     if ((c >= 'a') && (c <= 'z'))  
>>         return c + ('A' - 'a');  
>>     return c;  
>> } 
>> ```
>> 

>> ### `transform(input.begin(), input.end(), input.begin(), ::tolower)`
>>  这是c++ STL string里面的函数，里面其中input是Stirng类型(小声bb，其实也是调用上面的操作)<br>
>> `string input`<br>`transform(input.begin(), input.end(), input.begin(), ::tolower)`
>> 
---
> ## 杂项
>> ### `strlen(a)`
>>  返回char数组的实际大小，而不是开辟时的最大容量<br>
>> `char a[100]`<br>`strlen(a)!=100`

>> ### `sizeof(a)`
>>  返回char数组的最大容量<br>
>> `char a[100]`<br>`strlen(a)=100`

>> 
# 遗留问题
## 1. ~~`if(!(cin>>a))`关于这个a类型的问题。~~ 答:因为char类型基本上都能装，怎么会想char类型的回滚呢。。。。。一般用于数字(也就是我暂时没有发现其他用法)