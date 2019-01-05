#include "AnalyseurLex.h"
#include <iostream>
#include<string.h>
#include<stdio.h>

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
	public :  char car;
    public : string tabLexeme [10] ;
    public : static int offset;
	public : bool succes ;

    public : void init()
    {
        //initialiser les variables analyse lex
        this->ligne=1;
        this->etat=AnalyseurLex::ETAT_0;
        this->pos=0;
        this->offset=0;
        this->succes=false;
    }


    public: void initTab()
    {
        tabLexeme[0]  = "program";
        tabLexeme[1]  = "var";
        tabLexeme[2]  = "integer";
        tabLexeme[3]  = "char";
        tabLexeme[4]  = "begin";
        tabLexeme[5]  = "end";
        tabLexeme[6]  = "if";
        tabLexeme[7]  = "then";
        tabLexeme[8]  = "else";
        tabLexeme[9]  = "while";
        tabLexeme[10] = "do";
        tabLexeme[11] = "read";
        tabLexeme[12] = "readln";
        tabLexeme[13] = "write";
        tabLexeme[14] = "writeln";
        tabLexeme[15] = "(";
        tabLexeme[16] = ")";
        tabLexeme[17] = ":";
        tabLexeme[18] = ";";
    }

};


