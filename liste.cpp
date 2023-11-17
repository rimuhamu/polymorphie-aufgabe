#include <iostream>
#include "liste.h"

// Konstruktoren und Destruktoren

Liste::Liste(int size){
    if(size <= 0) size = 5;
    this->size = size;
    this->no_of_entries = 0;
    // hier wird ein Feld von Zeigern angelegt
    this->entries = (Tupel**) new Tupel*[size];
}

Liste::~Liste(){

  // fuer jeden Zeiger in entries muss das Objekt geloescht werden
  // auf das der Zeiger zeigt
  for (int i = 0; i < this->no_of_entries; i++){  
      if (this->entries[i] != NULL) delete (this->entries[i]);      
  }
  this->size = 0;
  this->no_of_entries = 0;
  // loeschen des Felds an Zeigern
  if (this->entries) delete [] this->entries;
}


const Liste& Liste::operator = (const Liste& list)
{
	if (this != &list)
	{
        // loeschen der Speicherbereiche fuer Zeiger und Ziele der Zeiger
		for (int i = 0; i < this->no_of_entries; i++)
			if (*(this->entries + i)) delete* (this->entries + i);
		if (this->entries) delete[] this->entries;
        // setzen der neuen Groessen
		this->size = list.size;
		this->no_of_entries  = list.no_of_entries;
		entries = (Tupel**) new Tupel*[list.size];
		for (int i = 0; i < list.no_of_entries; i++)
			entries[i] = list.entries[i]->clone();			
	}
	return *this;
}

const Liste& Liste::operator += (const Tupel& tup)
{
	this->add(tup);
	return *this;
}


bool operator == (const Liste& list1, const Liste& list2)
{
	bool ret = true;
	if (list1.size == list2.size){
		if (list1.no_of_entries == list2.no_of_entries){
			for (int i = 0; i < list1.no_of_entries; i++){
				if (*list1.entries[i] != *list2.entries[i]){
                    ret = false; 
                    break; 
                }
			}
		}
		else {
            ret = false;
        }
    }
	else {
        ret = false;
    }
	return ret;
}

bool operator != (const Liste& list1, const Liste& list2)
{
	return !(list1 == list2);
}

ostream& operator << (ostream& s, const Liste& list)
{
	s << "Eintraege: " << list.no_of_entries << endl;
	for (int i = 0; i < list.no_of_entries; i++)	{
			s << *list.entries[i];
	}
	return s;
}

// unvollstaendig
istream& operator >> (istream& s, Liste& list)
{
	// code
    // ...
	return s;
}

void Liste::add(const Tupel& tup){
  if (this->no_of_entries < this->size){
    // vorher:    
    // this->entries[this->no_of_entries] = tup;
    // neu:
    // erzeuge vollstaendige Kopie
    this->entries[this->no_of_entries] = tup.clone();        
    this->no_of_entries++;
  }
  else{
    cerr << "Fehler: Liste voll!" << endl;
  }
}

void Liste::set(const Tupel& tup, int pos)
{	
	if (pos < this->no_of_entries && pos >= 0)
		this->entries[pos] = tup.clone();
	else if (pos == this->size)
		add(tup);
	else
        cerr << "Fehler: Ungueltige Position!" << endl;		
}

Tupel& Liste::get(int pos) const
{
	if (pos < this->no_of_entries && pos >= 0)
		return *this->entries[pos];
	else{	
        cerr << "Fehler: Ungueltige Position!" << endl;				
        //return 0;
    }
}


