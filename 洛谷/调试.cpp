#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<char> v;
    char a;
    cin >> a;
    while (a != '0') {
        v.push_back(a);
        cin >> a;
    }
    cout << "读入完毕，现在输出" << endl;
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
    return 0;
}
//自动代码补全，CodeGeeX自动预测代码，错误实时检查，并且报错信息汉化后显示在代码行内，光标平滑移动，再配上
//这炫酷的黑色，我的天哪，太爽了！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
//就是这里，输出的哪一行汉字，不知道是什么编码问题，显示不出来，但是不影响程序运行，所以我就不管了，哈哈
//看到刚刚那个预测没有，太只能了。