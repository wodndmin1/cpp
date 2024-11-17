#include <iostream>
#include <string>
using namespace std;
class UI { // ȭ�� ��� �� Ű �Է� �Լ�
    static int n; // ���� ����� ���� �Է� ���� ����
public:
    static void start(); // ù�ٿ� ������ �׷��� ������ �Դϴ� ���
    static int menu(); // ���� ���� ��κ��� ����
    static int insert(); // ���� ����
    static int del(); // ���� ����
};
int UI::n = 0;
void UI::start() {
    cout << "�׷��� �������Դϴ�." << endl;
}
int UI::menu() { // �޴� ��� �� �Է�
    cout << "����:1, ����:2, ��κ���:3, ����:4 >> ";
    cin >> n;
    return n;
}
int UI::insert() { // ���� ���Կ� ���� �޴� ��� �� �Է�
    cout << "��:1, ��:2, �簢��:3 >> ";
    cin >> n;
    return n;
}
int UI::del() { // ���� ������ ���� �޴� ��� �� �Է�
    cout << "�����ϰ��� �ϴ� ������ �ε��� >> ";
    cin >> n;
    return n;
}
class GraphicEditor { // �Ļ�Ŭ����
    int index; // ������ �ε���
public:
    GraphicEditor(int i) { index = i; }
    virtual void show() = 0; // �� �������� ����Լ��� �����ϱ� ���� ���� ���� �Լ� ���
    int getIndex() { return index; }
    void subIndex() { --index; }
};
class Line : public GraphicEditor {
public:
    Line(int index) : GraphicEditor(index) {}
    void show() { cout << getIndex() << ": Line" << endl; }
};
class Circle : public GraphicEditor {
public:
    Circle(int index) : GraphicEditor(index) {}
    void show() { cout << getIndex() << ": Circle" << endl; }
};
class Rect : public GraphicEditor {
public:
    Rect(int index) : GraphicEditor(index) {}
    void show() { cout << getIndex() << ": Rectangle" << endl; }
};
int main() {
    GraphicEditor* g[100];// �� 100 ���� ������ �ִ� �׷��� ������
    UI::start();
    int index = 0;
    for (;;) {
        int m = UI::menu();
        if (m == 1) { // ����
            int n = UI::insert();
            if (n == 1) { // ����
                Line* l = new Line(index); //���� ��ü�� �׷��� ��ü �迭�� ����
                g[index] = l;
                ++index;
            }
            else if (n == 2) { // ��
                Circle* c = new Circle(index); //�� ��ü�� �׷��� ��ü �迭�� ����
                g[index] = c;
                ++index;
            }
            else if (n == 3) { // �簢��
                Rect* r = new Rect(index);//�簢�� ��ü�� �׷��� ��ü �迭�� ����
                g[index] = r;
                ++index;
            }
            else cout << "�Է� ����" << endl;
        }
        else if (m == 2) { // ����
            int n = UI::del();
            for (int i = n; i < index - 1; ++i) { // ��ĭ�� ����
                g[i] = g[i + 1];
                g[i]->subIndex(); // ��ĭ�� ��丸ŭ �ε��� ����
            }
            --index; // ��ü ũ�� ����
        }
        else if (m == 3) { // ��ü ����
            for (int i = 0; i < index; ++i)
                g[i]->show();
        }
        else if (m == 4) break;
        else cout << "�Է� ���� " << endl;
    }
}