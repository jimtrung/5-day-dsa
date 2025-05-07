#include <iostream>
#include <iomanip>
using namespace std;

struct PhanSo {
    int tuSo, mauSo;
};

typedef PhanSo Data;

Data setData() {
    Data d;
    cout << "Nhap tu so: "; cin >> d.tuSo;
    cout << "Nhap mau so: "; cin >> d.mauSo;
    return d;
}

void getData(Data d) {
    cout << d.tuSo << "/" << d.mauSo;
}

struct Node {
    Data data;
    Node* next;
};

Node* createNewNode(Data value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

struct Stack {
    Node* head;
};

void newStack(Stack &s) {
    s.head = NULL; 
}

bool isEmpty(Stack s) {
    return s.head == NULL;
}

void push(Stack &s, Data value) {
    Node* newNode = createNewNode(value);
    newNode->next = s.head;
    s.head = newNode;
}

void pop(Stack &s, Data &d) {
    if (isEmpty(s)) {
        cout << "Ngan xep rong" << endl;
        return;
    }
    d = s.head->data;
    Node* curr = s.head;
    s.head = s.head->next;
    delete curr;
}

int main() {
    Stack s;
    newStack(s);
    
    int N;
    do {
        cout << "Nhap so luong phan so: ";
        cin >> N;
    } while (N <= 0);
    
    for (int i = 1; i <= N; i++) {
        cout << "Nhap thong tin phan so thu " << i << endl;
        Data d = setData();
        push(s, d);
        cout << endl;
    }
    
    float tong = 0;
    cout << "Cac phan so trong ngan xep la:" << endl; 
    while (!isEmpty(s)) {
        Data d;
        pop(s, d);
        getData(d);
        cout << " ";
        tong += float(d.tuSo) / d.mauSo;
    }
    cout << endl << endl;
    
    cout << setprecision(2) << fixed 
         << "Tong cua cac phan so la: " << tong << endl;
    
    return 0;
}
