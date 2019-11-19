#include <iostream>
#include <locale>
#include<string>
using namespace std;
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Xml::Serialization;
using namespace System::IO;
ref class Jewel;
ref class JewelForHand;
ref class Chains;
ref class JewelForNeck;
ref class Clip;
ref class Earrings;
ref class JewelForHead;
ref class JewelForHuman;
ref class Watch;
ref class Box;
ref class JewelForHome;
ref class Ring;
ref class Beads;
ref class Bracelet;
[Serializable]
[XmlInclude(JewelForHand::typeid)]
[XmlInclude(JewelForHead::typeid)]
[XmlInclude(JewelForHome::typeid)]
[XmlInclude(Beads::typeid)]
[XmlInclude(Box::typeid)]
[XmlInclude(Bracelet::typeid)]
[XmlInclude(Clip::typeid)]
[XmlInclude(Earrings::typeid)]
[XmlInclude(JewelForHuman::typeid)]
[XmlInclude(JewelForNeck::typeid)]
[XmlInclude(Ring::typeid)]
[XmlInclude(Watch::typeid)]
[XmlInclude(Chains::typeid)]
public ref class Jewel
{
public:
	String^ name;
	String^ typeOfMetal;
};
[Serializable]
public ref class JewelForHuman : public Jewel
{
public:
	double price;
	double weight;
};
[Serializable]
public ref class JewelForHome : public Jewel
{
public:
	double price;
	int year;
	String^ color;
};
[Serializable]
public ref class JewelForHand : public JewelForHuman
{
public:
	double diameter;
};
[Serializable]
public ref class JewelForHead : public JewelForHuman
{
public:
	String^ typeOfclasp;
};
[Serializable]
public ref class JewelForNeck : public JewelForHuman
{
public:
	int length;
};
[Serializable]
public ref class Beads : public JewelForNeck
{
public:
	int numberOfBeads;
};
[Serializable]
public ref class Box : public JewelForHome
{
public:
	String^ pattern;
};
[Serializable]
public ref class Bracelet : public JewelForHand
{
public:
	String^ typeOfBand;
	double bandLength;
};
[Serializable]
public ref class Clip : public JewelForHead
{
public:
	String^ pattern;
};
public ref class Earrings : public JewelForHead
{
public:
	String^ typeOfGemstone;
	int numberOfCarats;
};
[Serializable]
public ref class Ring : public JewelForHand
{
public:
	String^ typeOfGemstone;
	int numberOfCarats;
};
public ref class Watch :public JewelForHome
{
public:
	String^ typeOfmechanism;
	String^ typeOfBand;
	double bandLength;
};
public ref class Chains : public JewelForNeck
{
public:
	String^ typeOfNetting;
};
public ref class Store {
public:
	List<Jewel^> listJewel;
	void print() {
		Console::WriteLine("=====Список изделий=====");
		for each (Jewel^ var in listJewel)
		{
			Console::WriteLine("Имя:");
			Console::WriteLine(var->name);
			Console::WriteLine("Тип драгоценного метала:");
			Console::WriteLine(var->typeOfMetal);
			if (var->GetType()==Earrings::typeid)
			{
				Console::WriteLine("Тип изделия:\n Серьги");
				Console::WriteLine("Вес:");
				Console::WriteLine(((Earrings^)var)->weight);
				Console::WriteLine("Цена:");
				Console::WriteLine(((Earrings^)var)->price);
				Console::WriteLine("Тип застежки:");
				Console::WriteLine(((Earrings^)var)->typeOfclasp);
				Console::WriteLine("Тип драгоценного камня:");
				Console::WriteLine(((Earrings^)var)->typeOfGemstone);
				Console::WriteLine("Кол-во карат:");
				Console::WriteLine(((Earrings^)var)->numberOfCarats);
			}
			if (var->GetType()==Clip::typeid)
			{
				Console::WriteLine("Тип изделия:\n Клипсы");
				Console::WriteLine("Вес:");
				Console::WriteLine(((Clip^)var)->weight);
				Console::WriteLine("Цена:");
				Console::WriteLine(((Clip^)var)->price);
				Console::WriteLine("Тип застежки:");
				Console::WriteLine(((Clip^)var)->typeOfclasp);
				Console::WriteLine("Тип узора:");
				Console::WriteLine(((Clip^)var)->pattern);
			}
			if (var->GetType()==Beads::typeid)
			{
				Console::WriteLine("Тип изделия:\n Бусы");
				Console::WriteLine("Вес:");
				Console::WriteLine(((Beads^)var)->weight);
				Console::WriteLine("Цена:");
				Console::WriteLine(((Beads^)var)->price);
				Console::WriteLine("Длинна:");
				Console::WriteLine(((Beads^)var)->length);
				Console::WriteLine("Кол-во бусинок:");
				Console::WriteLine(((Beads^)var)->numberOfBeads);
			}
			if (var->GetType() == Chains::typeid)
			{
				Console::WriteLine("Тип изделия:\n Цепь");
				Console::WriteLine("Вес:");
				Console::WriteLine(((Chains^)var)->weight);
				Console::WriteLine("Цена:");
				Console::WriteLine(((Chains^)var)->price);
				Console::WriteLine("Длинна:");
				Console::WriteLine(((Chains^)var)->length);
				Console::WriteLine("Тип плетения:");
				Console::WriteLine(((Chains^)var)->typeOfNetting);
			}
			if (var->GetType() == Ring::typeid)
			{
				Console::WriteLine("Тип изделия:\n Кольцо");
				Console::WriteLine("Вес:");
				Console::WriteLine(((Ring^)var)->weight);
				Console::WriteLine("Цена:");
				Console::WriteLine(((Ring^)var)->price);
				Console::WriteLine("Диаметр:");
				Console::WriteLine(((Ring^)var)->diameter);
				Console::WriteLine("Тип драгоценного камня:");
				Console::WriteLine(((Ring^)var)->typeOfGemstone);
				Console::WriteLine("Кол-во карат:");
				Console::WriteLine(((Ring^)var)->numberOfCarats);
			}
			if (var->GetType() == Bracelet::typeid)
			{
				Console::WriteLine("Тип изделия:\n Браслет");
				Console::WriteLine("Вес:");
				Console::WriteLine(((Bracelet^)var)->weight);
				Console::WriteLine("Цена:");
				Console::WriteLine(((Bracelet^)var)->price);
				Console::WriteLine("Диаметр:");
				Console::WriteLine(((Bracelet^)var)->diameter);
				Console::WriteLine("Тип плетения:");
				Console::WriteLine(((Bracelet^)var)->typeOfBand);
				Console::WriteLine("Длинна браслета:");
				Console::WriteLine(((Bracelet^)var)->bandLength);
			}
			Console::WriteLine("_______________________");
		}
	}
};

int main() {
	setlocale(LC_ALL, "");
	int operation=1;
	int index;
	Store^ MainStore = gcnew Store;
	String^ filename = "E:\\test\\1.xml";
	Earrings^ ear1;
	Clip^ clip1;
	Beads^ beads1;
	Chains^ chains1;
	Ring^ ring1;
	Bracelet^ bracelet1;
	XmlSerializer^ ser1;
	TextWriter^ writer1;
	TextReader^ reader;
	String^ name;
	while (operation!=0)
	{
		Console::WriteLine("1.Считать из XML файла");
		Console::WriteLine("2.Добавить ювелирное изделие");
		Console::WriteLine("3.Удалить ювелирное изделие");
		Console::WriteLine("4.Редактировать изделие");
		Console::WriteLine("5.Записать в файл");
		Console::WriteLine("0.Выход");
		Console::WriteLine("Операция:");
		operation = int::Parse(Console::ReadLine());
		switch (operation){
			case 1:

				ser1 = gcnew XmlSerializer(MainStore->GetType());
				reader = gcnew StreamReader(filename);
				MainStore = (Store^)ser1->Deserialize(reader);
				reader->Close();
				break;
			case 2:
				Console::WriteLine("1.Добавить серьги");
				Console::WriteLine("2.Добавить клипсы");
				Console::WriteLine("3.Добавить бусы");
				Console::WriteLine("4.Добавить цепь");
				Console::WriteLine("5.Добавить кольцо");
				Console::WriteLine("6.Добавить браслет");
				Console::WriteLine("Тип изделия: ");
				operation = int::Parse(Console::ReadLine());
				switch (operation)
				{

				case 1:
					ear1 = gcnew Earrings;
					Console::WriteLine("Имя:");
					ear1->name=Console::ReadLine();
					Console::WriteLine("Тип драгоценного метала:");
					ear1->typeOfMetal= Console::ReadLine();
					Console::WriteLine("Вес:");
					ear1->weight = double::Parse(Console::ReadLine());
					Console::WriteLine("Цена:");
					ear1->price= double::Parse(Console::ReadLine());
					Console::WriteLine("Тип застежки:");
					ear1->typeOfclasp = Console::ReadLine();
					Console::WriteLine("Тип драгоценного камня:");
					ear1->typeOfGemstone= Console::ReadLine();
					Console::WriteLine("Кол-во карат:");
					ear1->numberOfCarats = int::Parse(Console::ReadLine());
					MainStore->listJewel.Add(ear1);
					break;
				case 2:
					clip1 = gcnew Clip;
					Console::WriteLine("Имя:");
					clip1->name = Console::ReadLine();
					Console::WriteLine("Тип драгоценного метала:");
					clip1->typeOfMetal = Console::ReadLine();
					Console::WriteLine("Вес:");
					clip1->weight = double::Parse(Console::ReadLine());
					Console::WriteLine("Цена:");
					clip1->price = double::Parse(Console::ReadLine());
					Console::WriteLine("Тип застежки:");
					clip1->typeOfclasp = Console::ReadLine();
					Console::WriteLine("Тип узора:");
					clip1->pattern= Console::ReadLine();
					MainStore->listJewel.Add(clip1);
					break;
				case 3:
					beads1 = gcnew Beads;
					Console::WriteLine("Имя:");
					beads1->name = Console::ReadLine();
					Console::WriteLine("Тип драгоценного метала:");
					beads1->typeOfMetal = Console::ReadLine();
					Console::WriteLine("Вес:");
					beads1->weight = double::Parse(Console::ReadLine());
					Console::WriteLine("Цена:");
					beads1->price = double::Parse(Console::ReadLine());
					Console::WriteLine("Длинна:");
					beads1->length = int::Parse(Console::ReadLine());
					Console::WriteLine("Кол-во бусинок:");
					beads1->numberOfBeads = int::Parse(Console::ReadLine());
					MainStore->listJewel.Add(beads1);
					break;
				case 4:
					chains1 = gcnew Chains;
					Console::WriteLine("Имя:");
					chains1->name = Console::ReadLine();
					Console::WriteLine("Тип драгоценного метала:");
					chains1->typeOfMetal = Console::ReadLine();
					Console::WriteLine("Вес:");
					chains1->weight = double::Parse(Console::ReadLine());
					Console::WriteLine("Цена:");
					chains1->price = double::Parse(Console::ReadLine());
					Console::WriteLine("Длинна:");
					chains1->length = int::Parse(Console::ReadLine());
					Console::WriteLine("Тип плетения:");
					chains1->typeOfNetting = Console::ReadLine();
					MainStore->listJewel.Add(chains1);
					break;
				case 5:
					ring1 = gcnew Ring;
					Console::WriteLine("Имя:");
					ring1->name = Console::ReadLine();
					Console::WriteLine("Тип драгоценного метала:");
					ring1->typeOfMetal = Console::ReadLine();
					Console::WriteLine("Вес:");
					ring1->weight = double::Parse(Console::ReadLine());
					Console::WriteLine("Цена:");
					ring1->price = double::Parse(Console::ReadLine());
					Console::WriteLine("Диаметр:");
					ring1->diameter= double::Parse(Console::ReadLine());
					Console::WriteLine("Тип драгоценного камня:");
					ring1->typeOfGemstone = Console::ReadLine();
					Console::WriteLine("Кол-во карат:");
					ring1->numberOfCarats = int::Parse(Console::ReadLine());
					MainStore->listJewel.Add(ring1);
					break;
				case 6:
					bracelet1 = gcnew Bracelet;
					Console::WriteLine("Имя:");
					bracelet1->name = Console::ReadLine();
					Console::WriteLine("Тип драгоценного метала:");
					bracelet1->typeOfMetal = Console::ReadLine();
					Console::WriteLine("Вес:");
					bracelet1->weight = double::Parse(Console::ReadLine());
					Console::WriteLine("Цена:");
					bracelet1->price = double::Parse(Console::ReadLine());
					Console::WriteLine("Диаметр:");
					bracelet1->diameter = double::Parse(Console::ReadLine());
					Console::WriteLine("Тип плетения:");
					bracelet1->typeOfBand = Console::ReadLine();
					Console::WriteLine("Длинна браслета:");
					bracelet1->bandLength = double::Parse(Console::ReadLine());
					MainStore->listJewel.Add(bracelet1);
					break;
				default:
					break;
				}
				break;
			case 3:
				Console::WriteLine("Введите номер удаляемого изделия:");
				index = int::Parse(Console::ReadLine());
				MainStore->listJewel.RemoveAt(index);
				break;
			case 4:
				Console::WriteLine("Введите номер изменяемого изделия:");
				index = int::Parse(Console::ReadLine());
				MainStore->listJewel.RemoveAt(index);
				Console::WriteLine("1.Изменить на серьги");
				Console::WriteLine("2.Изменить на клипсы");
				Console::WriteLine("3.Изменить на бусы");
				Console::WriteLine("4.Изменить на цепь");
				Console::WriteLine("5.Изменить на кольцо");
				Console::WriteLine("6.изменить на браслет");
				Console::WriteLine("Тип изделия: ");
				operation = int::Parse(Console::ReadLine());
				switch (operation)
				{

				case 1:
					ear1 = gcnew Earrings;
					Console::WriteLine("Имя:");
					ear1->name = Console::ReadLine();
					Console::WriteLine("Тип драгоценного метала:");
					ear1->typeOfMetal = Console::ReadLine();
					Console::WriteLine("Вес:");
					ear1->weight = double::Parse(Console::ReadLine());
					Console::WriteLine("Цена:");
					ear1->price = double::Parse(Console::ReadLine());
					Console::WriteLine("Тип застежки:");
					ear1->typeOfclasp = Console::ReadLine();
					Console::WriteLine("Тип драгоценного камня:");
					ear1->typeOfGemstone = Console::ReadLine();
					Console::WriteLine("Кол-во карат:");
					ear1->numberOfCarats = int::Parse(Console::ReadLine());
					MainStore->listJewel.Insert(index, ear1);
					break;
				case 2:
					clip1 = gcnew Clip;
					Console::WriteLine("Имя:");
					clip1->name = Console::ReadLine();
					Console::WriteLine("Тип драгоценного метала:");
					clip1->typeOfMetal = Console::ReadLine();
					Console::WriteLine("Вес:");
					clip1->weight = double::Parse(Console::ReadLine());
					Console::WriteLine("Цена:");
					clip1->price = double::Parse(Console::ReadLine());
					Console::WriteLine("Тип застежки:");
					clip1->typeOfclasp = Console::ReadLine();
					Console::WriteLine("Тип узора:");
					clip1->pattern = Console::ReadLine();
					MainStore->listJewel.Insert(index, clip1);
					break;
				case 3:
					beads1 = gcnew Beads;
					Console::WriteLine("Имя:");
					beads1->name = Console::ReadLine();
					Console::WriteLine("Тип драгоценного метала:");
					beads1->typeOfMetal = Console::ReadLine();
					Console::WriteLine("Вес:");
					beads1->weight = double::Parse(Console::ReadLine());
					Console::WriteLine("Цена:");
					beads1->price = double::Parse(Console::ReadLine());
					Console::WriteLine("Длинна:");
					beads1->length = int::Parse(Console::ReadLine());
					Console::WriteLine("Кол-во бусинок:");
					beads1->numberOfBeads = int::Parse(Console::ReadLine());
					MainStore->listJewel.Insert(index, beads1);
					break;
				case 4:
					chains1 = gcnew Chains;
					Console::WriteLine("Имя:");
					chains1->name = Console::ReadLine();
					Console::WriteLine("Тип драгоценного метала:");
					chains1->typeOfMetal = Console::ReadLine();
					Console::WriteLine("Вес:");
					chains1->weight = double::Parse(Console::ReadLine());
					Console::WriteLine("Цена:");
					chains1->price = double::Parse(Console::ReadLine());
					Console::WriteLine("Длинна:");
					chains1->length = int::Parse(Console::ReadLine());
					Console::WriteLine("Тип плетения:");
					chains1->typeOfNetting = Console::ReadLine();
					MainStore->listJewel.Insert(index, chains1);
					break;
				case 5:
					ring1 = gcnew Ring;
					Console::WriteLine("Имя:");
					ring1->name = Console::ReadLine();
					Console::WriteLine("Тип драгоценного метала:");
					ring1->typeOfMetal = Console::ReadLine();
					Console::WriteLine("Вес:");
					ring1->weight = double::Parse(Console::ReadLine());
					Console::WriteLine("Цена:");
					ring1->price = double::Parse(Console::ReadLine());
					Console::WriteLine("Диаметр:");
					ring1->diameter = double::Parse(Console::ReadLine());
					Console::WriteLine("Тип драгоценного камня:");
					ring1->typeOfGemstone = Console::ReadLine();
					Console::WriteLine("Кол-во карат:");
					ring1->numberOfCarats = int::Parse(Console::ReadLine());
					MainStore->listJewel.Insert(index, ring1);
					break;
				case 6:
					bracelet1 = gcnew Bracelet;
					Console::WriteLine("Имя:");
					bracelet1->name = Console::ReadLine();
					Console::WriteLine("Тип драгоценного метала:");
					bracelet1->typeOfMetal = Console::ReadLine();
					Console::WriteLine("Вес:");
					bracelet1->weight = double::Parse(Console::ReadLine());
					Console::WriteLine("Цена:");
					bracelet1->price = double::Parse(Console::ReadLine());
					Console::WriteLine("Диаметр:");
					bracelet1->diameter = double::Parse(Console::ReadLine());
					Console::WriteLine("Тип плетения:");
					bracelet1->typeOfBand = Console::ReadLine();
					Console::WriteLine("Длинна браслета:");
					bracelet1->bandLength = double::Parse(Console::ReadLine());
					MainStore->listJewel.Insert(index,bracelet1);
					break;
				default:
					break;
				}
				break;
			case 5:
				ser1 = gcnew XmlSerializer(MainStore->GetType());
				writer1 = gcnew StreamWriter(filename);
				ser1->Serialize(writer1, MainStore);
				writer1->Close();
				break;
		default:
			break;
		}
		if (operation!=0)
			MainStore->print();
	}
}