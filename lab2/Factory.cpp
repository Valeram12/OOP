#include <iostream>
#include <stdlib.h>
#include <time.h>
class DHandleAbs
{
public:
	virtual void printSerialNumber() = 0;
};

class DWindowAbs
{
public:
	virtual void printSerialNumber() = 0;
};

class BDHandle : public DHandleAbs
{
public:
	void printSerialNumber() {
		std::cout << " DoorHandle: B"<<rand() << std::endl;
	}
};

class FDHandle : public DHandleAbs
{
public:
	void printSerialNumber() {
		std::cout << " DoorHandle: F"<<rand() << std::endl;
	}
};

class BDWindow : public DWindowAbs
{
public:
	void printSerialNumber() {
		std::cout << " DoorWindow: B"<<rand() << std::endl;
	}
};

class FDWindow : public DWindowAbs {
public:

	void printSerialNumber() {
		std::cout << " DoorWindow: F"<<rand()<<std::endl;
	}
};


class CarAbsFactory
{
public:
	virtual DHandleAbs* createDoorHandle() = 0;
	virtual DWindowAbs* createDoorWindow() = 0;
};

class BMWCar_ConcreteFactory : public CarAbsFactory
{
public:
	DHandleAbs* createDoorHandle() {
		return new BDHandle;
	}
	DWindowAbs* createDoorWindow() {
		return new BDWindow;
	}
};

class FordCar_ConcreteFactory : public CarAbsFactory
{
public:
	DHandleAbs* createDoorHandle() {
		return new FDHandle;
	}
	DWindowAbs* createDoorWindow() {
		return new FDWindow;
	}
};


int main()
{
	srand(time(NULL));
	CarAbsFactory* abstractFactory;
	DHandleAbs* dHandle_AbstractProduct;
	DWindowAbs* dWindow_AbstractProduct;


	abstractFactory = new FordCar_ConcreteFactory;

	dHandle_AbstractProduct = abstractFactory->createDoorHandle();
	dWindow_AbstractProduct = abstractFactory->createDoorWindow();

	dHandle_AbstractProduct->printSerialNumber();
	dWindow_AbstractProduct->printSerialNumber();

	abstractFactory = new BMWCar_ConcreteFactory;

	dHandle_AbstractProduct = abstractFactory->createDoorHandle();
	dWindow_AbstractProduct = abstractFactory->createDoorWindow();

	dHandle_AbstractProduct->printSerialNumber();
	dWindow_AbstractProduct->printSerialNumber();

	return 0;
}