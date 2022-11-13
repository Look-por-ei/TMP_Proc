#include "Container.h"

void Init_Container(Container& C) {
    C.Len = 0;
}

void In_Container(Container& C, ifstream& ifst) {
    while (!ifst.eof()) //×èòàåì äî êîíöà ôàéëà
    {
        if ((C.Cont[C.Len] = In_Matrix(ifst)) != 0) //Ñ÷èòûâàåì î÷åðåäíóþ ìàòðèöó 
        { 
            C.Len++;

            if (C.Len == C.Max_len) //Ïðîâåðêà íà ïåðåïîëíåíèå êîíòåéíåðà
            {
                break;
            }
        }
    }
}

void Out_Container(Container& C, ofstream& ofst) {
    ofst << "Container contains " << C.Len 
        << " elements." << endl; //Âûâîäèì äëèíó êîíòåéíåðà

    for (int i = 0; i < C.Len; i++)
    {
        ofst << i << ": "; //Âûâîäèì íîìåð ìàòðèöû
        Out_Matrix(C.Cont[i], ofst); //Âûâîäèì ìàòðèöó

        ofst << "Sum of matrix elements = " << Sum_Matrix(C.Cont[i]) << endl;
    }
}

void Clear_Container(Container& C) {
    for (int i = 0; i < C.Len; i++) 
    {
        delete C.Cont[i]; //Î÷èùàåì ïàìÿòü, âûëåëåííóþ äëÿ êàæäîé ìàòðèöû
    }
    
    C.Len = 0;
}

void Out_Only_Two_Dim(Container& C, ofstream& ofst) {
    ofst << endl << "Only Two Dimensional arrays." << endl;

    for (int i = 0; i < C.Len; i++)
    {
        if (C.Cont[i]->K == TWO_DIMENSIONAL_ARRAY) //Ïðîâåðêà òîãî, ÷òî ìàòðèöà - îáû÷íûé äóìåðíûé ìàññèâ
        {
            ofst << i << ": ";
            Out_Matrix(C.Cont[i], ofst);
        }
void Sort(Container& C)
{
    //Ñîðòèðóåì ïóçûðüêîì
    for (int i = 0; i < C.Len - 1; i++) 
    { 
        for (int j = i + 1; j < C.Len; j++) 
        { 
            //Êîìïàðàòîðîì ñðàâíèâàåì ñóììû ýëåìåíòîâ ìàòðèö
            if (Compare(C.Cont[i], C.Cont[j])) 
            { 
                Matrix* Temp = C.Cont[i]; 
                C.Cont[i] = C.Cont[j]; 
                C.Cont[j] = Temp; 
            } 
        } 
    }
}