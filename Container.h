#ifndef CONTAINER_H
#define CONTAINER_H

#include <fstream>

#include "Matrix.h"

using namespace std;

//Êîíòåéíåð
struct Container {
    enum { 
        Max_len = 100 
    }; // Ìàêñèìàëüíàÿ äëèíà êîíòåéíåðà

    int Len; // Òåêóùàÿ äëèíà
    Matrix* Cont[Max_len]; //Ìàññèâ ìàòðèö
};

//Ôóíêöèÿ èíèöèàëèçàöèè êîíòåéíåðà
void Init_Container(Container& C);

//Ôóíêöèÿ ââîäà ýëåìåíòîâ â êîíòåéíåð
void In_Container(Container& C, ifstream& ifst);

//Ôóíêöèÿ âûâîä êîíòåéíåðà
void Out_Container(Container& C, ofstream& ofst);

//Ôóíêöèÿ î÷èñòêè êîíòåéíåðà
void Clear_Container(Container& C);

//Ôóíêöèÿ ñîðòèðîâêè êîíòåéíåðà
void Sort(Container& C);
//Ôóíêöèÿ âûâîäà òîëüêî äâóìåðíûõ ìàññèâîâ
void Out_Only_Two_Dim(Container& C, ofstream& ofst);

#endif //CONTAINER_H