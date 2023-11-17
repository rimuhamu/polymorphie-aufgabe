

#include <iostream>
#include "tupel.h"
#include "pixel.h"
#include "liste.h"


int main(){

    Pixel pix1 = Pixel(1, 2, Color::red);
    Pixel pix2 = Pixel(5, 6, Color::blue);
    Tupel tup1 = Tupel(3,4);
    
    // 1. Thema: Ueberschreiben von Funktionen
    // 2. Thema: Virtuelle Funktionen

    pix1.print();
    cout << endl;
    pix1.vPrint();    
    cout << endl;
    tup1.vPrint();
    cout << endl;

    // 3. Container-Klassen
    // Klassen, die Objekte verwalten
    Liste list1 = Liste(3);
    Liste list2 = Liste();

    list1.add(tup1);
    cout << list1 << endl;
    list1.set((Tupel) pix1, 0);
    cout << list1 << endl;
    list1 += (Tupel) pix2;
    cout << list1 << endl;
    list2 = list1;
    cout << "(list2==list1)? "<< (list2 == list1) << endl;
    list1.add((Tupel) pix1);
    cout << "(list2==list1)? "<< (list2 == list1) << endl;
}


