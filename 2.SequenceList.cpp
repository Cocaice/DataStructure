/* 
    （1）基本设计思想：1.用一个变量c存储数组中碰到的第一个数num，用变量time存储他出现的个数
                       2.当碰到不是num的元素时，time减一，否则加一，当time变为0时，令c为此时碰到的元素，计数time为1。 
                       3.重复第二步直至遍历数组。
                       4.最后根据c遍历数组看其出现的次数，如果大于n/2，则是主元素，否则不是。 
*/

#include<iostream>
using namespace std;
//(2)C++表达：***********************
int Majority(int A[], int n) {
    int c = -1, time = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] == c) {
            time++;
            
        } else {
            if (time > 0) time--;
            else {
                c = A[i];
                time = 1;
            }
        }
    }
    time = 0;
    for (int i = 0; i < n; i++) {
        if (A[i] == c) time++;
    }
    if (time > n/2) return c;
    else return -1;
} 
//***********************************

int main() {
    int A[6] = {1, 2, 3, 4, 4, 4};
    int B[7] = {1, 4, 2, 4, 3, 4, 4};
    int C[8] = {4, 4, 4, 4, 4, 3, 2, 1};
    cout << Majority(A, 6) << endl;
    cout << Majority(B, 7) << endl;
    cout << Majority(C, 8) << endl;
    return 0;
}

//(3)时间复杂度和控件复杂度分别为 O(n)和O(1) 
