#include <vector>
#include <string>

using namespace std;

class patient {
public:
	friend class Observer;

	string get_last_name() { return last_name; }
	string get_name() { return name; }
	string get_papich() { return papich; }
	string get_address() { return address; }
	long long int get_number() { return number; }
	string get_shiza() { return shiza; }

	void set_last_name(string a) { last_name = a;}
	void set_name(string a) { name = a; }
	void set_papich(string a) { papich = a; }
	void set_address(string a) { address = a; }
	void set_number(long long int a) {	number = a;	}
	void set_shiza(string a) { shiza = a; };
	
	friend bool operator== (const patient& object1, const patient& object2);
	friend bool operator!= (const patient& object1, const patient& object2);
	patient& operator= (const patient& object);
	
	patient() 
	{
	}
	
	patient(string a, string b, string c, string d, long long int e, string f) 
		: last_name(a), name(b), papich(c), address(d), number(e), shiza(f) 
	{	
	}
	
	patient(const patient& object) 
		: last_name(object.last_name), 
		name(object.name), 
		papich(object.papich), 
		address(object.address), 
		number(object.number), 
		shiza(object.shiza) 
	{	
	}

	~patient() {
	}
	
private:
	string last_name;
	string name;
	string papich;
	string address;
	long long int number = 0;
	string shiza;
};

class Observer {
public:
	string GetInfo(patient& object);
};