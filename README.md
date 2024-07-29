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
### . Définition des Points Fixes

Un nombre en virgule fixe est représenté par un entier, mais interprété comme s'il avait une virgule fixe à une certaine position. Par exemple, avec 8 bits fractionnaires (aussi appelés Q8), cela signifie que la partie fractionnaire a 8 bits.

Si tu veux convertir un entier en nombre à virgule fixe, il suffit de décaler (shift) par le nombre de bits fractionnaires.

## Conversion d'un Nombre Flottant en Virgule Fixe


### 1. Multiplier par une Puissance de 2

Pour convertir un nombre flottant en virgule fixe, il faut multiplier ce nombre flottant par \(2^N\), où \(N\) est le nombre de bits de la partie fractionnaire. Par exemple, si vous avez 8 bits fractionnaires, \(N = 8\), donc vous multipliez par \(2^8 = 256\).

### 2. Arrondir à l'Entier le Plus Proche

Après avoir multiplié le nombre flottant par \(2^N\), il faut arrondir le résultat à l'entier le plus proche pour obtenir le nombre en virgule fixe.

### 3. Stocker en Tant qu'Entier

Le résultat arrondi est ensuite stocké en tant qu'entier. Cet entier représente la valeur en virgule fixe.

### Exemple

Supposons que nous voulons convertir le nombre flottant 3.75 en virgule fixe avec 8 bits fractionnaires :

- **Multiplier par \(2^8\)** :
  \[
  3.75 \times 256 = 960
  \]

- **Arrondir à l'entier le plus proche** :
  \[
  960 \text{ (déjà un entier)}
  \]

- **Stocker en tant qu'entier** :
  \[
  960
  \]

Ainsi, le nombre flottant 3.75 est représenté par l'entier 960 en virgule fixe avec 8 bits fractionnaires.

### Conversion Inverse : Virgule Fixe à Flottant

Pour convertir un nombre en virgule fixe en nombre flottant, il suffit de diviser l'entier par \(2^N\).

### Exemple

Pour convertir l'entier 960 (qui est en format Q8) en nombre flottant :

- **Diviser par \(2^8\)** :
  \[
  \frac{960}{256} = 3.75
  \]

Ainsi, l'entier 960 en virgule fixe avec 8 bits fractionnaires représente le nombre flottant 3.75.

## Conversion d'un Nombre Flottant en Représentation Binaire IEEE 754 (Simple Précision)

### Étapes

1. **Décomposer le Nombre Flottant**

   Le nombre flottant est décomposé en trois parties :
   - **Bit de signe** : Indique si le nombre est positif (0) ou négatif (1).
   - **Exposant** : La puissance de 2 à laquelle la mantisse est multipliée.
   - **Mantisse** : La partie fractionnaire du nombre flottant.

   Exemple : Prenons le nombre flottant `5.0` et convertissons-le en format IEEE 754 simple précision.

2. **Décomposer le Nombre Flottant**

   - **Bit de Signe** : Le nombre `5.0` est positif, donc le bit de signe est `0`.

   - **Partie Entière en Binaire** : La partie entière de `5` en binaire est `101`.

   - **Notation Scientifique** : En notation scientifique, cela devient `1.01 × 2^2`.

3. **Calculer l'Exposant**

   L'exposant est `2`. En IEEE 754, l'exposant est stocké avec un biais de `127` pour la simple précision.

   \[
   \text{Exposant} = 2 + 127 = 129
   \]

   En binaire, `129` s'écrit :

   \[
   10000001
   \]

4. **Convertir la Mantisse**

   La mantisse est la partie fractionnaire de `1.01`, en enlevant le `1` implicite :

   \[
   01000000000000000000000
   \]

5. **Combiner Toutes les Parties**

   - **Bit de Signe** : `0`
   - **Exposant** : `10000001`
   - **Mantisse** : `01000000000000000000000`

   La représentation binaire IEEE 754 de `5.0` est donc :

   \[
   01000000101000000000000000000000
   \]
La conversion inverse est très simple.

