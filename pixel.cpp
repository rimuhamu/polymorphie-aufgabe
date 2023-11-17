/* Implementierung der einfachen vererbten und aggregierten Klasse
Autor: A. Pohl
Daumt: 11/21
*/

#include <iostream>
#include "tupel.h"
#include "pixel.h"

void Pixel::setTupel(Tupel tup){
  this->setA(tup.getA());
  this->setB(tup.getB());
}

void Pixel::setFarbe(Color farbe){
  if ((Color::black <= farbe) && (farbe <= Color::white)){
    this->farbe = farbe;
  }
  else{
    // hier koennen jetzt Ausnahmen geworfen werden
    throw int(2);
  }
}

// Operatoren
const Pixel& Pixel::operator = (const Pixel& pix){
  this->setTupel(pix.getTupel());
  this->farbe = pix.getFarbe();
  return *this;
}

bool operator  == (const Pixel& pix1, const Pixel& pix2){
  return ((pix1.getTupel() == pix2.getTupel()) && (pix1.getFarbe() == pix2.getFarbe()));
}

bool operator != (const Pixel& pix1, const Pixel& pix2){
  return !(pix1 == pix2);
}

ostream& operator << (ostream& s, const Pixel& pix){
  s << "("<< (Tupel) pix << "," << pix.getFarbe()<<")";
  return s;
}

istream& operator >> (istream& s, Pixel& pix){
  Tupel tmp_tup;
  int tmp_col;  
  s >> tmp_tup;
  pix.setTupel(tmp_tup);  
  cout << "Bitte geben Sie einen Farbwert (0-9) ein:" << endl;
  s >> tmp_col;
  pix.farbe = (Color) tmp_col;
    return s;
}

// neu
// ueberschreiben der print-Funktion

void Pixel::print()const {
  Tupel::print();
  cout <<  ", Farbe " << this->farbe;
}


// virtuelle Funktion zum Drucken
void Pixel::vPrint() const{
  cout << *this;
}

// neu
// virtuelle Funktion zum Klonen
Pixel* Pixel::clone() const{
  return (Pixel*) new Pixel(*this);
}

