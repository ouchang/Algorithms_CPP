#include <iostream>
#include <string>

using namespace std;

int WORD_A[30];
int WORD_B[30];

int main() {
    string a,b;
    bool ok=true;
    cin >> a >> b;

    for(int i=0; i<a.length(); i++) {
        WORD_A[a[i]-'a']++;
    }

    for(int i=0; i<b.length(); i++) {
        WORD_B[b[i]-'a']++;
    }

    for(int i=0; i<28; i++) {
        if(WORD_A[i] != WORD_B[i]) {
            cout << "To nie są anagramy!" << endl;
            ok = false;
            break;
        }
    }

    if(ok)
        cout << "To są anagramy!" << endl;
}
