#include "Two_dimensional_array.h"

void In_Two_dimensional_array(int N, Two_dimensional_array& T_d_a, ifstream& ifst) {
    T_d_a.Array = new int* [N];

    for (int i = 0; i < N; i++) {
        T_d_a.Array[i] = new int[N]; 
    }

    bool Error = false; 

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            string Temp_str = "";

            ifst >> Temp_str;

            //Проверка на считывание пустого значения
            if (Temp_str == "") {
                T_d_a.Array = NULL;

                return;
            }

            //Проверка на то, что считанный символ - число
            if (isdigit(int(signed char(Temp_str.front())))) {
                T_d_a.Array[i][j] = atoi(Temp_str.c_str());
            }
            else {
                Error = true;
            }
        }
    }

    if (Error) {
        T_d_a.Array = NULL;
    }
}

void Out_Two_dimensional_array(Key_out K_o, int N, Two_dimensional_array& T_d_a, ofstream& ofst) {
    ofst << "It's two dimensional matrix with dimension = " << N << endl; 

    if (K_o == BY_LINE) { //Вывод по строкам
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                ofst << T_d_a.Array[i][j] << " ";
            }

            ofst << endl;
        }

        ofst << endl;
    }
    else if (K_o == BY_COLUMN) { //Вывод по столбцам
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                ofst << T_d_a.Array[j][i] << " ";
            }

            ofst << endl;
        }

        ofst << endl;
    }
    else if (K_o == ONE_DIMENSIONAL) { //Вывод в виде одномерного массива
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                ofst << T_d_a.Array[i][j] << " ";
            }
        }

        ofst << endl;
    }
}

int Sum_Two_dimensional_array(int N, Two_dimensional_array& T_d_a) {
    int Sum = 0;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            Sum += T_d_a.Array[i][j];
        }
    }

    return Sum;
}