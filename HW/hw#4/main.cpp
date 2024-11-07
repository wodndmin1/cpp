#include <iostream>
#include <string>
using namespace std;

class printer {
	string model;
	string manufacturer;
	int printedCount;
	int availableCount;
public:
	printer(string m, string ma, int a) {
		model = m;
		manufacturer = ma;
		availableCount = a;
	}
	string getModel() { return model; }
	string getManu() { return manufacturer; }
	int getAvail() { return availableCount; }
	bool print(int pages) {
		printedCount = pages;
		if (availableCount >= printedCount) {
			availableCount -= printedCount;
			return true;
		}
		else {
			cout << "������ �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
			return false;
		}
	}
};

class Ink : 
	public printer {
	int availableInk;
public:
	Ink(string m, string ma, int a, int aInk) : printer(m, ma, a) {
		availableInk = aInk;
	}
	void printInkJet(int pages) {
		if (print(pages)) {
			if (availableInk >= pages) {
				availableInk -= pages;
				cout << "����Ʈ�Ͽ����ϴ�." << endl;
			}
		}
	}
	void show() {
		cout << getModel() << " ," << getManu() << " ,���� ���� " << getAvail() << "�� ,���� ��ũ " << availableInk << endl;
	}
};

class Laser : public printer {
	int availableToner;
public:
	Laser(string m, string ma, int a, int aToner) : printer(m, ma, a) {
		availableToner = aToner;
	}
	void printLaser(int pages) {
		if (print(pages)) {
			if (availableToner >= pages) {
				availableToner -= pages;
				cout << "����Ʈ�Ͽ����ϴ�." << endl;
			}
		}
	}
	void show() {
		cout << getModel() << " ," << getManu() << " ,���� ���� " << getAvail() << "�� ,������� " << availableToner << endl;
	}
};

int main() {
	Ink* IP = new Ink("Officejet V40", "HP", 5, 10);
	Laser* LP = new Laser("SCX-6x45", "�Ｚ����", 3, 20);
	int n1, n2;
	char a;

	cout << "���� �۵����� 2 ���� �����ʹ� �Ʒ��� ����" << endl;
	cout << "��ũ�� : "; IP->show();
	cout << "������ : "; LP->show();

	while (1) {
		cout << endl << "������(1:��ũ��, 2:������)�� �ż� �Է�>>";
		cin >> n1 >> n2;
		if (n1 == 1)
		{
			IP->printInkJet(n2);
			IP->show();
			LP->show();
		}
		if (n1 == 2)
		{
			LP->printLaser(n2);
			IP->show();
			LP->show();
		}
		cout << "��� ����Ʈ �Ͻðڽ��ϱ�(y/n)>>";
		cin >> a;
		if (a == 'n') break;
	}
}
