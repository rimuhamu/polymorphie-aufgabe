#ifndef TUPEL_H
#define TUPEL_H
/* Bibliothek mit einfacher Klasse
Autor: A. Pohl
Datum: 11/21
*/

#include <iostream>
#include "interface.h"
using namespace std;

class Tupel : public PrintInterface {
  
  private:

  // Attribute
  // ***
  int a;
  int b;
  
  public:

  // Funktionen
  // ***
  // Standard- und Initialisierungskonstruktor
  Tupel(int a = 0, int b = 0){     // Tupel(), Tupel(1), Tupel(1,2)
    this->a = a;
    this->b = b;
  }
  // Kopierkonstruktor
  Tupel(const Tupel& tup) {if (this != &tup) *this = tup;}
  // Destruktor
  virtual ~Tupel(){}

  // setter/getter
  void setA(int a){this->a = a;}
  int  getA(){return a;}
  void setB(int b){this->b = b;}
  int  getB(){return b;}

  // Operatoren
  const Tupel& operator = (const Tupel& tup);
  friend bool operator  == (const Tupel& tup1, const Tupel& tup2);
  friend bool operator != (const Tupel& tup1, const Tupel& tup2);
	friend ostream& operator << (ostream& s, const Tupel& tup);
	friend istream& operator >> (istream& s, Tupel& tup);
  
  // weitere Funktionen
  // statische/fruehe Bindung
  void print() const;

  // neu:
  // virtuelle Funktionen
  // dynamische/spaete Bindung
  virtual Tupel* clone() const;
  virtual void vPrint() const;
  //void vPrint() const;
  
};


#endif // TUPEL_H