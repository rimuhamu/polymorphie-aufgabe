#ifndef LISTE_H
#define LISTE_H

#include "tupel.h"

class Liste{
  // Attribute
  //***

private:
  int size;
  int no_of_entries;
  // Speicherbereich mit Zeigern, die auf Tupel zeigen
  Tupel** entries;

public:
  
  // Konstruktoren + Destruktor
  Liste(int size = 5);
  virtual ~Liste();

  //Operatoren
  const Liste& operator  = (const Liste& list);
  // neuer Operator zum Hinzufuegen von Objekten
  const Liste& operator += (const Tupel& st);
  friend bool operator == (const Liste& list1, const Liste& list2);
  friend bool operator != (const Liste& list1, const Liste& list2);
  friend ostream& operator << (ostream& s, const Liste& list);
  friend istream& operator >> (istream& s, const Liste& list);

  // sonstige Funktionen
  void add(const Tupel& tup);
  void set(const Tupel& tup, int pos);
  Tupel& get(int pos) const; // const nachgestellt: Inhalt des Objekts darf nicht veraendert werden
};

#endif