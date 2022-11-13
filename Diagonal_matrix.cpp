#include "Diagonal_matrix.h"

void In_Diagonal_matrix(int N, Diagonal_matrix& D_m, ifstream& ifst)
{
    D_m.Array = new int[N]; //Выделяем память для диагональной матрицы

    bool Error = false;
    
    for (int i = 0; i < N; i++)
    {
        string Temp_str = "";
        ifst >> Temp_str;

        if (Temp_str == "")
        {
            D_m.Array = NULL;

            return;
        }

        if (isdigit(int(signed char(Temp_str.front()))))
        {
            D_m.Array[i] = atoi(Temp_str.c_str());
        }
        else
        {
            Error = true;
        }
    }

    if (Error)
    {
        D_m.Array = NULL;
    }
}

void Out_Diagonal_matrix(Key_out K_o, int N, Diagonal_matrix& D_m, ofstream& ofst)
{
    ofst << "It's diagonal matrix with dimension = " << N << endl; //Выводим размерность матрицы

    if (K_o == BY_LINE)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (i == j)
                {
                    ofst << D_m.Array[i] << " ";
                }
                else
                {
                    ofst << "0 ";
                }
            }
            ofst << endl;
        }
    }
    else if (K_o == BY_COLUMN)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (i == j)
                {
                    ofst << D_m.Array[j] << " ";
                }
                else
                {
                    ofst << "0 ";
                }
            }
            ofst << endl;
        }
    }
    else if (K_o == ONE_DIMENSIONAL)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                if (i == j)
                {
                    ofst << D_m.Array[i] << " ";
                }
                else
                {
                    ofst << "0 ";
                }
            }
        }

        ofst << endl;
    }
}

int Sum_Diagonal_matrix(int N, Diagonal_matrix& D_m)
{
    int Sum = 0;

    for (int i = 0; i < N; i++)
    {
        Sum += D_m.Array[i];
    }
    return Sum;
}