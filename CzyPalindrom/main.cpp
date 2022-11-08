#include <iostream>
#include <string>
using namespace std;

int main() {
    string a;
    int i,j;
    bool ok=true;

    cin >> a;

    i=0;
    j=a.length()-1;

    while(i < j) {
        if(a[i] != a[j]) {
            cout << "To nie jest palindrom!" << endl;
            ok = false;
            break;
        }

        i++;
        j--;
    }

    if(ok)
        cout << "To jest palindrom!" << endl;

}
