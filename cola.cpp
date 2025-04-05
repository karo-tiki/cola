#include <iostream>
using namespace std;

template <typename T>
class Cola {
private:
    T arr[10];
    T* head;
    T* tail;

public:

    Cola() {
        head = NULL;
        tail = NULL;
    }


    void push(T value) {
        if (head == NULL && tail == NULL) {

            arr[0] = value;
            head = &arr[0];
            tail = &arr[0];
        }
        else if ((tail + 1 == head) || (tail == &arr[9] && head == &arr[0])) {

            cout << "La cola esta llena." << endl;
        }
        else {

            if (tail == &arr[9]) {
                tail = &arr[0];
            }
            else {
                tail++;
            }
            *tail = value;
        }
    }

    bool pop(T& v) {
        if (head == nullptr && tail == nullptr) {
            cout << "La cola esta vacia." << endl;
            return false;
        }
        else {
            v = *head;
            if (head == tail) {

                head = nullptr;
                tail = nullptr;
            }
            else {

                if (head == &arr[9]) {
                    head = &arr[0];
                }
                else {
                    head++;
                }
            }
            return true;
        }
    }
    void mostrar() {
        if (head == nullptr && tail == NULL) {
            cout << "La cola está vacia." << endl;
            return;
        }

        cout << "Elementos en la cola: ";
        T* ptr = head;
        while (ptr != tail) {
            cout << *ptr << " ";
            if (ptr == &arr[9]) {
                ptr = &arr[0];
            }
            else {
                ptr++;
            }
        }
        cout << *tail << endl;
    }
};

int main() {
    Cola<int> miCola;
    miCola.push(1);
    miCola.push(2);
    miCola.push(3);
    miCola.push(4);
    miCola.push(5);
    miCola.push(6);
    miCola.push(7);
    miCola.push(8);
    miCola.push(9);
    miCola.push(10);
    miCola.push(11);
    miCola.mostrar();
    int valorEliminado;
    if (miCola.pop(valorEliminado)) {
        cout << "Elemento eliminado: " << valorEliminado << endl;
    }
    miCola.mostrar();
    miCola.push(80);
    return 0;
}