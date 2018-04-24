 /*(1)设计思想：1.从数组第一位开始，用一个中间变量A存储该位置数据，然后赋予数组第p位的值赋到第一位，根据X后=(n+X前-p)%n，用C存储第一位移动后的位置；
                2.找到C位置，用A数据替换该位置的值，然后将该位置进行移位后的位置存储到C中
                3.一直重复第二步n-1次。 
 */
 //(2)
 #include<iostream>
 using namespace std;
 int main() {
     int n, p;
     cin >> n >> p;
     int *a = new int[n];
     for (int i = 0; i < n; i++) {
         a[i] = i;
     }
     //以下为算法***************
     int A = a[0];
     a[0] = a[0+p];
     int B, C = (n+0-p)%n;
     for (int i = 0; i < n-1; i++) {
         B = a[C];
         a[C] = A;
         A = B;                     //替换C位置的数据 
         C = (n+C-p)%n;             //令C为C位置移位后的位置。 
     }
     //************************
     for (int i = 0; i < n; i++) {
         cout << a[i] << " ";
     }
 }
 
 
 //(3)时间复杂度和空间复杂度分别为 O(n),O(3)
