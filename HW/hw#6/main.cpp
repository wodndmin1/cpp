#include <iostream>
#include <string>
#include "Shape.h"
#include "Circle.h"
#include "Rect.h"
#include "Line.h"
#include <vector>
using namespace std;
class UI { // 화면 출력 및 키 입력 함수
    static int n; // 무슨 기능을 할지 입력 받은 숫자
public:
    static void start(); // 첫줄에 나오는 그래픽 에디터 입니다 출력
    static int menu(); // 삽입 삭제 모두보기 종료
    static int insert(); // 도형 삽입
    static int del(); // 도형 삭제
};
int UI::n = 0;
void UI::start() {
    cout << "그래픽 에디터입니다." << endl;
}
int UI::menu() { // 메뉴 출력 및 입력
    cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >> ";
    cin >> n;
    return n;
}
int UI::insert() { // 도형 삽입에 대한 메뉴 출력 및 입력
    cout << "선:1, 원:2, 사각형:3 >> ";
    cin >> n;
    return n;
}
int UI::del() { // 도형 삭제에 대한 메뉴 출력 및 입력
    cout << "삭제하고자 하는 도형의 인덱스 >> ";
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
        if (n == 1) // 라인
            v.push_back(new Line());
        else if (n == 2)  // 원
            v.push_back(new Circle());
        else if (n == 3) // 사각형
            v.push_back(new Rect());
        else cout << "입력 에러" << endl;
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
            if (m == 1) // 삽입
                insert();
            else if (m == 2) // 삭제
                deleteShape();
            else if (m == 3)  // 전체 보기
                showAll();
            else if (m == 4) break;
            else cout << "입력 에러 " << endl;
        }
    }
};
int main() {
    GraphicEditor* g = new GraphicEditor;
    g->start();
    delete g;
}