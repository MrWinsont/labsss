

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cctype>

using namespace std;

int max(vector <string> &a) {
    int maxch = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i].length() > maxch){
            maxch = a[i].length();
        }
    }
    return maxch;
}
bool compare(char a) {
    char chars[11] = ",.?:;'-() ";
    for (int i = 0; i < 10; i++) {
        if (a == chars[i]) {
            return true;
        }
    }
    return false;

}
string noChars(string b) {
    string a;
    for (int i = 0; i < b.length(); i++) {
        if (!compare(b[i])) {
            a += b[i];
        }
    }
    return a;
}

int main()
{   
    cout << "hi "<<endl;
    vector <string> arr;
    vector <string> aom;   // ArrOfMax
    string buff;
    vector <string> chars;
    
    ifstream f1("input.txt");
    string s;
    while (!f1.eof()) {
        s = "";
        f1 >> s;
        arr.push_back(noChars(s));
    }
    char str[100];
    int k = 0;
    ifstream f2("input.txt");
    while (!f2.eof()) {
        f2.getline(str,100);
        for (int i = 0; i < strlen(str); i++) {
            if (compare(str[i])) {
                buff.push_back(str[i]);
                k++;  
            }
            if (!compare(str[i]) && k != 0) {
                chars.push_back(buff);
                k = 0;
                buff = "";
            }
        }
        chars.push_back("\n");
    }

    int MAX = max(arr);
    for (int i = 0; i < arr.size(); i++) {
        if (MAX == arr[i].length()) {
            aom.push_back(arr[i]);
        }
    }
    string stroka1;
    string stroka2;
    string strtmp;
    int poisk;
    int counter;
    for (int i = 0; i < arr.size(); i++) {
        stroka1 = arr[i];
        bool flag = false;
        for (int j = 0; j < aom.size(); j++) {
            string stroka2 = aom[j];
            strtmp = "";
            for (int k = 0; k < stroka1.length(); k++) {
                counter = 0;
                poisk = 0;
                for (int l = 0; l < stroka2.length(); l++) {
                    if ((stroka1[k] != stroka2[l]) && (stroka1.length() != MAX)) {
                        counter++;
                    }
                }
                if (counter == MAX) {
                    for (int i = 0; i < strtmp.length(); i++) {
                        if (stroka1[k] == strtmp[i]) {
                            poisk++;
                        }
                    }
                    if (poisk == 0) {
                        strtmp += stroka1[k];
                    }
                }
            }
        }
        if (strtmp != "") {
            flag = true;
        }
        if (flag) {
            for (int h = 0; h < stroka1.length(); h++) {
                stroka1[h] = toupper(stroka1[h]);

            }
            arr[i] = stroka1 + "(" + strtmp + ")";
        }
        
    }
    for (int i = 0; i < aom.size(); i++) {
        cout << aom[i] << endl;
    }
    ofstream file("output.txt");
    for (int i = 0; i < arr.size(); i++) {
        file << arr[i] << chars[i];
    }
    file.close();
}
