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
		Console::WriteLine("=====������ �������=====");
		for each (Jewel^ var in listJewel)
		{
			Console::WriteLine("���:");
			Console::WriteLine(var->name);
			Console::WriteLine("��� ������������ ������:");
			Console::WriteLine(var->typeOfMetal);
			if (var->GetType()==Earrings::typeid)
			{
				Console::WriteLine("��� �������:\n ������");
				Console::WriteLine("���:");
				Console::WriteLine(((Earrings^)var)->weight);
				Console::WriteLine("����:");
				Console::WriteLine(((Earrings^)var)->price);
				Console::WriteLine("��� ��������:");
				Console::WriteLine(((Earrings^)var)->typeOfclasp);
				Console::WriteLine("��� ������������ �����:");
				Console::WriteLine(((Earrings^)var)->typeOfGemstone);
				Console::WriteLine("���-�� �����:");
				Console::WriteLine(((Earrings^)var)->numberOfCarats);
			}
			if (var->GetType()==Clip::typeid)
			{
				Console::WriteLine("��� �������:\n ������");
				Console::WriteLine("���:");
				Console::WriteLine(((Clip^)var)->weight);
				Console::WriteLine("����:");
				Console::WriteLine(((Clip^)var)->price);
				Console::WriteLine("��� ��������:");
				Console::WriteLine(((Clip^)var)->typeOfclasp);
				Console::WriteLine("��� �����:");
				Console::WriteLine(((Clip^)var)->pattern);
			}
			if (var->GetType()==Beads::typeid)
			{
				Console::WriteLine("��� �������:\n ����");
				Console::WriteLine("���:");
				Console::WriteLine(((Beads^)var)->weight);
				Console::WriteLine("����:");
				Console::WriteLine(((Beads^)var)->price);
				Console::WriteLine("������:");
				Console::WriteLine(((Beads^)var)->length);
				Console::WriteLine("���-�� �������:");
				Console::WriteLine(((Beads^)var)->numberOfBeads);
			}
			if (var->GetType() == Chains::typeid)
			{
				Console::WriteLine("��� �������:\n ����");
				Console::WriteLine("���:");
				Console::WriteLine(((Chains^)var)->weight);
				Console::WriteLine("����:");
				Console::WriteLine(((Chains^)var)->price);
				Console::WriteLine("������:");
				Console::WriteLine(((Chains^)var)->length);
				Console::WriteLine("��� ��������:");
				Console::WriteLine(((Chains^)var)->typeOfNetting);
			}
			if (var->GetType() == Ring::typeid)
			{
				Console::WriteLine("��� �������:\n ������");
				Console::WriteLine("���:");
				Console::WriteLine(((Ring^)var)->weight);
				Console::WriteLine("����:");
				Console::WriteLine(((Ring^)var)->price);
				Console::WriteLine("�������:");
				Console::WriteLine(((Ring^)var)->diameter);
				Console::WriteLine("��� ������������ �����:");
				Console::WriteLine(((Ring^)var)->typeOfGemstone);
				Console::WriteLine("���-�� �����:");
				Console::WriteLine(((Ring^)var)->numberOfCarats);
			}
			if (var->GetType() == Bracelet::typeid)
			{
				Console::WriteLine("��� �������:\n �������");
				Console::WriteLine("���:");
				Console::WriteLine(((Bracelet^)var)->weight);
				Console::WriteLine("����:");
				Console::WriteLine(((Bracelet^)var)->price);
				Console::WriteLine("�������:");
				Console::WriteLine(((Bracelet^)var)->diameter);
				Console::WriteLine("��� ��������:");
				Console::WriteLine(((Bracelet^)var)->typeOfBand);
				Console::WriteLine("������ ��������:");
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
		Console::WriteLine("1.������� �� XML �����");
		Console::WriteLine("2.�������� ��������� �������");
		Console::WriteLine("3.������� ��������� �������");
		Console::WriteLine("4.������������� �������");
		Console::WriteLine("5.�������� � ����");
		Console::WriteLine("0.�����");
		Console::WriteLine("��������:");
		operation = int::Parse(Console::ReadLine());
		switch (operation){
			case 1:

				ser1 = gcnew XmlSerializer(MainStore->GetType());
				reader = gcnew StreamReader(filename);
				MainStore = (Store^)ser1->Deserialize(reader);
				reader->Close();
				break;
			case 2:
				Console::WriteLine("1.�������� ������");
				Console::WriteLine("2.�������� ������");
				Console::WriteLine("3.�������� ����");
				Console::WriteLine("4.�������� ����");
				Console::WriteLine("5.�������� ������");
				Console::WriteLine("6.�������� �������");
				Console::WriteLine("��� �������: ");
				operation = int::Parse(Console::ReadLine());
				switch (operation)
				{

				case 1:
					ear1 = gcnew Earrings;
					Console::WriteLine("���:");
					ear1->name=Console::ReadLine();
					Console::WriteLine("��� ������������ ������:");
					ear1->typeOfMetal= Console::ReadLine();
					Console::WriteLine("���:");
					ear1->weight = double::Parse(Console::ReadLine());
					Console::WriteLine("����:");
					ear1->price= double::Parse(Console::ReadLine());
					Console::WriteLine("��� ��������:");
					ear1->typeOfclasp = Console::ReadLine();
					Console::WriteLine("��� ������������ �����:");
					ear1->typeOfGemstone= Console::ReadLine();
					Console::WriteLine("���-�� �����:");
					ear1->numberOfCarats = int::Parse(Console::ReadLine());
					MainStore->listJewel.Add(ear1);
					break;
				case 2:
					clip1 = gcnew Clip;
					Console::WriteLine("���:");
					clip1->name = Console::ReadLine();
					Console::WriteLine("��� ������������ ������:");
					clip1->typeOfMetal = Console::ReadLine();
					Console::WriteLine("���:");
					clip1->weight = double::Parse(Console::ReadLine());
					Console::WriteLine("����:");
					clip1->price = double::Parse(Console::ReadLine());
					Console::WriteLine("��� ��������:");
					clip1->typeOfclasp = Console::ReadLine();
					Console::WriteLine("��� �����:");
					clip1->pattern= Console::ReadLine();
					MainStore->listJewel.Add(clip1);
					break;
				case 3:
					beads1 = gcnew Beads;
					Console::WriteLine("���:");
					beads1->name = Console::ReadLine();
					Console::WriteLine("��� ������������ ������:");
					beads1->typeOfMetal = Console::ReadLine();
					Console::WriteLine("���:");
					beads1->weight = double::Parse(Console::ReadLine());
					Console::WriteLine("����:");
					beads1->price = double::Parse(Console::ReadLine());
					Console::WriteLine("������:");
					beads1->length = int::Parse(Console::ReadLine());
					Console::WriteLine("���-�� �������:");
					beads1->numberOfBeads = int::Parse(Console::ReadLine());
					MainStore->listJewel.Add(beads1);
					break;
				case 4:
					chains1 = gcnew Chains;
					Console::WriteLine("���:");
					chains1->name = Console::ReadLine();
					Console::WriteLine("��� ������������ ������:");
					chains1->typeOfMetal = Console::ReadLine();
					Console::WriteLine("���:");
					chains1->weight = double::Parse(Console::ReadLine());
					Console::WriteLine("����:");
					chains1->price = double::Parse(Console::ReadLine());
					Console::WriteLine("������:");
					chains1->length = int::Parse(Console::ReadLine());
					Console::WriteLine("��� ��������:");
					chains1->typeOfNetting = Console::ReadLine();
					MainStore->listJewel.Add(chains1);
					break;
				case 5:
					ring1 = gcnew Ring;
					Console::WriteLine("���:");
					ring1->name = Console::ReadLine();
					Console::WriteLine("��� ������������ ������:");
					ring1->typeOfMetal = Console::ReadLine();
					Console::WriteLine("���:");
					ring1->weight = double::Parse(Console::ReadLine());
					Console::WriteLine("����:");
					ring1->price = double::Parse(Console::ReadLine());
					Console::WriteLine("�������:");
					ring1->diameter= double::Parse(Console::ReadLine());
					Console::WriteLine("��� ������������ �����:");
					ring1->typeOfGemstone = Console::ReadLine();
					Console::WriteLine("���-�� �����:");
					ring1->numberOfCarats = int::Parse(Console::ReadLine());
					MainStore->listJewel.Add(ring1);
					break;
				case 6:
					bracelet1 = gcnew Bracelet;
					Console::WriteLine("���:");
					bracelet1->name = Console::ReadLine();
					Console::WriteLine("��� ������������ ������:");
					bracelet1->typeOfMetal = Console::ReadLine();
					Console::WriteLine("���:");
					bracelet1->weight = double::Parse(Console::ReadLine());
					Console::WriteLine("����:");
					bracelet1->price = double::Parse(Console::ReadLine());
					Console::WriteLine("�������:");
					bracelet1->diameter = double::Parse(Console::ReadLine());
					Console::WriteLine("��� ��������:");
					bracelet1->typeOfBand = Console::ReadLine();
					Console::WriteLine("������ ��������:");
					bracelet1->bandLength = double::Parse(Console::ReadLine());
					MainStore->listJewel.Add(bracelet1);
					break;
				default:
					break;
				}
				break;
			case 3:
				Console::WriteLine("������� ����� ���������� �������:");
				index = int::Parse(Console::ReadLine());
				MainStore->listJewel.RemoveAt(index);
				break;
			case 4:
				Console::WriteLine("������� ����� ����������� �������:");
				index = int::Parse(Console::ReadLine());
				MainStore->listJewel.RemoveAt(index);
				Console::WriteLine("1.�������� �� ������");
				Console::WriteLine("2.�������� �� ������");
				Console::WriteLine("3.�������� �� ����");
				Console::WriteLine("4.�������� �� ����");
				Console::WriteLine("5.�������� �� ������");
				Console::WriteLine("6.�������� �� �������");
				Console::WriteLine("��� �������: ");
				operation = int::Parse(Console::ReadLine());
				switch (operation)
				{

				case 1:
					ear1 = gcnew Earrings;
					Console::WriteLine("���:");
					ear1->name = Console::ReadLine();
					Console::WriteLine("��� ������������ ������:");
					ear1->typeOfMetal = Console::ReadLine();
					Console::WriteLine("���:");
					ear1->weight = double::Parse(Console::ReadLine());
					Console::WriteLine("����:");
					ear1->price = double::Parse(Console::ReadLine());
					Console::WriteLine("��� ��������:");
					ear1->typeOfclasp = Console::ReadLine();
					Console::WriteLine("��� ������������ �����:");
					ear1->typeOfGemstone = Console::ReadLine();
					Console::WriteLine("���-�� �����:");
					ear1->numberOfCarats = int::Parse(Console::ReadLine());
					MainStore->listJewel.Insert(index, ear1);
					break;
				case 2:
					clip1 = gcnew Clip;
					Console::WriteLine("���:");
					clip1->name = Console::ReadLine();
					Console::WriteLine("��� ������������ ������:");
					clip1->typeOfMetal = Console::ReadLine();
					Console::WriteLine("���:");
					clip1->weight = double::Parse(Console::ReadLine());
					Console::WriteLine("����:");
					clip1->price = double::Parse(Console::ReadLine());
					Console::WriteLine("��� ��������:");
					clip1->typeOfclasp = Console::ReadLine();
					Console::WriteLine("��� �����:");
					clip1->pattern = Console::ReadLine();
					MainStore->listJewel.Insert(index, clip1);
					break;
				case 3:
					beads1 = gcnew Beads;
					Console::WriteLine("���:");
					beads1->name = Console::ReadLine();
					Console::WriteLine("��� ������������ ������:");
					beads1->typeOfMetal = Console::ReadLine();
					Console::WriteLine("���:");
					beads1->weight = double::Parse(Console::ReadLine());
					Console::WriteLine("����:");
					beads1->price = double::Parse(Console::ReadLine());
					Console::WriteLine("������:");
					beads1->length = int::Parse(Console::ReadLine());
					Console::WriteLine("���-�� �������:");
					beads1->numberOfBeads = int::Parse(Console::ReadLine());
					MainStore->listJewel.Insert(index, beads1);
					break;
				case 4:
					chains1 = gcnew Chains;
					Console::WriteLine("���:");
					chains1->name = Console::ReadLine();
					Console::WriteLine("��� ������������ ������:");
					chains1->typeOfMetal = Console::ReadLine();
					Console::WriteLine("���:");
					chains1->weight = double::Parse(Console::ReadLine());
					Console::WriteLine("����:");
					chains1->price = double::Parse(Console::ReadLine());
					Console::WriteLine("������:");
					chains1->length = int::Parse(Console::ReadLine());
					Console::WriteLine("��� ��������:");
					chains1->typeOfNetting = Console::ReadLine();
					MainStore->listJewel.Insert(index, chains1);
					break;
				case 5:
					ring1 = gcnew Ring;
					Console::WriteLine("���:");
					ring1->name = Console::ReadLine();
					Console::WriteLine("��� ������������ ������:");
					ring1->typeOfMetal = Console::ReadLine();
					Console::WriteLine("���:");
					ring1->weight = double::Parse(Console::ReadLine());
					Console::WriteLine("����:");
					ring1->price = double::Parse(Console::ReadLine());
					Console::WriteLine("�������:");
					ring1->diameter = double::Parse(Console::ReadLine());
					Console::WriteLine("��� ������������ �����:");
					ring1->typeOfGemstone = Console::ReadLine();
					Console::WriteLine("���-�� �����:");
					ring1->numberOfCarats = int::Parse(Console::ReadLine());
					MainStore->listJewel.Insert(index, ring1);
					break;
				case 6:
					bracelet1 = gcnew Bracelet;
					Console::WriteLine("���:");
					bracelet1->name = Console::ReadLine();
					Console::WriteLine("��� ������������ ������:");
					bracelet1->typeOfMetal = Console::ReadLine();
					Console::WriteLine("���:");
					bracelet1->weight = double::Parse(Console::ReadLine());
					Console::WriteLine("����:");
					bracelet1->price = double::Parse(Console::ReadLine());
					Console::WriteLine("�������:");
					bracelet1->diameter = double::Parse(Console::ReadLine());
					Console::WriteLine("��� ��������:");
					bracelet1->typeOfBand = Console::ReadLine();
					Console::WriteLine("������ ��������:");
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