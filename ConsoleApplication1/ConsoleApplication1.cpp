#include <iostream>

using namespace std;
// перечислимый тип
enum Car { zil = 1, pobeda, volga, zaz, moscvich = 0 };
Car operator+(const Car& m, const int& b)
{
    Car t = Car(b + m);
    return (t = Car(t%5));
}
// вторая функция для коммутативности сложения Car operator+(const int &b, const Car &m)
Car operator+(const int& b, const Car& m)
{
    return (m + b);
}
Car operator++(Car& m) // префиксная форма
{
    return (m = Car(m + 1));
}
Car operator++(Car& m, int) // постфиксная форма
{
    Car t = m; m == Car(m + 1);
    return t;
}
void print(const Car& d) // вывод на экран названий машин
{
    string Cars[5] =
    {
    "Зил-111", "Победа", "ГАЗ-3102", "ЗАЗ-968М", "Москвич-412"
    };
    cout << Cars[d] << endl;
}
int main()
{
    setlocale(LC_ALL, "Rus");
    Car m = zaz; print(m + 1);
    print(2 + m); print(operator+(m, 1));
    print(operator+(2, m)); m++;
    print(m);
    print(++m);
    print(operator++(m)); print(operator++(m, 0)); print(m);
    system("pause");
}

