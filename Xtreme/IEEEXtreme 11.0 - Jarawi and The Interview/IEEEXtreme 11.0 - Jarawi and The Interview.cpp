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

int quarry(string& s, string& p); // q�ĺ�׺���������s���Ӵ����ַ����ĳ���

int main() {
    string s;
    cin >> s;
    int q;
    cin >> q;
    string p;
    int results[q]; // ��¼��
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
    } // ��ͼ
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


