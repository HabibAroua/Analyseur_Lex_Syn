#include "AnalyseurLex.h"
#include <iostream>
#include<string.h>
#include<stdio.h>
#include <regex>
#include "Symbol.cpp";

using namespace std ;

class AnalyseurLex1
{
    //Les mots clé

    public: const string KEY="KEY";
    public: const string TYPE="TYPE";
	public: const string ID="ID";
	public: const string PRTO="PRTO";
	public: const string PRIF="PRIF";
	public: const string CRO="CRO";
    public: const string CRF="CRF";
	public: const string EGA="EGA";
	public: const string AFC="AFC";
	public: const string PVR="PVR";
	public: const string PGE="PGE";
    public: const string PGQ="PGQ";
	public: const string PPE="PPE";
	public: const string PPQ="PPQ";
	public: const string PLUS="PLUS";
    public: const string MOIS="MOIS";
	public: const string FOIS="FOIS";
    public: const string DIV="DIV";
    public: const string DIF="DIF";
	public: const string NOT="NOT";
	public: const string ET="ET";
	public: const string OU="OU";
	public: const string DEF="DEF";
	public: const string VIR="VIR";
	public: const string MODE="MODE";

    //Global variable pour analyser ce grammaire lexical
	public :  int ligne ;
    public :  int etat;
    public :  int pos;
	public :  string car;
    public :  string tabKeyWord[18] ;
    public :  int offset;
	public :  bool succes ;

	//déclarer lexeme et le source
	public  : Symbol lexeme;
    private : string source;
    private : Symbol listeLexeme[];
    private : int indiceLexeme;



    private : void init()
    {
        //initialiser les variables analyse lex
        this->ligne=1;
        this->etat=AnalyseurLex::ETAT_0;
        this->pos=0;
        this->offset=0;
        this->succes=false;
        this->indiceLexeme=0;
        initTab();
    }


    public: void initTab()
    {
        tabKeyWord[0]  = "program";
        tabKeyWord[1]  = "var";
        tabKeyWord[2]  = "integer";
        tabKeyWord[3]  = "char";
        tabKeyWord[4]  = "begin";
        tabKeyWord[5]  = "end";
        tabKeyWord[6]  = "if";
        tabKeyWord[7]  = "then";
        tabKeyWord[8]  = "else";
        tabKeyWord[9]  = "while";
        tabKeyWord[10] = "do";
        tabKeyWord[11] = "read";
        tabKeyWord[12] = "readln";
        tabKeyWord[13] = "write";
        tabKeyWord[14] = "writeln";

    }

    public : void getCodeSource(string code)
    {
        this->source=code;
    }

    public : string getChar() //equivalent a char
    {
         string temp=this->source.substr(this->offset,1);
         this->offset++;
         this->pos++;
         return temp;
    }

    public : void goBack()
    {
        this->offset--;
        this->pos--;
    }

    private : bool isNum(string car)
    {
        regex integer("[[:digit:]]+");
        return regex_match(car,integer); //preg_match('/^([[:alpha:]])+$/', car);
    }

    private : bool isAlpha(string car)
    {
        regex integer("[a-zA-Z]+");
        return regex_match(car,integer);
    }

    private : bool isID(string car)
    {
        regex integer("[a-zA-Z]([a-zA-Z]|[[:digit:]])*");
        return regex_match(car,integer);
    }

    private : bool isAlphaNum(string car)
    {
        regex integer("([a-zA-Z]|[[:digit:]])+");
        return regex_match(car,integer);
    }

    private : bool isComment(string car)
    {
        return true;
    }

    private : bool isKeyWord(string word)
    {
        for(int i = 0; i <=18; i++)
        {
           if(tabKeyWord[i]== word) return true;
        }
        return false;
    }

    public : void addListeLexeme(int indice , Symbol liste[] , Symbol lexeme)
    {
        liste[indice]=lexeme;
    }

    public : void lexSuiv()
    {
        string str="";
        init();
        char x=13;
        while(true)
        {
              switch(this->etat)
              {
                    case AnalyseurLex::ETAT_0 : this->car=getChar();
                                                if(this->car == " " || this->car == "\t"); //+
                                                else
                                                if(this->car[0] == x){ this->ligne++; this->pos = 0; this->offset++; }
                                                else
                                                if(isAlpha(this->car)){ this->etat=AnalyseurLex::ETAT_1; }
                                                else
                                                if(this->car==";") this->etat=AnalyseurLex::ETAT_3; //
                                                else
                                                if(isNum(this->car)) this->etat=AnalyseurLex::ETAT_4; //
                                                else
                                                if(this->car == "(") this->etat=AnalyseurLex::ETAT_9; //
                                                else
                                                if(this->car == ")")  this->etat=AnalyseurLex::ETAT_10; //
                                                else
                                                if(this->car == "=") this->etat=AnalyseurLex::ETAT_13; // -> ==
                                                else
                                                if(this->car == ">") this->etat=AnalyseurLex::ETAT_16; //
                                                else
                                                if(this->car == "<") this->etat=AnalyseurLex::ETAT_19; //
                                                else
                                                if(this->car == "+") this->etat=AnalyseurLex::ETAT_23; //
                                                else
                                                if(this->car == "-") this->etat=AnalyseurLex::ETAT_24; //
                                                else
                                                if(this->car == "*") this->etat=AnalyseurLex::ETAT_25; //
                                                else
                                                if(this->car == "/") this->etat=AnalyseurLex::ETAT_26; //
                                                else
                                                if(this->car == "&") this->etat=AnalyseurLex::ETAT_27; //
                                                else
                                                if(this->car == "|") this->etat=AnalyseurLex::ETAT_29; //
                                                else
                                                if(this->car == ":") this->etat=AnalyseurLex::ETAT_33;
                                                else
                                                if(this->car == ",") this->etat=AnalyseurLex::ETAT_34;
                                                else
                                                if(this->car == "%") this->etat=AnalyseurLex::ETAT_35; //
                                                else
                                                this->etat=AnalyseurLex::PUIS;
                    break;

                    case AnalyseurLex::ETAT_1 : if(isAlphaNum(this->car))
                                                {
                                                     str=str+this->car;
                                                     car = getChar();
                                                }
                                                else
                                                {
                                                      this->etat=AnalyseurLex::ETAT_2;
                                                }
                    break;
                    case AnalyseurLex::ETAT_2 : this->etat=AnalyseurLex::ETAT_0;
                                                goBack();
                                                if(isKeyWord(str))
                                                {
                                                    this->lexeme.term=str;
                                                    this->lexeme.value=str;
                                                    this->lexeme.def=this->KEY;
                                                }
                                                else
                                                {
                                                    if(isID(str))
                                                    {
                                                         this->lexeme.term="id";
                                                         this->lexeme.value=str ;
                                                         this->lexeme.def= this->ID;
                                                    }
                                                }
                                                addListeLexeme(this->indiceLexeme , this->listeLexeme , this->lexeme);
                                                this->indiceLexeme++;

                    break;

                    case AnalyseurLex::ETAT_3 : this->etat= AnalyseurLex::ETAT_0;
                                                this->lexeme.term=";";
                                                this->lexeme.value=";";
                                                this->lexeme.def=this->PVR;
                                                //addListeLexeme(this->indiceLexeme , listeLexeme , this->lexeme);
                                                this->listeLexeme[0]=lexeme;
                                                printf("l'indice est %d \n",this->indiceLexeme);
                                                this->indiceLexeme++;
                    break;

                    case AnalyseurLex::ETAT_4 : if(isNum(car))
                                                {
                                                    str =str+ this->car;
                                                    this->car = getChar();
                                                    goBack();
							                        this->etat =AnalyseurLex::ETAT_0;

							                        this->lexeme.term = "nb";
                                                    this->lexeme.value = str;
							                        this->lexeme.def  = this->TYPE;
                                                    addListeLexeme(this->indiceLexeme , this->listeLexeme , this->lexeme);
                                                    this->indiceLexeme++;
                                                }

                    break;

                    case AnalyseurLex::ETAT_9 : this->etat = AnalyseurLex::ETAT_0;
							                    this->lexeme.term = "(";
							                    this->lexeme.value = "(";
							                    this->lexeme.def  = this->PRTO;
                                                addListeLexeme(this->indiceLexeme , this->listeLexeme , this->lexeme);
                                                this->indiceLexeme++;
                    break;

                    case AnalyseurLex::ETAT_10 : this->etat = AnalyseurLex::ETAT_0;
							                     this->lexeme.term = ")";
							                     this->lexeme.value = ")";
							                     this->lexeme.def  = this->PRIF;
                                                 addListeLexeme(this->indiceLexeme , this->listeLexeme , this->lexeme);
                                                 this->indiceLexeme++;
                    break;

                    case AnalyseurLex::ETAT_13 : str =str+ this->car;
							                     this->car = getChar();

							                     if(this->car == "=")
								                     this->etat = AnalyseurLex::ETAT_14;

                    break;

                    case AnalyseurLex::ETAT_14 : this->etat =AnalyseurLex::ETAT_0;
						 	                     str =str+ this->car;
							                     this->lexeme.term = "oprel";
							                     this->lexeme.value = str;
                                                 this->lexeme.def  = this->EGA;
                                                 addListeLexeme(this->indiceLexeme , this->listeLexeme , this->lexeme);
                                                 this->indiceLexeme++;

                    break;


                    case AnalyseurLex::ETAT_16 : str = str+this->car;
							                     this->car = getChar();
							                     if(this->car == "=")
                                                     this->etat =AnalyseurLex::ETAT_17;
                                                 else
								                     this->etat =AnalyseurLex::ETAT_18;
                    break;

                    case AnalyseurLex::ETAT_17 : this->etat = AnalyseurLex::ETAT_0;
							                     str = str + this->car;
                                                 this->lexeme.term = "oprel";
                                                 this->lexeme.value = str;
							                     this->lexeme.def  = this->PGE;
                                                 addListeLexeme(this->indiceLexeme , this->listeLexeme , this->lexeme);
                                                 this->indiceLexeme++;
                    break;

                    case AnalyseurLex::ETAT_18 : goBack();
							                     this->etat = AnalyseurLex:: ETAT_0;

                                                 this->lexeme.term = "oprel";
							                     this->lexeme.value = str;
							                     this->lexeme.def  = this->PGQ;
							                     addListeLexeme(this->indiceLexeme , this->listeLexeme , this->lexeme);
                                                 this->indiceLexeme++;
                    break;

                    case AnalyseurLex::ETAT_19 : str = str + this->car; //if supp
							                     this->car = getChar();
                                                 if(this->car == "=")
								                     this->etat = AnalyseurLex::ETAT_20;
							                     else
                                                     {
                                                        if(this->car == ">")
                                                        {
                                                            this->etat = AnalyseurLex::ETAT_21;
                                                        }
                                                        else
                                                        {
                                                              this->etat =AnalyseurLex::ETAT_22 ;
                                                        }
                                                     }
                    break;

                    case AnalyseurLex::ETAT_20 : this->etat =AnalyseurLex::ETAT_0;
							                     str = str + this->car;
							                     this->lexeme.term = "oprel";
							                     this->lexeme.value = str;
                                                 this->lexeme.def  = this->PPE;
                                                 addListeLexeme(this->indiceLexeme , this->listeLexeme , this->lexeme);
                                                 this->indiceLexeme++;
                    break;

                    case AnalyseurLex::ETAT_21 : this->etat =AnalyseurLex::ETAT_0;
							                     str = str + this->car;
							                     this->lexeme.term = "oprel";
							                     this->lexeme.value = str;
                                                 this->lexeme.def  = this->DEF;
                                                 addListeLexeme(this->indiceLexeme , this->listeLexeme , this->lexeme);
                                                 this->indiceLexeme++;
                    break;
                    case AnalyseurLex::ETAT_22 : goBack();
							                     this->etat = AnalyseurLex::ETAT_0;
                                                 this->lexeme.term = "oprel";
                                                 this->lexeme.value = str;
							                     this->lexeme.def  = this->PPQ;
							                     addListeLexeme(this->indiceLexeme , this->listeLexeme , this->lexeme);
                                                 this->indiceLexeme++;
                    break;

                    case AnalyseurLex::ETAT_23 : str = str + this->car;
							                     this->etat = AnalyseurLex::ETAT_0;
							                     this->lexeme.term = "opadd";
							                     this->lexeme.value = str;
                                                 this->lexeme.def  = this->PLUS;
                                                 addListeLexeme(this->indiceLexeme , this->listeLexeme , this->lexeme);
                                                 this->indiceLexeme++;
                    break;

                    case AnalyseurLex::ETAT_24 : str = str + this->car;
							                     this->etat = AnalyseurLex::ETAT_0;
							                     this->lexeme.term = "opadd";
							                     this->lexeme.value = str;
                                                 this->lexeme.def  = this->MOIS;
                                                 addListeLexeme(this->indiceLexeme , this->listeLexeme , this->lexeme);
                                                 this->indiceLexeme++;
                    break;

                    case AnalyseurLex::ETAT_25 : str = str + this->car;
							                     this->etat = AnalyseurLex::ETAT_0;
							                     this->lexeme.term = "opmul";
							                     this->lexeme.value = str;
                                                 this->lexeme.def  = this->FOIS;
                                                 addListeLexeme(this->indiceLexeme , this->listeLexeme , this->lexeme);
                                                 this->indiceLexeme++;
                    break;

                    case AnalyseurLex::ETAT_26 : str = str + this->car;
							                     this->etat = AnalyseurLex::ETAT_0;
							                     this->lexeme.term = "opmul";
							                     this->lexeme.value = str;
                                                 this->lexeme.def  = this->DIV;
                                                 addListeLexeme(this->indiceLexeme , this->listeLexeme , this->lexeme);
                                                 this->indiceLexeme++;
                    break;

                    case AnalyseurLex::ETAT_27 : str = str + this->car;
							                     this->car = getChar();
							                     if(this->car == "&")
                                                     this->etat = AnalyseurLex::ETAT_28;
                                                 else
                                                 {
                                                     goBack();
                                                     this->etat = AnalyseurLex::PUIS;
                                                 }
                    break;

                    case AnalyseurLex::ETAT_28 : this->etat = AnalyseurLex::ETAT_0;
							                     str = str + this->car;
							                     this->lexeme.term = "opmul";
							                     this->lexeme.value = str;
							                     this->lexeme.def  =this->ET;
							                     addListeLexeme(this->indiceLexeme , this->listeLexeme , this->lexeme);
                                                 this->indiceLexeme++;
                    break;

                    case AnalyseurLex::ETAT_29 : str = str + this->car;
							                     this->car = getChar();
							                     if(this->car == "|")
								                     this->etat = AnalyseurLex::ETAT_30;
                                                 else
							                     {
								                      goBack();
								                      this->etat = AnalyseurLex::PUIS;
						                         }
                    break;

                    case AnalyseurLex::ETAT_30 : this->etat =AnalyseurLex::ETAT_0;
                                                 str = str + this->car;
                                                 this->lexeme.term = "opadd";
							                     this->lexeme.value = str;
                                                 this->lexeme.def  =  this->OU;
                    break;

                    case AnalyseurLex::ETAT_35 : str = str + this->car;
							                     this->etat = AnalyseurLex::ETAT_0;
							                     this->lexeme.term = "opmul";
							                     this->lexeme.value = str;
                                                 this->lexeme.def  = this->MODE;
                                                 addListeLexeme(this->indiceLexeme , this->listeLexeme , this->lexeme);
                                                 this->indiceLexeme++;
                    break;

                    case AnalyseurLex::ETAT_33 : this->etat =AnalyseurLex::ETAT_0;
							                     str = str + this->car;
                                                 this->lexeme.term = ":";
                                                 this->lexeme.value = str;
							                     this->lexeme.def  = this->DEF;
                    break;

                    case AnalyseurLex::ETAT_34 : this->etat =AnalyseurLex::ETAT_0;
							                     str = str + this->car;
                                                 this->lexeme.term = ",";
                                                 this->lexeme.value = str;
                                                 this->lexeme.def  = this->VIR;
                    break;

                    case AnalyseurLex::PUIS : // cout << "Erreur Lexical" << endl;
                    break;
                    default : this->etat=AnalyseurLex::PUIS;
            }
        }
    }
};
