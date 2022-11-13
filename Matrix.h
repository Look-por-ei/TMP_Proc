#ifndef MATRIX_H
#define MATRIX_H

#include "Key.h"
#include "Diagonal_matrix.h"
#include "Two_dimensional_array.h"
#include "Triangular_matrix.h"

//Ñòðóêòóðà "ìàòðèöû"
struct Matrix {
    Key K; //Èäåíòèôèêàòîð ìàòðèöû - äèàãîíàëüíàÿ èëè îáû÷íûé äâóìåðíûé ìàññèâ
    int N; //Äëèíà ìàññèâà
    Key_out K_o; //Ñïîñîá âûâîäà ìàòðèöû

    //Îáúåêò äèàãîíàëüíîé ìàòðèöû, îáû÷íîãî äâóìåðíîãî ìàññèâà èëè òðåóãîëüíîé ìàòðèöû
    union {
        Diagonal_matrix D_m;
        Two_dimensional_array T_d_a;
        Triangular_matrix T_m;
    };
};

//Ôóíêöèÿ ââîäà ìàòðèöû
Matrix* In_Matrix(ifstream& ifst);

//Ôóíêöèÿ âûâîäà ìàòðèöà
void Out_Matrix(Matrix* M, ofstream& ofst);

//Ôóíêöèÿ ïîäñ÷åò ñóììû ýëåìåíòîâ ìàòðèöû
int Sum_Matrix(Matrix* M);

//Ôóíêöèÿ ñðàâíåíèÿ ñóìì ýëåìåíòîâ ìàòðèö
bool Compare(Matrix* First, Matrix* Second);
#endif //MATRIX_H