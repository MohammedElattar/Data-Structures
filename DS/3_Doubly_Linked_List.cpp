#include <iostream>

class DoublyLinkedList{
private:
    struct Node{
        int value;
        Node* next;
        [[maybe_unused]] Node* prev;
    };

    int count;
    Node* head;

public:
    DoublyLinkedList(){
        head = nullptr;
        count = 0;
    }

    void insertFirst(int value){
        Node* newNode = new Node();
        newNode->value = value;
        newNode->prev = nullptr;

        if(head == nullptr){
            newNode->next = nullptr;
            head = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }

        count++;
    }

    void insertLast(int value){
        Node* newNode = new Node();
        newNode->value = value;
        newNode->next = nullptr;

        if(head == nullptr){
            newNode->prev = nullptr;
            head = newNode;
        } else {
            Node* tmpNode = head;

            while(tmpNode->next){
                tmpNode = tmpNode->next;
            }

            tmpNode->next = newNode;
            newNode->prev = tmpNode;
        }

        count++;
    }

    void insertAtPosition(int position, int value){
        if(position < 1 || (position >(count +1))){
            std::cout << "Out of range\n";
            return;
        }

        if(position == 1){
            insertFirst(value);
        } else if (position == (count + 1)){
            insertLast(value);
        } else {
            Node* newNode = new Node();
            newNode->value = value;

            Node* tmpNode = head;
            position-=2;

            while(tmpNode->next && position){
                tmpNode = tmpNode->next;
                position--;
            }

            newNode->next = tmpNode->next;
            newNode->prev = tmpNode;
            tmpNode->next = newNode;
            count++;
        }

    }

    void deleteFirst(){
        if(head == nullptr){
            std::cout << "Your linked list is empty\n";
            return;
        }
        else if (head->next == nullptr){
            delete head;
            head = nullptr;
        } else {
            Node* tmpNode = head->next;

            delete head;
            tmpNode->prev = nullptr;
            head = tmpNode;
        }

        count--;

    }

    void deleteLast(){
        if(head == nullptr){
            std::cout << "Your linked list is empty\n";
            return;
        }
        else if (head->next == nullptr){
            delete head;
            head = nullptr;
        } else {
            Node* tmpNode = head;

            // here we are catching the node before the last node
            while(tmpNode->next->next){
                tmpNode = tmpNode->next;
            }

            Node* lastNode = tmpNode->next;

            tmpNode->next = nullptr;

            delete lastNode;
        }

        count--;
    }

    void deleteAtPosition(int position){
        if(position < 1 || position > count){
            std::cout << "Out of range\n";
            return;
        }

        if(position == 1){
            deleteFirst();
        } else if (position == count){
            deleteLast();
        } else {
            Node* tmpNode = head;

            position-= 2;

            while(tmpNode->next && position){
                tmpNode = tmpNode->next;
                position--;
            }

            Node* targetNode = tmpNode->next;

            tmpNode->next = targetNode->next;
            tmpNode->next->prev = tmpNode;

            delete targetNode;

            count--;
        }
    }

    void reverse(){
        DoublyLinkedList reversedLinkedList = *new DoublyLinkedList();

        if(head == nullptr){
            std::cout << "Your linked list is empty\n";
            return;
        }

        Node* tmpNode = head;

        while(tmpNode){
            reversedLinkedList.insertFirst(tmpNode->value);
            tmpNode = tmpNode->next;
        }

        reversedLinkedList.traverse();
    }

    void traverse(){
        Node* tmpNode = head;

        while(tmpNode){
            std::cout << tmpNode->value << " ";
            tmpNode = tmpNode->next;
        }

        std::cout << std::endl;
    }

    int size() const{
        return count;
    }
};
int main(){
    DoublyLinkedList doublyLinkedListInstance = *new DoublyLinkedList();

    doublyLinkedListInstance.insertFirst(10);
    doublyLinkedListInstance.insertFirst(20);
    doublyLinkedListInstance.insertFirst(30);
    doublyLinkedListInstance.deleteFirst();
    doublyLinkedListInstance.insertLast(100);
    doublyLinkedListInstance.insertLast(200);
    doublyLinkedListInstance.insertAtPosition(1, 500);
    doublyLinkedListInstance.deleteLast();
    doublyLinkedListInstance.deleteAtPosition(1);
    doublyLinkedListInstance.reverse();
    doublyLinkedListInstance.traverse();
}