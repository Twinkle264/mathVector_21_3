#include <iostream>

using namespace std;

struct Vector {
    double x = 0;
    double y = 0;
};

void print_vector(const Vector& v){
    cout << endl << "Result: (" << v.x << ", " << v.y << ")";
}

void enter_vector(Vector& v){
    cout << "Enter vector coordinates (x y): ";
    cin >> v.x >> v.y;
}

Vector add(const Vector& v1, const Vector& v2) {
    Vector result;
    result.x = v1.x + v2.x;
    result.y = v1.y + v2.y;
    return result;
}

Vector subtract(const Vector& v1, const Vector& v2) {
    Vector result;
    result.x = v1.x - v2.x;
    result.y = v1.y - v2.y;
    return result;
}

Vector scale(const Vector& v, double scalar) {
    Vector result;
    result.x = v.x * scalar;
    result.y = v.y * scalar;
    return result;
}

double length(const Vector& v) {
    return sqrt(v.x * v.x + v.y * v.y);
}

Vector normalize(const Vector& v) {
    double len = length(v);
    Vector result;
    if (len != 0.0) {
        result.x = v.x / len;
        result.y = v.y / len;
    }
    return result;
}

int main() {
    Vector v1, v2, result;
    double scalar;

    string command;
    cout << "Enter the command (add, subtract, scale, length, normalize): ";
    cin >> command;

    if (command == "add") {
        cout << "\tVector 1" << endl;
        enter_vector(v1);

        cout << "\tVector 2" << endl;
        enter_vector(v2);

        result = add(v1, v2);
        print_vector(result);
    } else if (command == "subtract") {
        cout << "\tVector 1" << endl;
        enter_vector(v1);

        cout << "\tVector 2" << endl;
        enter_vector(v2);

        result = subtract(v1, v2);
        print_vector(result);
    } else if (command == "scale") {
        cout << "\tVector 1" << endl;
        enter_vector(v1);

        cout << "Enter the scalar: ";
        cin >> scalar;

        result = scale(v1, scalar);
        print_vector(result);
    } else if (command == "length") {
        cout << "\tVector 1" << endl;
        enter_vector(v1);

        double len = length(v1);
        cout << "The length: " << len;
    } else if (command == "normalize"){
        cout << "\tVector 1" << endl;
        enter_vector(v1);

        result = normalize(v1);
        print_vector(result);
    }
    return 0;
}
