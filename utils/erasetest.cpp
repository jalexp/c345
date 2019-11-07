#include <vector>
#include <iostream>
using std::vector;
using std::cout;
using std::endl;
int main(){
    //initializer list of vector requires -std=c++11 compiler flag
    vector<int> vec = {1,2,3,5};

    vec.erase(vec.begin()+1);
    for(int i : vec)
        cout<<i<< " ";
    cout<<endl;
    return 0;
}