#include <windows.h>
#include <codecvt>
#include <iostream>

#include <random>
#include <fstream> 
#include <sstream> 
#include <string> 
#include <vector>
using namespace std;

class Kopek {

private:
    string adi;
public:
    bool setkontrol(string name) {

        for (char x : name) {
            if (x >= '0' && x <= '9') {  
                cout << "Geçersiz isim Harf olmayan veya Türkçe karakter içeren karakter kullanılamaz." << endl;
                return false;  
            }
        }
       
        return true; 
    }
    bool setturkce(string name) {
       
        for (char x : name) {
           
            if (!isalpha(x))
            {
                cout << "Geçersiz isim Harf olmayan veya Türkçe karakter içeren karakter kullanılamaz." << endl;
                return false; 
            }
        }
        locale::global(locale(""));
        adi = name;
        cout << "Köpeğin ismi başarıyla ayarlandı: " << adi << endl;
        return true;  
    }

};

int main() {
    locale::global(locale(""));
    string adi;
    Kopek x;

    cout << "Girilecek isimde harf olmayan bir karakter olamaz!" << endl;
  

    do {
        do 
        {
            
            cout << "Köpeğin adını girin: ";
            cin >> adi;
        } 
        while (!x.setkontrol(adi));
       
    }
    while (!x.setturkce(adi));
    return 0;
}
