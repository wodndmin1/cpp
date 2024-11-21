#include <iostream>
#include <string>
#include "Shape.h"
#include "Circle.h"
#include "Rect.h"
#include "Line.h"
#include <vector>
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
class GraphicEditor {
    vector<Shape*> v;
    vector<Shape*>::iterator it;
public:
    GraphicEditor() {}
    void insert() {
        int n = UI::insert();
        if (n == 1) // ����
            v.push_back(new Line());
        else if (n == 2)  // ��
            v.push_back(new Circle());
        else if (n == 3) // �簢��
            v.push_back(new Rect());
        else cout << "�Է� ����" << endl;
    }
    void deleteShape() {
        int n = UI::del();
        Shape* del;
        it = v.begin();
        for (int i = 0; i < n; ++i)
            ++it;
        del = *it;
        it = v.erase(it);
        delete del;
    }
    void showAll() {
        for (int i = 0; i < v.size(); ++i) {
            cout << i << ": ";
            v[i]->paint();
        }
    }
    void start() {
        UI::start();
        for (;;) {
            int m = UI::menu();
            if (m == 1) // ����
                insert();
            else if (m == 2) // ����
                deleteShape();
            else if (m == 3)  // ��ü ����
                showAll();
            else if (m == 4) break;
            else cout << "�Է� ���� " << endl;
        }
    }
};
int main() {
    GraphicEditor* g = new GraphicEditor;
    g->start();
    delete g;
}