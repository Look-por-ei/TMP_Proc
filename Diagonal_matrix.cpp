#include "Diagonal_matrix.h"

void In_Diagonal_matrix(int N, Diagonal_matrix& D_m, ifstream& ifst) {
    D_m.Array = new int[N];
    bool Error = false;
  
    for (int i = 0; i < N; i++) {
        string Temp_str = "";

        ifst >> Temp_str;

        //Проверка на считывание пустого значения
        if (Temp_str == "") {
            D_m.Array = NULL;

            return;
        }

        //Проверка на то, что считанная строка - число
        if (isdigit(int(signed char(Temp_str.front())))) {
            D_m.Array[i] = atoi(Temp_str.c_str());
        }
        else {
            Error = true;
        }
    }

    if (Error) {
        D_m.Array = NULL;
    }
}

void Out_Diagonal_matrix(Key_out K_o, int N, Diagonal_matrix& D_m, ofstream& ofst) {
    ofst << "It's diagonal matrix with dimension = " << N << endl;

    if (K_o == BY_LINE) { //Вывод по строкам
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j) {
                    ofst << D_m.Array[i] << " ";
                }
                else {
                    ofst << "0 ";
                }
            }

            ofst << endl;
        }

        ofst << endl;
    }
    else if (K_o == BY_COLUMN) { //Вывод по столбцам
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j) {
                    ofst << D_m.Array[j] << " ";
                }
                else {
                    ofst << "0 ";
                }
            }

            ofst << endl;
        }

        ofst << endl;
    }
    else if (K_o == ONE_DIMENSIONAL) { //Вывод в виде одномерного массива
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j) {
                    ofst << D_m.Array[i] << " ";
                }
                else {
                    ofst << "0 ";
                }
            }
        }

        ofst << endl;
    }
}

int Sum_Diagonal_matrix(int N, Diagonal_matrix& D_m) {
    int Sum = 0;

    for (int i = 0; i < N; i++) {
        Sum += D_m.Array[i];
    }

    return Sum;
}