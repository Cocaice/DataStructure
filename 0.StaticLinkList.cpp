#include<iostream>
using namespace std;
#define Maxsize 50
struct SLinklist{
    int data;
    int cur;
};

void InitSpace(SLinklist *space) {
    for (int i = 0; i < Maxsize-1; i++) {
        space[i].cur = i+1;
    }
    space[Maxsize-1].cur = 0;
} 

int MallocSpace(SLinklist *space) {
    if (space[0].cur != 0) {
        int i = space[0].cur;
        space[0].cur = space[i].cur;
        return i;
    } else {
        return -1;
    }
}

void FreeSpace(SLinklist *space, int i) {
    space[i].cur = space[0].cur;
    space[0].cur = i;
}

//题目：集合运算（A-B）∪（B-A）
int main() {
    SLinklist space[Maxsize];
    InitSpace(space);
    int sum_a, sum_b;
    cin >> sum_a >> sum_b;
    int head, tail;
    head =  MallocSpace(space);
    tail =  head;
    //cin >> space[tail].data;
    for (int i = 0; i < sum_a; i++) {
        space[tail].cur = MallocSpace(space);
        tail = space[tail].cur;
        cin >> space[tail].data;
    }
    space[tail].cur = -1;
    

    int m = 0;
    for (int i = 0; i < sum_b; i++) {
        cin >> m;
        int p = head;
        int j = space[p].cur;
        while(j != -1 && space[j].data != m) {
            p = j;
            j = space[j].cur;  
        }
        if (j == -1) {
            space[tail].cur = MallocSpace(space);
            tail = space[tail].cur;
            space[tail].data = m;
            space[tail].cur = -1;
        } else {
            space[p].cur = space[j].cur;
            FreeSpace(space,j);
            if (tail == j) tail = p;
        }
    }
    int j = space[head].cur;
    cout << "result: ";
    while(j != -1) {
        cout << space[j].data << " ";
        j = space[j].cur;
    }
}
