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

	    public : string tabVar [10] ;

	    public :  static int ligne ;
        public :  static int etat;
     	public :  static int pos;
	    public :  char car;

        public : void init()
        {
            this->ligne=1;
            this->etat=AnalyseurLex::ETAT_0;
            this->pos=0;
        }


    public: void initTab()
    {
        tabVar[0]  = "program";
        tabVar[1]  = "var";
        tabVar[2]  = "integer";
        tabVar[3]  = "char";
        tabVar[4]  = "begin";
        tabVar[5]  = "end";
        tabVar[6]  = "if";
        tabVar[7]  = "then";
        tabVar[8]  = "else";
        tabVar[9]  = "while";
        tabVar[10] = "do";
        tabVar[11] = "read";
        tabVar[12] = "readln";
        tabVar[13] = "write";
        tabVar[14] = "writeln";
        tabVar[15] = "(";
        tabVar[16] = ")";
        tabVar[17] = ":";
        tabVar[18] = ";";
    }


};


