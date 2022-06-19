#include "iostream"
using namespace std;


class Engine
{
public:
	Engine();
	~Engine();

	virtual void setEngine() = 0;

};



class V8 : public Engine
{
public:
	V8();
	~V8();

	void setEngine()
	{
		cout << "V8 engine is installed." << endl;
	}


};


class V6 : public Engine
{
public:
	V6();
	~V6();


	void setEngine()
	{
		cout << "V6 engine is installed." << endl;
	}


};



class Car
{
public:
	Car();
	~Car();

	virtual void CarPlatform() = 0;
	virtual void setEngine() = 0;

	Engine* vc;			
};

class BMW : public Car
{
public:
	BMW();
	~BMW();

	

	void CarPlatform()
	{
		cout << "Coupe" << endl;
	}


	void setEngine()
	{
		vc->setEngine();	
	}
};


class Audi : public Car
{
public:
	Audi();
	~Audi();

	

	void CarPlatform()
	{
		cout << "Station wagon" << endl;
	}


	void setEngine()
	{
		vc->setEngine();	
	}
};



int main()
{
	cout << "BMW:" << endl;
	Car* car = new BMW();
	car->CarPlatform();
	Engine* engine = new V8();	
	car->vc = engine;					
	car->setEngine();					

	cout << "\nAudi:" << endl;
	Car* car2 = new Audi();
	car2->CarPlatform();
	Engine* engine2 = new V6();
	car2->vc = engine2;
	car2->setEngine();

	cout << "\nBmw:" << endl;
	Car* car3 = new BMW();
	car3->CarPlatform();
	Engine* engine3 = new V6();
	car3->vc = engine3;
	car3->setEngine();

    return 0;
}