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
        head = nullptr;
        tail = nullptr;
    }

    void push(T value) {
        if (head == nullptr && tail == nullptr) {
            arr[0] = value;
            head = &arr[0];
            tail = &arr[0];
        } else if ((tail + 1 == head) || (tail == &arr[9] && head == &arr[0])) {
            cout << "La cola está llena." << endl;
        } else {
            if (tail == &arr[9]) {
                tail = &arr[0];
            } else {
                tail++;
            }
            *tail = value;
        }
    }

    bool pop(T& v) {
        if (head == nullptr && tail == nullptr) {
            cout << "La cola está vacía." << endl;
            return false;
        } else {
            v = *head;

            if (head == tail) {
                head = nullptr;
                tail = nullptr;
            } else {
                if (head == &arr[9]) {
                    head = &arr[0];
                } else {
                    head++;
                }
            }
            return true;
        }
    }

    void mostrar() {
        if (head == nullptr && tail == nullptr) {
            cout << "La cola está vacía." << endl;
            return;
        }

        cout << "Elementos en la cola: ";
        T* ptr = head;
        while (ptr != tail) {
            cout << *ptr << " ";
            if (ptr == &arr[9]) {
                ptr = &arr[0];
            } else {
                ptr++;
            }
        }
        cout << *tail << endl;
    }
};

int main() {
    Cola<int> miCola;

    miCola.push(5);
    miCola.push(3);
    miCola.push(7);

    miCola.mostrar();

    int valorEliminado;
    if (miCola.pop(valorEliminado)) {
        cout << "Elemento eliminado: " << valorEliminado << endl;
    }

    miCola.mostrar();

    return 0;
}
