// 7lab_b.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

#include "Container.h"

using namespace std;

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "incorrect command line! "
            "Waited: command in_file out_file"
            << endl;
        exit(1);
    }

    ifstream ifst(argv[1]);

    if (!ifst.is_open()) {
        cout << "No input file found or could not open!" << endl;
        system("pause");
        return 1;
    }

    ofstream ofst(argv[2]);

    if (!ofst.is_open()) {
        cout << "No output file found or could not open!" << endl;
        system("pause");
        return 1;
    }

    cout << "Start" << endl;

    Container C; //Объявление нового контейнера

    Init_Container(C); //Инициализация контейнера

    In_Container(C, ifst); //Запись элементов в контейнер

    //Проверка заполнение контейнера до максимума
    if (C.Len == C.Max_len) {
        ofst << "Conteiner is full (" << C.Max_len << " elemets)!" << endl <<
            "It can't accommodate more elements." << endl;
    }

    ofst << "Filled and sorted container. " << endl;

    Sort(C); //Сортировка контейнера

    Out_Container(C, ofst); //Вывод контейнера

    Out_Only_Two_Dim(C, ofst); //Вывод только двумерного массива

    Multi_Method(C, ofst); //Вызов мультиметода

    Clear_Container(C); //Очистка контейнера

    ofst << "Empty container. " << endl;

    Out_Container(C, ofst); //Вывод контейнера

    cout << "Stop" << endl;
    system("pause");
    return 0;
}