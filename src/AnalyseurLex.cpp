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


    public: void method()
    {
    printf("%d \n",AnalyseurLex::ETAT_0);
    }
};


