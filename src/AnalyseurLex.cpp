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

    //Global variable pour analyser ce grammaire lexical
	public :  static int ligne ;
    public :  static int etat;
    public :  static int pos;
	public :  string car;
    public : string tabKeyWord[18] ;
    public : static int offset;
	public : bool succes ;

	//déclarer lexeme et le source
	private : Symbol lexeme;
    private : string source;
    private : Symbol listeLexeme[];
    private : static int indiceLexeme;



    private : void init()
    {
        //initialiser les variables analyse lex
        this->ligne=1;
        this->etat=AnalyseurLex::ETAT_0;
        this->pos=0;
        this->offset=0;
        this->succes=false;
        indiceLexeme=0;
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
        tabKeyWord[15] = "(";
        tabKeyWord[16] = ")";
        tabKeyWord[17] = ":";
        tabKeyWord[18] = ";";
    }

    public : void getCodeSource(string code)
    {
        this->source=code;
    }

    public : string getChar() //equivalent a char
    {
         return this->source.substr(this->offset,1);
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
        while(true)
        {
              switch(this->etat)
              {
                    case AnalyseurLex::ETAT_0 : this->car=getChar();
                                                if(this->car == " " || this->car == "\t");
                                                else
                                                if(isAlpha(this->car)) this->etat=AnalyseurLex::ETAT_1;
                                                else
                                                if(this->car==";") this->etat=AnalyseurLex::ETAT_3;
                                                else
                                                if(isNum(this->car)) this->etat=AnalyseurLex::ETAT_4;
                                                else
                                                if(this->car == "(") this->etat=AnalyseurLex::ETAT_9;
                                                else
                                                if(this->car == ")")  this->etat=AnalyseurLex::ETAT_10;
                                                else
                                                if(this->car == "=") this->etat=AnalyseurLex::ETAT_13;
                                                else
                                                if(this->car == ">") this->etat=AnalyseurLex::ETAT_16;
                                                else
                                                if(this->car == "<") this->etat=AnalyseurLex::ETAT_19;
                                                else
                                                if(this->car == "+") this->etat=AnalyseurLex::ETAT_22;
                                                else
                                                if(this->car == "-") this->etat=AnalyseurLex::ETAT_23;
                                                else
                                                if(this->car == "*") this->etat=AnalyseurLex::ETAT_24;
                                                else
                                                if(this->car == "/") this->etat=AnalyseurLex::ETAT_25;
                                                else
                                                if(this->car == "&") this->etat=AnalyseurLex::ETAT_27;
                                                else
                                                if(this->car == "|") this->etat=AnalyseurLex::ETAT_31;
                                                else
                                                if(this->car == ":") this->etat=AnalyseurLex::ETAT_33;
                                                else
                                                if(this->car == ",") this->etat=AnalyseurLex::ETAT_34;
                                                else
                                                this->etat=AnalyseurLex::PUIS;
                    break;

                    case AnalyseurLex::ETAT_1 : if(isAlphaNum(this->car))
                                                {
                                                     str=str+this->car;
                                                     this->car = getChar();
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
                                                addListeLexeme(this->indiceLexeme , this->listeLexeme , this->lexeme);
                                                this->indiceLexeme++;
                    break;

                    case AnalyseurLex::ETAT_4 : if(isNum(car))
                                                {
                                                    str =str+ car;
                                                    car = getChar();
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

                    case AnalyseurLex::ETAT_6 : //
                    break;

                    case AnalyseurLex::ETAT_7 : //
                    break;

                    case AnalyseurLex::ETAT_8 : //
                    break;


                    case AnalyseurLex::ETAT_10 : //
                    break;

                    case AnalyseurLex::ETAT_11 : //
                    break;

                    case AnalyseurLex::ETAT_12 : //
                    break;

                    case AnalyseurLex::ETAT_13 : //
                    break;

                    case AnalyseurLex::ETAT_14 : //
                    break;
              }
        }
    }
};
