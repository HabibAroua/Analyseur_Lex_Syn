#include <iostream>
#include "src/AnalyseurLex.cpp";
#include<stdio.h>
#include <regex>

using namespace std;

int main()
{
    int tab[10];
    tab[0]=1;
    tab[1]=2;
    int counts = sizeof(tab)/sizeof(tab[0]);
    printf("count est %d \n ",counts);

/*
string input;
	regex integer("([a-zA-Z]|[[:digit:]])+");
 	//As long as the input is correct ask for another number
 	while(true)
 	{
 		cout<<"Give me an alpha!"<<endl;
 		cin>>input;
 		if(!cin) break;
 		//Exit when the user inputs q
 		if(input=="q")
 			break;
 		if(regex_match(input,integer))
 		    printf("good \n");
 		else
 		{
 			cout<<"Invalid input"<<endl;
 		}
 	}
 	*/

/*
    AnalyseurLex1 a;
    return 0;
    */
}
