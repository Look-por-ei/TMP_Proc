#include "Container.h"

void Init_Container(Container& C) {
    C.Len = 0;
}

void In_Container(Container& C, ifstream& ifst) {
    while (!ifst.eof())
    {
        if ((C.Cont[C.Len] = In_Matrix(ifst))) { 
            C.Len++;

            if (C.Len == C.Max_len) {
                break;
            }
        }
    }
}

void Out_Container(Container& C, ofstream& ofst) {
    ofst << "Container contains " << C.Len 
        << " elements." << endl << endl;

    for (int i = 0; i < C.Len; i++) {
        ofst << i << ": "; 
        Out_Matrix(C.Cont[i], ofst); 

        if (C.Cont[i]->K != ERROR) {
            ofst << "Sum of matrix elements = " << Sum_Matrix(C.Cont[i]) << endl << endl;
        }
    }
}

void Clear_Container(Container& C) {
    for (int i = 0; i < C.Len; i++)  {
        delete C.Cont[i]; 
    }
    
    C.Len = 0;
}

void Sort(Container& C) {
    for (int i = 0; i < C.Len - 1; i++)  { 
        for (int j = i + 1; j < C.Len; j++)  { 
            if (Compare(C.Cont[i], C.Cont[j]))  { 
                Matrix* Temp = C.Cont[i]; 
                C.Cont[i] = C.Cont[j]; 
                C.Cont[j] = Temp; 
            } 
        } 
    }
}

void Out_Only_Two_Dim(Container& C, ofstream& ofst) {
    ofst << "Only Two Dimensional arrays." << endl << endl;

    for (int i = 0; i < C.Len; i++) {
        if (C.Cont[i]->K == TWO_DIMENSIONAL_ARRAY) {
            ofst << i << ": ";
            Out_Matrix(C.Cont[i], ofst);
        }
    }
}

void Multi_Method(Container& C, ofstream& ofst) {
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
                case TRIANGULAR_MATRIX:
                    ofst << "Two Dimensional Array and Triangual Matrix." << endl;
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
                case TRIANGULAR_MATRIX:
                    ofst << "Diagonal Matrix and Triangual Matrix." << endl;
                    break;
                default:
                    ofst << "Unknown type" << endl;
                }
                break;
            case TRIANGULAR_MATRIX:
                switch (C.Cont[j]->K) {
                case TWO_DIMENSIONAL_ARRAY:
                    ofst << "Triangual Matrix and Two Dimensional Array." << endl;
                    break;
                case DIAGONAL_MATRIX:
                    ofst << "Triangual Matrix and Diagonal Matrix." << endl;
                    break;
                case TRIANGULAR_MATRIX:
                    ofst << "Triangual Matrix and Triangual Matrix." << endl;
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