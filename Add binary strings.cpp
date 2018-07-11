#include <iostream>
#include <string>

using namespace std;

string addBinaryStrings(string s1, string s2) {
    int len1 = s1.size();
    int len2 = s2.size();
    if(len1==0) return s2;
    if(len2==0) return s1;
    
    string res;
    int i = len1-1, j = len2 - 1, carry = 0;
    
    while(i>=0&&j>=0){
        int tmp = s1[i--] - '0' + s2[j--] - '0' + carry;
        res = to_string(tmp % 2) + res;
        carry = tmp / 2;
    }
    
    while(i>=0){
        int tmp = s1[i--] - '0' + carry;
        res = to_string(tmp % 2) + res;
        carry = tmp / 2;
    }
    
    while(j>=0){
        int tmp = s2[j--] - '0' + carry;
        res = to_string(tmp % 2) + res;
        carry = tmp / 2;
    }
    
    if(carry) res = "1" + res;
    
    return res;
};

int main()
{
    string res = addBinaryStrings("1100101", "100110010");
    cout<<res<<endl;
    return 0;
}
