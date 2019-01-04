#include <iostream>
#include "src/AnalyseurLex.cpp";
#include<stdio.h>

using namespace std;

int main()
{
    AnalyseurLex1 a;
    a.method();
    cout <<a.KEY <<endl;
    cout << "Hello world! "+a.tabVar[0] << endl;
    return 0;
}
