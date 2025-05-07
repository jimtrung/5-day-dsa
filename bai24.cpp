#include <iostream>
#include <iomanip>
using namespace std;

struct SoPhuc {
    int thuc, ao;
};

typedef SoPhuc Data;

Data setData() {
    Data d;
    cout << "Nhap phan thuc: "; cin >> d.thuc;
    cout << "Nhap phan ao: "; cin >> d.ao; 
    return d;
}

void getData(Data d) {
    cout << d.thuc << " + " << d.ao << "i";
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
        cout << "Nhap so luong so phuc: ";
        cin >> N;
    } while (N <= 0);
    
    for (int i = 1; i <= N; i++) {
        cout << "Nhap thong tin so phuc thu " << i << endl;
        Data d = setData();
        push(s, d);
        cout << endl;
    }
    
    int tongThuc = 0, tongAo = 0;
    cout << "Cac so phuc trong ngan xep la:" << endl;
    while (!isEmpty(s)) {
        Data d;
        pop(s, d);
        getData(d);
        cout << "\n";
        tongThuc += d.thuc;
        tongAo += d.ao;
    }
    cout << endl;
    
    cout << setprecision(2) << fixed 
         << "Tong cua cac so phuc la: " 
         << tongThuc << " + " << tongAo << "i" << endl; 
    
    return 0;
}

