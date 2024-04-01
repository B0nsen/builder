#include <iostream>
#include <string>
#include <ctime>
using namespace std;

/* Паттерн Строитель отделяет конструирование сложного объекта от его представления, так что
	   в результате одного и того же процесса конструирования могут получаться разные представления.
	Применимость
	   - алгоритм создания сложного объекта не должен зависеть от того, из каких частей состоит объект и как они стыкуются между собой;
	   - процесс конструирования должен обеспечивать различные представления конструируемого объекта.
   Плюсы и минусы паттерна строитель и его применения:
	- позволяет изменять внутреннее представление продукта
	- изолирует код, реализующий конструирование и представление
	- дает более тонкий контроль над процессом конструирования
   */

/*
	 matrix (продукт) представляет сложный конструируемый объект. 
	 ConcreteBuilder строит внутреннее представление продукта и определяет процесс его сборки.
*/

class Body
{
protected:
	std::string name;
	std::string color;
public:
	void SetName(string name)
	{
		this->name = name;
	}
	void SetColor(string color)
	{
		this->color = color;
	}
	string GetName()
	{
		return name;
	}
	string GetColor()
	{
		return color;
	}
	void PrintBody()
	{
		std::cout << "Car body\nName: " << name << "\nColor: " << color << '\n';
	}
};

class Engine
{
protected:
	std::string name;
	int power;
public:
	void SetName(string name)
	{
		this->name = name;
	}
	void SetPower(int power)
	{
		this->power = power;
	}
	string GetName()
	{
		return name;
	}
	int GetPower()
	{
		return power;
	}
	void PrintEngine()
	{
		std::cout << "Car engine\nName: " << name << "\nHourse power: " << power << '\n';
	}
};

class GearBox
{
protected:
	std::string type;
	int count;
public:
	void SetType(string type)
	{
		this->type = type;
	}
	void SetCount(int count)
	{
		this->count = count;
	}
	string GetType()
	{
		return type;
	}
	int GetCount()
	{
		return count;
	}
	void PrintGearBox()
	{
		std::cout << "Car gearbox\nType: " << type << "\nCount: " << count << '\n';
	}
};

class WheelsBuilderPrototype abstract
{
protected:
	int wheels;
public:
	int GetWheels()
	{
		return wheels;
	}
	virtual void SetWheels() abstract;
};

class WheelsBuilder1 : public WheelsBuilderPrototype
{
public:
	void SetWheels() override
	{
		wheels = 13;
	}
};

class WheelsBuilder2 : public WheelsBuilderPrototype
{
public:
	void SetWheels() override
	{
		wheels = 14;
	}
};

class WheelsBuilder3 : public WheelsBuilderPrototype
{
public:
	void SetWheels() override
	{
		wheels = 16;
	}
};

class EngineBuilderPrototype abstract
{
protected:
	Engine engine;
public:
	Engine GetEngine()
	{
		return engine;
	}
	virtual void SetName() abstract;
	virtual void SetPower() abstract;
};

class EngineBuilder1 : public EngineBuilderPrototype
{
public:
	void SetName() override
	{
		engine.SetName("Lanos");
	}
	void SetPower() override
	{
		engine.SetPower(98);
	}
};

class EngineBuilder2 : public EngineBuilderPrototype
{
public:
	void SetName() override
	{
		engine.SetName("Ford");
	}
	void SetPower() override
	{
		engine.SetPower(160);
	}
};

class EngineBuilder3 : public EngineBuilderPrototype
{
public:
	void SetName() override
	{
		engine.SetName("UAZ");
	}
	void SetPower() override
	{
		engine.SetPower(120);
	}
};

class BodyBuilderPrototype abstract
{
protected:
	Body body;
public:
	Body GetBody()
	{
		return body;
	}
	virtual void SetName() abstract;
	virtual void SetColor() abstract;
};

class BodyBuilder1 : public BodyBuilderPrototype
{
public:
	void SetName() override
	{
		body.SetName("Sedan");
	}
	void SetColor() override
	{
		body.SetColor("Red");
	}
};

class BodyBuilder2 : public BodyBuilderPrototype
{
public:
	void SetName() override
	{
		body.SetName("Cupe");
	}
	void SetColor() override
	{
		body.SetColor("Blue");
	}
};

class BodyBuilder3 : public BodyBuilderPrototype
{
public:
	void SetName() override
	{
		body.SetName("Universal");
	}
	void SetColor() override
	{
		body.SetColor("Green");
	}
};

class GearBoxBuilderPrototype abstract
{
protected:
	GearBox gearbox;
public:
	GearBox GetGearBox()
	{
		return gearbox;
	}
	virtual void SetType() abstract;
	virtual void SetCount() abstract;
};

class GearBoxBuilder1 : public GearBoxBuilderPrototype
{
public:
	void SetType() override
	{
		gearbox.SetType("Manual");
	}
	void SetCount() override
	{
		gearbox.SetCount(5);
	}
};

class GearBoxBuilder2 : public GearBoxBuilderPrototype
{
public:
	void SetType() override
	{
		gearbox.SetType("Auto");
	}
	void SetCount() override
	{
		gearbox.SetCount(4);
	}
};

class GearBoxBuilder3 : public GearBoxBuilderPrototype
{
public:
	void SetType() override
	{
		gearbox.SetType("Manual");
	}
	void SetCount() override
	{
		gearbox.SetCount(4);
	}
};

class Car
{
protected:
	Body body;
	Engine engine;
	GearBox gearbox;
	int wheels;
public:
	void SetBody(Body body)
	{
		this->body.SetColor(body.GetColor());
		this->body.SetName(body.GetName());
	}
	void SetEngine(Engine engine)
	{
		this->engine.SetName(engine.GetName());
		this->engine.SetPower(engine.GetPower());
	}
	void SetGearBox(GearBox gearbox)
	{
		this->gearbox.SetCount(gearbox.GetCount());
		this->gearbox.SetType(gearbox.GetType());
	}
	void SetWheels(int wheels)
	{
		this->wheels = wheels;
	}
	Body GetBody()
	{
		return body;
	}
	Engine GetEngine()
	{
		return engine;
	}
	GearBox GetGearBox()
	{
		return gearbox;
	}
	int GetWheels()
	{
		return wheels;
	}
	void ShowCar()
	{
		body.PrintBody();
		engine.PrintEngine();
		gearbox.PrintGearBox();
		std::cout << "Wheels: " << wheels << '\n';
	}
};

class CarBuilder abstract
{
protected:
	Car car;
public:
	Car GetCar()
	{
		return car;
	}
	void BuildEngine(EngineBuilderPrototype* EBP)
	{
		EBP->SetPower();
		EBP->SetName();
		car.SetEngine(EBP->GetEngine());
	}
	void BuildBody(BodyBuilderPrototype* BBP)
	{
		BBP->SetColor();
		BBP->SetName();
		car.SetBody(BBP->GetBody());
	}
	void BuildGearBox(GearBoxBuilderPrototype* GBBP)
	{
		GBBP->SetCount();
		GBBP->SetType();
		car.SetGearBox(GBBP->GetGearBox());
	}
	void BuildWheels(WheelsBuilderPrototype* WBP)
	{
		WBP->SetWheels();
		car.SetWheels(WBP->GetWheels());
	}
};

class Factory
{
	CarBuilder* carBuilder;
	EngineBuilderPrototype* Enginebuilder;
	GearBoxBuilderPrototype* Gearboxbuilder;
	WheelsBuilderPrototype* Wheelsbuilder;
	BodyBuilderPrototype* Bodybuilder;
public:
	void SetEngineBuilder(EngineBuilderPrototype* EBP)
	{
		Enginebuilder = EBP;
	}
	void SetGearBoxBuilder(GearBoxBuilderPrototype* GBBP)
	{
		Gearboxbuilder = GBBP;
	}
	void SetBodyBuilder(BodyBuilderPrototype* BBP)
	{
		Bodybuilder = BBP;
	}
	void SetWheelsBuilder(WheelsBuilderPrototype* WBP)
	{
		Wheelsbuilder = WBP;
	}
	Car GetCar()
	{
		return carBuilder->GetCar();
	}
	void ConstructCar()
	{
		carBuilder->BuildBody(Bodybuilder);
		carBuilder->BuildGearBox(Gearboxbuilder);
		carBuilder->BuildEngine(Enginebuilder);
		carBuilder->BuildWheels(Wheelsbuilder);
	}
};

void Client(BodyBuilderPrototype* BBP, EngineBuilderPrototype* EBP, GearBoxBuilderPrototype* GBBP, WheelsBuilderPrototype* WBP)
{
	Factory factory;
	factory.SetBodyBuilder(BBP);
	factory.SetEngineBuilder(EBP);
	factory.SetGearBoxBuilder(GBBP);
	factory.SetWheelsBuilder(WBP);
	factory.ConstructCar();
	Car car = factory.GetCar();
	car.ShowCar();
}

void main()
{
	srand(time(nullptr));
	EngineBuilderPrototype* eb = new EngineBuilder1();
	BodyBuilderPrototype* bb = new BodyBuilder1();
	GearBoxBuilderPrototype* gbb = new GearBoxBuilder1();
	WheelsBuilderPrototype* wb = new WheelsBuilder1();
	Client(bb, eb, gbb, wb);

	//system("pause");
}