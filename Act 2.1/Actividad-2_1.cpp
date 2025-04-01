#include <iostream>
#include <string>

using namespace std;

long long prhf(string S) {
    int n = S.length();
    int p = 31;
    int m = 1e9 + 9;
    long long valorHash = 0;
    long long potencia = 1;
    for (int i = 0; i < n; i++) {
        int charValue;
        if (S[i] >= 'a' && S[i] <= 'z') {
            charValue = S[i] - 'a' + 1;
        } else if (S[i] >= 'A' && S[i] <= 'Z') {
            charValue = S[i] - 'A' + 27; 
        } else {
            charValue = 0;
        }
        valorHash = (valorHash + charValue * potencia) % m;
        potencia = (potencia * p) % m;
    }
    return valorHash;
}

int main() {
    string input;
    cout << "Ingrese una cadena: ";
    getline(cin, input); 
    
    long long hashValue = prhf(input);
    cout << "El valor hash de la cadena es: " << hashValue << endl;

    return 0;
}