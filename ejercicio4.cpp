#include <iostream>
#include <cmath>
#include <cfenv>

using namespace std;

struct Punto
{
    double x, y, z;
};

Punto operator+(const Punto &p, double num)
{
    Punto res;
    res.x = p.x + num;
    res.y = p.y + num;
    res.z = p.z + num;
    return res;
}
// Sobrecarga del operador + para la clase Punto
Punto operator+(const Punto &p, const Punto &q)
{
    Punto res;
    res.x = p.x + q.x;
    res.y = p.y + q.y;
    res.z = p.z + q.z;
    return res;
}
// Sobrecarga del operador - para la clase Punto
Punto operator-(const Punto &p, const Punto &q)
{
    Punto res;
    res.x = p.x - q.x;
    res.y = p.y - q.y;
    res.z = p.z - q.z;
    return res;
}
// Sobrecarga del operador * para la clase Punto cuando se multiplica un punto por un numero
Punto operator*(const Punto &p, double num)
{
    Punto res;
    res.x = p.x * num;
    res.y = p.y * num;
    res.z = p.z * num;
    return res;
}

// Sobrecarga del operador * para la clase Punto
Punto operator*(const Punto &p, const Punto &q)
{
    Punto res;
    res.x = p.x * q.x;
    res.y = p.y * q.y;
    res.z = p.z * q.z;
    return res;
}
// Sobrecarga del operador % para la clase Punto
Punto operator%(const Punto &p, const Punto &q)
{
    Punto res;
    res.x = std ::fmod(p.x, q.x);
    res.y = std ::fmod(p.y, q.y);
    res.z = std ::fmod(p.z, q.z);
    return res;
}

int main()
{
    Punto a, b, c, res;
    a.x = 1;
    a.y = 2;
    a.z = 3;

    b.x = 2;
    b.y = 3;
    b.z = 4;

    c.x = 1;
    c.y = 1;
    c.z = 1;

    cout << "--------------SUMA----------- \n";
    res = a + b;
    cout << "res.x " << res.x << "\n";
    cout << "res.y " << res.y << "\n";
    cout << "res.z " << res.z << "\n";

    cout << "--------------RESTA----------- \n";
    res = a - b;
    cout << "res.x " << res.x << "\n";
    cout << "res.y " << res.y << "\n";
    cout << "res.z " << res.z << "\n";

    cout << "--------------MULTIPLICACION----------- \n";
    res = a * b;
    cout << "res.x " << res.x << "\n";
    cout << "res.y " << res.y << "\n";
    cout << "res.z " << res.z << "\n";

    cout << "--------------MOD----------- \n";
    res = a % b;
    cout << "res.x " << res.x << "\n";
    cout << "res.y " << res.y << "\n";
    cout << "res.z " << res.z << "\n";

    cout << "--------------COSAS LOCAS a*b +c---------- \n";
    res = a * b + c;
    cout << "res.x " << res.x << "\n";
    cout << "res.y " << res.y << "\n";
    cout << "res.z " << res.z << "\n";

    cout << "--------------COSAS LOCAS (b+b) * (c-a)---------- \n";
    res = (b + b) * (c - a);
    cout << "res.x " << res.x << "\n";
    cout << "res.y " << res.y << "\n";
    cout << "res.z " << res.z << "\n";

    cout << "--------------COSAS LOCAS a % (c * b)---------- \n";
    res = a % (c * b);
    cout << "res.x " << res.x << "\n";
    cout << "res.y " << res.y << "\n";
    cout << "res.z " << res.z << "\n";

    cout << "--------------COSAS LOCAS b + 3 --------- \n";
    res = b + 3;
    cout << "res.x " << res.x << "\n";
    cout << "res.y " << res.y << "\n";
    cout << "res.z " << res.z << "\n";

    cout << "--------------COSAS LOCAS (b + b) *(c mod a )---------- \n";
    res = (b + b) * (c % a);
    cout << "res.x " << res.x << "\n";
    cout << "res.y " << res.y << "\n";
    cout << "res.z " << res.z << "\n";

    cout << "--------------COSAS LOCAS a * 3.0 + 7.0 --------- \n";
    res = a * 3.0 + 7.0;
    cout << "res.x " << res.x << "\n";
    cout << "res.y " << res.y << "\n";
    cout << "res.z " << res.z << "\n";
}
