/* Implementierung der Funktionen des selbstdefinierten Struktur
Autor: A. Pohl
Datum: 11/21
*/

#include <iostream>
#include "tupel.h"

using namespace std;

// Tupel
// ***

// Operatoren
// Zuweisungsoperator
const Tupel& Tupel::operator = (const Tupel& tup){
  this->a = tup.a;
  this->b = tup.b;
  return *this; // Inhalt an Referenz übergeben (Referenz ist const!)
}

// globale Operatoren (werden überschrieben)
bool operator  == (const Tupel& tup1, const Tupel& tup2){
  return ((tup1.a == tup2.a) && (tup1.b == tup2.b));
}

bool operator != (const Tupel& tup1, const Tupel& tup2){
  return !(tup1 == tup2);
}

ostream& operator << (ostream& s, const Tupel& tup){
  s << "(" << tup.a << "," << tup.b << ")";
  return s;
}

istream& operator >> (istream& s, Tupel& tup){
  cout << "Geben Sie a und b ein: ";
  s >> tup.a >> tup.b;
  return s;
}

// sonstige Funktionen
void Tupel::print() const{
  cout << *this;
}

// neu
// virtuelle Funktion zum Drucken
void Tupel::vPrint() const{
  cout << *this;
}

// neu:
// virtuelle Funktion zum Clonen
Tupel* Tupel::clone() const{
  return (Tupel*) new Tupel(*this);  
}

