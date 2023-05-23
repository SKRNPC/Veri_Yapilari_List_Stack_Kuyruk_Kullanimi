#include <iostream>
#include <cstdlib>
#include <ctime>
#include <list>
#include <queue>
#include <stack>

using namespace std;

// Kişi veri yapısı
struct Kisi {
    int numara;
    int islemSuresi;
};

// Yığın yapısı
class Yigin {
private:
    stack<Kisi> kisiler;
public:
    void ekle(Kisi kisi) {
        kisiler.push(kisi);
    }
    void cikar() {
        if (!kisiler.empty()) {
            kisiler.pop();
        }
    }
    Kisi ustteki() {
        return kisiler.top();
    }
    bool bosMu() {
        return kisiler.empty();
    }
};

// Kuyruk yapısı
class Kuyruk {
private:
    queue<Kisi> kisiler;
public:
    void ekle(Kisi kisi) {
        kisiler.push(kisi);
    }
    void cikar() {
        if (!kisiler.empty()) {
            kisiler.pop();
        }
    }
    Kisi ustteki() {
        return kisiler.front();
    }
    bool bosMu() {
        return kisiler.empty();
    }
};

int main() {
    // Random sayı üretimi için srand fonksiyonu kullanılıyor
    srand(time(0));

    // Yığın yapısı için stack kullanımı
    Yigin kuyrukYigin;

    int N;
    cout << "Kac kisi icin kuyruk olusturulsun? ";
    cin >> N;

    // Kuyruk oluşturma işlemi
    for (int i = 1; i <= N; i++) {
        Kisi kisi;
        kisi.numara = i;
        kisi.islemSuresi = rand() % 271 + 30; // Random işlem süresi belirleme

        kuyrukYigin.ekle(kisi); // Yığın yapısı ile kuyruk oluşturma

    }

    // Yığın yapısı ile kuyruk işlemleri
    cout << "Yigin yapisi ile kuyruk islemleri:" << endl;

    int toplamSure = 0; // Toplam işlem süresi
    while (!kuyrukYigin.bosMu()) {
        Kisi kisi = kuyrukYigin.ustteki();
        kuyrukYigin.cikar();
        toplamSure += kisi.islemSuresi; // Toplam işlem süresine ekleme
        cout << "Kisi numarasi: " << kisi.numara << ", islem suresi: " << kisi.islemSuresi;
        cout << ", kuyrukta kalma suresi: " << toplamSure << endl;
    }

    // Ortalama işlem süresini hesaplama
    double ortalamaSure = (double)toplamSure / N;
    cout << "Toplam islem suresi: " << toplamSure << endl;
    cout << "Ortalama islem suresi: " << ortalamaSure << endl;

    return 0;
}


