#include "Two_dimensional_array.h"

void In_Two_dimensional_array(int N, Two_dimensional_array& T_d_a, ifstream& ifst)
{
    T_d_a.Array = new int* [N]; //Выделение памяти под массив

    for (int i = 0; i < N; i++)
    {
        T_d_a.Array[i] = new int[N]; //Выделение памяти под массив
    }

    bool Error = false; //Идентификатор того, что какой-то элемент матрицы не является числом

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            string Temp_str = "";
            ifst >> Temp_str;

            //Проверяем, что не считали пустое значение
            if (Temp_str == "")
            {
                T_d_a.Array = NULL;

                return;
            }

            //Проверяем, что считанный символ - число
            if (isdigit(int(signed char(Temp_str.front()))))
            {
                T_d_a.Array[i][j] = atoi(Temp_str.c_str());
            }
            else
            {
                Error = true; //Иначе - ошибка
            }
        }
    }

    //Если была ошибка, то вернем пустой массив
    if (Error)
    {
        T_d_a.Array = NULL;
    }
}

void Out_Two_dimensional_array(Key_out K_o, int N, Two_dimensional_array& T_d_a, ofstream& ofst)
{
    ofst << "It's two dimensional matrix with dimension = " << N << endl; //Выводим размерность массива

    if (K_o == BY_LINE)
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                ofst << T_d_a.Array[i][j] << " ";
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
                ofst << T_d_a.Array[j][i] << " ";
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
                ofst << T_d_a.Array[i][j] << " ";
            }
        }

        ofst << endl;
    }
}

int Sum_Two_dimensional_array(int N, Two_dimensional_array& T_d_a)
{
    int Sum = 0;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            Sum += T_d_a.Array[i][j];
        }
    }

    return Sum;
}