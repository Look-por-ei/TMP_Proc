#include "Container.h"
#include "Key.h"

void Init_Container(Container& C) {
    C.Len = 0;
}

void In_Container(Container& C, ifstream& ifst) {
    while (!ifst.eof()) //������ �� ����� �����
    {
        if ((C.Cont[C.Len] = In_Matrix(ifst)) != 0) //��������� ��������� ������� 
        { 
            C.Len++;

            if (C.Len == C.Max_len) //�������� �� ������������ ����������
            {
                break;
            }
        }
    }
}

void Out_Container(Container& C, ofstream& ofst) {
    ofst << "Container contains " << C.Len 
        << " elements." << endl; //������� ����� ����������

    for (int i = 0; i < C.Len; i++)
    {
        ofst << i << ": "; //������� ����� �������
        Out_Matrix(C.Cont[i], ofst); //������� �������
    }
}

void Clear_Container(Container& C) {
    for (int i = 0; i < C.Len; i++) 
    {
        delete C.Cont[i]; //������� ������, ���������� ��� ������ �������
    }
    
    C.Len = 0;
}

void Multi_Method (Container& C, ofstream& ofst) {
    ofst << "Multimethod." << endl << endl;
    
    for (int i = 0; i < C.Len - 1; i++) { 
        for (int j = i + 1; j < C.Len; j++) { 
            switch (C.Cont[i]->K) { 
            case TWO_DIMENSIONAL_ARRAY: 
                switch (C.Cont[j]->K) { 
                case TWO_DIMENSIONAL_ARRAY: 
                    ofst << "Two Dimensional Array and Two Dimensional Array." << endl; 
                    break; 
                case DIAGONAL_MATRIX: 
                    ofst << "Two Dimensional Array and Diagonal Matrix." << endl; 
                    break; 
                default: 
                    ofst << "Unknown type" << endl; 
                } 
                break; 
            case DIAGONAL_MATRIX: 
                switch (C.Cont[j]->K) { 
                case TWO_DIMENSIONAL_ARRAY: 
                    ofst << "Diagonal Matrix and Two Dimensional Array." << endl; 
                    break; 
                case DIAGONAL_MATRIX: 
                    ofst << "Diagonal Matrix and Diagonal Matrix." << endl; 
                    break; 
                default: 
                    ofst << "Unknown type" << endl; 
                } 
                break; 
            default: 
                ofst << "Unknown type" << endl; 
            } 
            
            Out_Matrix(C.Cont[i], ofst); 
            Out_Matrix(C.Cont[j], ofst); 
        } 
    }
}