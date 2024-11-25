#include <iostream>
using namespace std;
void TOH(int n, char A, char B, char C,int& p) {
    if (n > 0) {
        TOH(n - 1, A, C, B,p);
        cout << "Move disk " << n << " from " <<A<< " to " <<C<< "\n";
        p++;
        TOH(n - 1, B,A,C,p);
        return;
    }
}

int main() {
    int n;
    cin>>n;
    int p = 0;
    TOH(n, 'A', 'B', 'C',p);
    cout<<"Total number of moves: "<<p;
    return 0;
}