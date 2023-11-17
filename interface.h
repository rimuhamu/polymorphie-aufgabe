
// Abstrakte Klasse zum Definieren einer Schnittstelle
// Da es keine privaten Attribute oder Funktionen gibt,
// kann auch ein struct genommen werden.
class PrintInterface 
{ 
public:
	virtual void vPrint() const = 0;
};

// struct PrintInterface{
//	 virtual void vPrint() const = 0;
//};