#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct ptr {
    char* last_ptr;
    char* p0;
    char* p1;
    inline void operator++() { if(p1 != last_ptr) { ++p1; } }
};

int quarry(string& s, string& p); // q的后缀中最长的且是s的子串的字符串的长度

int main() {
    string s;
    cin >> s;
    int q;
    cin >> q;
    string p;
    int results[q]; // 记录答案
    for(int i = 0; i < q; i++){ cin >> p; results[i] = quarry(s, p); p.clear(); }
    for(int i = 0; i < q; i++) { cout << results[i] << endl; }
    return 0;
}

int quarry(string& s, string& p) {
    int len = p.size();
    ptr rem[len];
    for(int i = 0 ; i < len ; ++i) { 
        rem[i].p0 =  new char[i+2]; rem[i].p1 = rem[i].p0;
        rem[i].last_ptr = rem[i].p0+i+1;
        for(int j = 0 ; j <= i ; ++j) { ((rem[i]).p0)[j] = p[len-1-i+j]; }
        *(rem[i].last_ptr) = 0;
    } // 制图
    for(int i = 0 ; i < s.size() ; ++i) {
        for(int j = 0 ; j < len ; ++j) {
            if(*(rem[j].p1) == s[i]) { 
                ++rem[j]; 
            }
        }
    }
    int max = 0;
    for(int i = 0 ; i < len ; ++i) {
        if(rem[i].p1 - rem[i].p0 > max) { max = rem[i].p1 - rem[i].p0; }
    }
    return max;
}


