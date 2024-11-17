#include <iostream>
#include <string>
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
class GraphicEditor { // 파생클래스
    int index; // 도형의 인덱스
public:
    GraphicEditor(int i) { index = i; }
    virtual void show() = 0; // 각 도형들의 출력함수를 구현하기 위해 순수 가상 함수 사용
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
    GraphicEditor* g[100];// 총 100 개를 담을수 있는 그래픽 에디터
    UI::start();
    int index = 0;
    for (;;) {
        int m = UI::menu();
        if (m == 1) { // 삽입
            int n = UI::insert();
            if (n == 1) { // 라인
                Line* l = new Line(index); //라인 객체를 그래픽 객체 배열에 저장
                g[index] = l;
                ++index;
            }
            else if (n == 2) { // 원
                Circle* c = new Circle(index); //원 객체를 그래픽 객체 배열에 저장
                g[index] = c;
                ++index;
            }
            else if (n == 3) { // 사각형
                Rect* r = new Rect(index);//사각형 객체를 그래픽 객체 배열에 저장
                g[index] = r;
                ++index;
            }
            else cout << "입력 에러" << endl;
        }
        else if (m == 2) { // 삭제
            int n = UI::del();
            for (int i = n; i < index - 1; ++i) { // 한칸씩 당기고
                g[i] = g[i + 1];
                g[i]->subIndex(); // 한칸씩 당긴만큼 인덱스 감소
            }
            --index; // 전체 크기 감소
        }
        else if (m == 3) { // 전체 보기
            for (int i = 0; i < index; ++i)
                g[i]->show();
        }
        else if (m == 4) break;
        else cout << "입력 에러 " << endl;
    }
}