#include "class.h"

bool operator== (const patient& object1, const patient& object2)
{
	return (object1.last_name == object2.last_name &&
		object1.name == object2.name &&
		object1.papich == object2.papich &&
		object1.address == object2.address &&
		object1.number == object2.number &&
		object1.shiza == object2.shiza
		);
}

bool operator!= (const patient& object1, const patient& object2)
{
	return !(object1 == object2);
}

patient& patient::operator= (const patient& object){
	last_name = object.last_name;
	name = object.name;
	papich = object.papich;
	address = object.address;
	number = object.number;
	shiza = object.shiza;

	return *this;
}

string Observer::GetInfo(patient& object) {
	return (object.last_name + " " + 
		object.name + " " + 
		object.papich + " " + 
		object.address + " " +
		to_string(object.number) + " " +
		object.shiza);
}