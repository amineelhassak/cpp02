# cpp02
cpp02

## Forme Canonique Orthodoxe d'une Classe

La forme canonique orthodoxe d'une classe est une pratique recommandée pour assurer que votre classe gère correctement les opérations de construction, de copie, d'assignation et de destruction.
```cpp
#include <iostream>
#include <string>

class MyClass {
private:
    int* data;           // Exemple de ressource dynamique
    std::string name;

public:
    // Constructeur par défaut
    MyClass() : data(new int(0)), name("default") {
        std::cout << "Constructeur par défaut appelé." << std::endl;
    }

    // Constructeur paramétré
    MyClass(int value, const std::string& str) : data(new int(value)), name(str) {
        std::cout << "Constructeur paramétré appelé." << std::endl;
    }

    // Constructeur de copie
    MyClass(const MyClass& other) : data(new int(*other.data)), name(other.name) {
        std::cout << "Constructeur de copie appelé." << std::endl;
    }

    // Opérateur d'assignation
    MyClass& operator=(const MyClass& other) {
        if (this != &other) { // Auto-assignement check
            delete data; // Libération de la mémoire précédente
            data = new int(*other.data); // Allocation et copie de la nouvelle ressource
            name = other.name;
        }
        std::cout << "Opérateur d'assignation appelé." << std::endl;
        return *this;
    }

    // Destructeur
    ~MyClass() {
        delete data; // Libération de la mémoire allouée
        std::cout << "Destructeur appelé." << std::endl;
    }

    // Méthode pour afficher les données
    void display() const {
        std::cout << "Name: " << name << ", Data: " << *data << std::endl;
    }
};

int main() {
    MyClass obj1; // Constructeur par défaut
    MyClass obj2(42, "example"); // Constructeur paramétré
    MyClass obj3 = obj2; // Constructeur de copie
    obj1 = obj2; // Opérateur d'assignation

    obj1.display();
    obj2.display();
    obj3.display();

    return 0;
}
```
## Explications des Méthodes de la Forme Canonique Orthodoxe

- **Constructeur par défaut** : Initialise les membres de la classe avec des valeurs par défaut. Dans cet exemple, il alloue une ressource dynamique (`data`).

- **Constructeur paramétré** : Initialise les membres avec des valeurs spécifiques passées en argument.

- **Constructeur de copie** : Crée une copie profonde des membres de la classe, notamment des ressources dynamiques, pour éviter les problèmes de double libération ou de fuite de mémoire.

- **Opérateur d'assignation** : Gère l'assignation entre deux objets. Il libère la ressource existante avant d'allouer une nouvelle ressource et de copier les données.

- **Destructeur** : Libère les ressources allouées lorsque l'objet est détruit.

## Surcharge d'Opérateurs

La surcharge d'opérateurs (ou *operator overloading*) en C++ permet de définir ou de modifier le comportement des opérateurs (comme `+`, `-`, `*`, etc.) pour les types de données définis par l'utilisateur (par exemple, les classes). Cela rend les objets de ces types plus intuitifs à utiliser avec des opérateurs arithmétiques, relationnels, ou autres.

```cpp
#include <iostream>

class Vector2D {
private:
    double x, y;

public:
    // Constructeur
    Vector2D(double x = 0, double y = 0) : x(x), y(y) {}

    // Surcharge de l'opérateur +
    Vector2D operator+(const Vector2D& other) const {
        return Vector2D(x + other.x, y + other.y);
    }

    // Surcharge de l'opérateur -
    Vector2D operator-(const Vector2D& other) const {
        return Vector2D(x - other.x, y - other.y);
    }

    // Surcharge de l'opérateur *
    Vector2D operator*(double scalar) const {
        return Vector2D(x * scalar, y * scalar);
    }

    // Surcharge de l'opérateur <<
    friend std::ostream& operator<<(std::ostream& os, const Vector2D& v) {
        os << "(" << v.x << ", " << v.y << ")";
        return os;
    }

    // Surcharge de l'opérateur ==
    bool operator==(const Vector2D& other) const {
        return x == other.x && y == other.y;
    }
};

int main() {
    Vector2D v1(1.0, 2.0);
    Vector2D v2(3.0, 4.0);

    Vector2D v3 = v1 + v2; // Utilisation de l'opérateur +
    Vector2D v4 = v1 - v2; // Utilisation de l'opérateur -
    Vector2D v5 = v1 * 2;  // Utilisation de l'opérateur *

    std::cout << "v1 + v2 = " << v3 << std::endl;
    std::cout << "v1 - v2 = " << v4 << std::endl;
    std::cout << "v1 * 2 = " << v5 << std::endl;

    if (v1 == v2) {
        std::cout << "v1 est égal à v2" << std::endl;
    } else {
        std::cout << "v1 n'est pas égal à v2" << std::endl;
    }

    return 0;
}
```
Les autres opérations disponibles dans ce projet incluent L'incrémentation et la décrémentation `++`, `--`, ainsi que les comparaisons `<`, `<=`, `>=`, et `>`.
