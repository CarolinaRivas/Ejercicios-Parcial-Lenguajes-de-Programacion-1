#include <iostream>
#include <cmath>
#include <cfenv>

using namespace std;

struct Punto
{
    double x, y, z;
};
// Sobrecarga del operador + para sumar un punto con un numero
Punto operator+(const Punto &p, double num)
{
    Punto res;
    res.x = p.x + num;
    res.y = p.y + num;
    res.z = p.z + num;
    return res;
}
// Sobrecarga del operador + para sumar dos puntos
Punto operator+(const Punto &p, const Punto &q)
{
    Punto res;
    res.x = p.x + q.x;
    res.y = p.y + q.y;
    res.z = p.z + q.z;
    return res;
}
// Sobrecarga del operador - para restar dos puntos
Punto operator-(const Punto &p, const Punto &q)
{
    Punto res;
    res.x = p.x - q.x;
    res.y = p.y - q.y;
    res.z = p.z - q.z;
    return res;
}
// Sobrecarga del operador * para cuando se multiplica un Punto por un numero
Punto operator*(const Punto &p, double num)
{
    Punto res;
    res.x = p.x * num;
    res.y = p.y * num;
    res.z = p.z * num;
    return res;
}

// Sobrecarga del operador * Producto Cruz
Punto operator*(const Punto &p, const Punto &q)
{
    Punto res;
    res.x = (p.y * q.z) - (p.z * q.y);
    res.y = (p.x * q.z) - (p.z * q.x);
    res.z = (p.x * q.y) - (p.y * q.x);
    return res;
}
// Sobrecarga del operador % Producto Punto
float operator%(const Punto &p, const Punto &q)
{
    return (p.x * q.x) + (p.y * q.y) + (p.z * q.z);
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
    cout << "El resultado de sumar el punto "
         << "(" << a.x << "," << a.y << "," << a.z << ")"
         << "\n"
         << "con el punto "
         << "(" << b.x << "," << b.y << "," << b.z << ") "
         << "es "
         << "\n";

    cout << "(" << res.x << "," << res.y << "," << res.z << ")"
         << "\n";

    cout << "--------------RESTA----------- \n";
    res = a - b;

    cout << "El resultado de restar el punto "
         << "(" << a.x << "," << a.y << "," << a.z << ")"
         << "\n"
         << "con el punto "
         << "(" << b.x << "," << b.y << "," << b.z << ") "
         << "es "
         << "\n";
    cout << "(" << res.x << "," << res.y << "," << res.z << ")"
         << "\n";

    cout << "--------------MULTIPLICACION PRODUCTO CRUZ----------- \n";
    res = a * b;

    cout << "El resultado de hacer el producto cruz  del punto "
         << "(" << a.x << "," << a.y << "," << a.z << ")"
         << "\n"
         << "con el punto "
         << "(" << b.x << "," << b.y << "," << b.z << ") "
         << "es "
         << "\n";
    cout << "(" << res.x << "," << res.y << "," << res.z << ")"
         << "\n";

    cout << "--------------PRODUCTO PUNTO----------- \n";
    cout << "El resultado de hacer el producto punto  del punto "
         << "(" << a.x << "," << a.y << "," << a.z << ")"
         << "\n"
         << "con el punto "
         << "(" << b.x << "," << b.y << "," << b.z << ") "
         << "es "
         << "\n";
    cout << a % b << "\n";

    cout << "-------------- a*b +c---------- \n";
    cout << "El resultado de "
         << "(" << a.x << "," << a.y << "," << a.z << ")"
         << "* "
         << "(" << b.x << "," << b.y << "," << b.z << ") "
         << "+ "
         << "(" << c.x << "," << c.y << "," << c.z << ") "
         << "es "
         << "\n";
    res = a * b + c;

    cout << "(" << res.x << "," << res.y << "," << res.z << ")"
         << "\n";

    cout << "--------------(b+b) * (c-a)---------- \n";
    res = (b + b) * (c - a);

    cout << "El resultado de "
         << "("
         << "(" << b.x << "," << b.y << "," << b.z << ")"
         << "+ "
         << "(" << b.x << "," << b.y << "," << b.z << ") "
         << ")"
         << "* "
         << "("
         << "(" << c.x << "," << c.y << "," << c.z << ") "
         << "- "
         << "(" << a.x << "," << a.y << "," << a.z << ")"
         << ") "
         << "es"
         << "\n";

    cout << "(" << res.x << "," << res.y << "," << res.z << ")"
         << "\n";

    cout << "-------------a % (c * b)---------- \n";
    a % (c * b);

    cout << "El resultado de "
         << "(" << a.x << "," << a.y << "," << a.z << ") "
         << "% "
         << "("
         << "(" << b.x << "," << b.y << "," << b.z << ") "
         << "* "
         << "("
         << "(" << c.x << "," << c.y << "," << c.z << ") "
         << ")"
         << "es"
         << "\n";
    cout << a % (c * b) << "\n";

    cout << "-------------- b + 3 --------- \n";
    res = b + 3;
    cout << "El resultado de "
         << "(" << b.x << "," << b.y << "," << b.z << ")"
         << "+ "
         << "3 "
         << "es "
         << "\n";
    cout << "(" << res.x << "," << res.y << "," << res.z << ")"
         << "\n";

    cout << "--------------COSAS LOCAS (b + b) *(c '%' a )---------- \n";
    res = (b + b) * (c % a);
    cout << "El resultado de "
         << "("
         << "(" << b.x << "," << b.y << "," << b.z << ")"
         << "+ "
         << "(" << b.x << "," << b.y << "," << b.z << ") "
         << ")"
         << "* "
         << "("
         << "(" << c.x << "," << c.y << "," << c.z << ") "
         << "% "
         << "(" << a.x << "," << a.y << "," << a.z << ")"
         << ") "
         << "es"
         << "\n";
    cout << "(" << res.x << "," << res.y << "," << res.z << ")"
         << "\n";

    cout << "-------------- a * 3.0 + 7.0 --------- \n";
    res = a * 3.0 + 7.0;
    cout << "El resultado de "
         << "(" << a.x << "," << a.y << "," << a.z << ")"
         << "* "
         << "3.0 "
         << "+ "
         << "7.0 "
         << "es "
         << "\n";
    cout << "(" << res.x << "," << res.y << "," << res.z << ")"
         << "\n";
}
