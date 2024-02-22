#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
private:
    Node* head; 

public:

    LinkedList() {
        head = NULL; 
    }

    void insertNode(int value) {
        Node* newNode = new Node; 
        newNode->data = value;
        newNode->next = NULL; 

        if (head == NULL) { 
            head = newNode;
        } else { 
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void editNode(int position, int value) {
        Node* temp = head;
        int currentPosition = 1;
        while (temp != NULL && currentPosition < position) { 
            temp = temp->next;
            currentPosition++;
        }

        if (temp == NULL) { 
            cout << "La posicion especificada esta mas alla del final de la lista." << endl;
        } else { 
            temp->data = value;
            cout << "El valor del nodo en la posicion " << position << " ha sido editado." << endl;
        }
    }

    void deleteNode(int position) {
        if (head == NULL) { 
            cout << "La lista está vacia." << endl;
            return;
        }

        Node* temp = head;
        if (position == 1) { 
            head = head->next;
            delete temp;
            cout << "El nodo en la posicion " << position << " ha sido eliminado." << endl;
            return;
        }

        int currentPosition = 1;
        while (temp != NULL && currentPosition < position - 1) { 
            temp = temp->next;
            currentPosition++;
        }

        if (temp == NULL || temp->next == NULL) { 
            cout << "La posicion especificada esta mas alla del final de la lista." << endl;
        } else { 
            Node* nodeToDelete = temp->next;
            temp->next = nodeToDelete->next;
            delete nodeToDelete;
            cout << "El nodo en la posicion " << position << " ha sido eliminado." << endl;
        }
    }

    void displayList() {
        if (head == NULL) { 
            cout << "La lista esta vacia." << endl;
            return;
        }

        Node* temp = head;
        cout << "Lista de nodos:" << endl;
        while (temp != NULL) { 
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList myList;

    myList.insertNode(10);
    myList.insertNode(20);
    myList.insertNode(15);
    myList.insertNode(9);

    cout << "Lista inicial" << endl;
    myList.displayList();
    
    //solo para aclarar profe, esta es mi manera de ordenar los nodos, no se me ocurre mas :( 

    myList.editNode(1, 20);
    myList.editNode(2, 15);
    myList.editNode(3, 10);
    myList.editNode(4, 9);

    cout << "Lista despues de editar:" << endl;
    myList.displayList();

    cout << "Lista despues de eliminar:" << endl;
    myList.displayList();

    return 0;
}
