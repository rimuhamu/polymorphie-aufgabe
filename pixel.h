#ifndef PIXEL_H
#define PIXEL_H

/* Einfache vererbte und aggregierte Klassen
Autor: A. Pohl
Daumt: 11/21
*/

#include "tupel.h"

// enumeration type: Aufzaehlung von "Aliasen" fuer Nummerierung
enum Color {black, yellow, blue, green, red, magenta, cyan, brown, grey, white};

// Vererbte Klasse Pixel
class Pixel : public Tupel{

  private:
  // wir erben einen Tupel
  // und moechten noch um eine Farbe erweitern
  Color farbe;
  
  public:

  // Konstruktoren
  Pixel(int a = 0, int b = 0, Color farbe = Color::black) : Tupel(a, b) {this->setFarbe(farbe);}
  Pixel(const Tupel& tup, Color farbe) : Tupel(tup){this->setFarbe(farbe);}
  Pixel(const Pixel& pix){if (this != &pix) *this = pix;}
  // virtual: spaete Bindung, bei Ableitungen wird ueberschriebene Funktion genommen
  virtual ~Pixel(){}

  // setter / getter 
  void  setTupel(Tupel tup);
  Tupel getTupel()const {return (Tupel) *this;}
  void  setFarbe(Color farbe);
  Color getFarbe() const {return farbe;}

  // Operatoren
  const Pixel& operator = (const Pixel& pix);
  friend bool operator  == (const Pixel& pix1, const Pixel& pix2);
  friend bool operator != (const Pixel& pix1, const Pixel& pix2);
	friend ostream& operator << (ostream& s, const Pixel& pix);
	friend istream& operator >> (istream& s, Pixel& pix);

  // sonstige Funktionen
  void print() const;
  virtual void  vPrint() const;
  virtual Pixel* clone() const;
  
};

#endif //PIXEL_H