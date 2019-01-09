#include <iostream>
#include "src/AnalyseurLex.cpp";
#include "src/AnalyseurLex2.cpp";
#include<stdio.h>
#include <regex>

using namespace std;

int main()
{
    //analyse syntaxique
     //AnalyseurLex2 a;
     //a.analyser();
     AnalyseurLex1 a;
     a.getCodeSource("program ex; var x:integer; begin end.");
     a.lexSuiv();
}


/*
    AnalyseurLex1 a;
    return 0;
    */

