#ifndef ANALYSEURLEX_H
#define ANALYSEURLEX_H
#include<iostream>
#include<string>


class AnalyseurLex
{
    public:
        AnalyseurLex();
        //déclarer les ensemples des états

        public: static const int ETAT_0=0; //etat initial
        public: static const int ETAT_1=1; //is Alpha
        public: static const int ETAT_2=2;
        public: static const int ETAT_3=3; // ;
        public: static const int ETAT_4=4; //is Num
        public: static const int ETAT_5=5;
        public: static const int ETAT_6=6;
        public: static const int ETAT_7=7;
        public: static const int ETAT_8=8;
        public: static const int ETAT_9=9; //(
        public: static const int ETAT_10=10; //)
        public: static const int ETAT_11=11;
        public: static const int ETAT_12=12;
        public: static const int ETAT_13=13; //=
        public: static const int ETAT_14=14;
        public: static const int ETAT_15=15;
        public: static const int ETAT_16=16; //>
        public: static const int ETAT_17=17;
        public: static const int ETAT_18=18;
        public: static const int ETAT_19=19; //<
        public: static const int ETAT_20=20;
        public: static const int ETAT_21=21;
        public: static const int ETAT_22=22; //+
        public: static const int ETAT_23=23; //-
        public: static const int ETAT_24=24; //*
        public: static const int ETAT_25=25; //  / div
        public: static const int ETAT_26=26; //  !
        public: static const int ETAT_27=27;
        public: static const int ETAT_28=28;
        public: static const int ETAT_29=29; //&
        public: static const int ETAT_30=30;
        public: static const int ETAT_31=31; // |
        public: static const int ETAT_32=32;
        public: static const int ETAT_33=33; // :
        public: static const int ETAT_34=34; // ','
        public: static const int PUIS=100;
};

#endif // ANALYSEURLEX_H
