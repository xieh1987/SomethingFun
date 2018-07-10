#include <iostream>
#include <vector>

using namespace std;

void removeDup(string s) {
    vector<int> mystr(26, 0);
    for(auto& l:s) ++mystr[l-'a'];
    for(auto i=0;i<26;++i){
        if(mystr[i]>0){
            char c = 'a' + i;
            cout<<c;
        }
    }
    return;
};

int main()
{
    removeDup("congratulations");
    return 0;
}
