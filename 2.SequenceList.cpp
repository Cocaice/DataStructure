/* 
    ��1���������˼�룺1.��һ������c�洢�����������ĵ�һ����num���ñ���time�洢�����ֵĸ���
                       2.����������num��Ԫ��ʱ��time��һ�������һ����time��Ϊ0ʱ����cΪ��ʱ������Ԫ�أ�����timeΪ1�� 
                       3.�ظ��ڶ���ֱ���������顣
                       4.������c�������鿴����ֵĴ������������n/2��������Ԫ�أ������ǡ� 
*/

#include<iostream>
using namespace std;
//(2)C++��***********************
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

//(3)ʱ�临�ӶȺͿؼ����Ӷȷֱ�Ϊ O(n)��O(1) 
