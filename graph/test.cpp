#include<bits/stdc++.h>
#include "trieDtype.cpp"

using namespace std;

int main(){
    trie<int, int, int> tr;
    tr.first = 10;
    tr.second = 20;
    tr.third = 30;
    cout<<"first: "<<tr.first<<endl;
    cout<<"second: "<<tr.second<<endl;
    cout<<"third: "<<tr.third<<endl;
    return 0;
}