#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<iostream>
using namespace std;
class AnalyseurLex2
{
    public : void analyser()
    {
         char ch, buffer[15], operators[] = "+-*/%><";
	     FILE *fp;
	     int i,j=0;
	     fp = fopen("program.txt","r");
	     if(fp == NULL)
	     {
             cout <<"erreur au niveau de l'ouverture de la fichier"<<endl;
		     exit(0);
	     }

	     while((ch = fgetc(fp)) != EOF)
	     {
	          for(i = 0; i < 7; ++i)
	          {
	               if(ch == operators[i])
	               {
	                    if((operators[i] == '+') || (operators[i] == '-'))
	                    {
	                          printf("%c est opadd \n", ch);
			            }
			            else if((operators[i] == '*') || (operators[i] == '/') || (operators[i] == '%'))
			            {
			                 printf("%c is opmul\n", ch);
			            }
			            else if((operators[i] == '<') || (operators[i] == '>'))
			            {
			                  printf("%c est oprel\n", ch);
                        }
                    }
   		       }

   		       if(isalnum(ch))
   		       {
   		           buffer[j++] = ch;
   		       }
   		       else if((ch == ' ' || ch == '\n') && (j != 0))
   		       {
                    buffer[j] = '\0';
   				    j = 0;

                      char keywords[15][10] = {"program","var","integer","char","begin","end","if",
							"then","else","while","do","read","readln","write","writeln"};
                        int i, test = 0;
                        for(i = 0; i < 15; ++i)
                        {
                            if(strcmp(keywords[i], buffer) == 0)
		                    {
		                         test = 1;
                                 break;
		                    }
                        }
                        if(test==1)
                           printf("%s est un mot clé \n", buffer);

                }

	   }

	fclose(fp);
    }
};
