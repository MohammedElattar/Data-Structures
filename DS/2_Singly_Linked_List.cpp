/*
 * Linked List
 *
 * linked list is a linear data structure
 * it doesn't store data as a block like what array data structure does instead, each node stores
 * the second node address in it
 *
 * linked list is good at allocating memory and work with it efficiently better that arrays
 *
 * accessing element in linked list takes O(N) linear time
 * inserting element takes O(N)
 * deleting element takes O(N)
 *
 * that is the worst case if we want to delete the last element or insert an element at the end of linked list
 * */

#include <iostream>
#include <variant>

struct Node{
    int value;
    Node *next;
};

class SinglyLinkedList{
private:
    int count;
public:
    Node* head;

    SinglyLinkedList(){
        head = nullptr;
        count = 0;
    }

    void insertFirst(int value){
        Node* newNode = new Node;

        newNode->value = value;
        newNode->next = head;
        head = newNode;

        count++;
    }

    void insertLast(int value){
        Node* newNode = new Node;
        newNode->value = value;
        newNode->next = nullptr;

        if(head == nullptr){
            head = newNode;

        } else {
            Node* tmpNode = head;

            while(tmpNode->next){
                tmpNode = tmpNode->next;
            }

            tmpNode->next = newNode;
        }

        count++;
    }

    void insertAtPosition(int position, int value){
        if(position <1 || position > (count+1)){
            std::cout << "Out of range\n";
            return;
        }
        if(position == 1){
            insertFirst(value);
        }
        else if (position == (count+1)){
            insertLast(value);
        } else {
            Node* newNode = new Node;
            newNode->value = value;

            Node* tmpNode = head;

            position-=2;
            while(tmpNode->next && position){
                tmpNode = tmpNode->next;
                position--;
            }

            newNode->next = tmpNode->next;
            tmpNode->next = newNode;
            count++;
        }
    }

    bool deleteFirstNode(){
        if(head == nullptr){
            return false;
        }

       Node* tmpNode = head;
        head = head->next;

        delete tmpNode;

        count--;
        return true;
    }

    bool deleteLast(){
        if(head == nullptr){
            return false;
        } else {
            Node* tmpNode = head;

            if(head->next == nullptr){
                head = nullptr;
                delete tmpNode;
            } else {
                while(tmpNode->next->next){
                    tmpNode = tmpNode->next;
                }

                Node* tmp = tmpNode->next->next;
                tmpNode->next = nullptr;
                delete tmp;
            }

            count--;

            return true;
        }
    }

    bool deleteNthNode(int position){
        if(head == nullptr){
            return false;
        }

        if(position <1 || position > count){
            std::cout << "Out of range!\n";
            return false;
        }
        if(position == 1){
            return deleteFirstNode();
        }
        else if (position == count){
            return deleteLast();
        } else {
            // The node in
            Node* tmpNode = head;
            position-=2;

            while(tmpNode && position){
                tmpNode = tmpNode->next;
                position--;
            }

            Node* targetNode = tmpNode->next;
            tmpNode->next = tmpNode->next->next;
            delete targetNode;

            count--;

            return true;
        }
    }

    void size()const{
        std::cout << count << std::endl;
    }

    void iterativeTraverse(){
        if(head == nullptr){
            std::cout << "Your Linked List Is Empty !\n";
        }
        else {
            Node* tmpNode = head;

            while(tmpNode){
                std::cout << tmpNode->value << " ";

                tmpNode = tmpNode->next;
            }

            std::cout << std::endl;
        }
    }

    void recursiveTraverse(Node* currentNode = nullptr){
        if(currentNode == nullptr){
            return;
        }

        std::cout << currentNode->value << " ";

        recursiveTraverse(currentNode->next);
    }

    void reverse() const{
        SinglyLinkedList reversedLinkedList = *new SinglyLinkedList();

        if(head == nullptr){
            std::cout << "Your linked list is empty\n";
            return;
        }

        Node* tmpNode = head;

        while (tmpNode){
            reversedLinkedList.insertFirst(tmpNode->value);
            tmpNode = tmpNode->next;
        }

        reversedLinkedList.iterativeTraverse();
    }
};
int main(){
    SinglyLinkedList linkedListInstance = *new SinglyLinkedList();

    linkedListInstance.insertLast(50);
    linkedListInstance.insertLast(100);
    linkedListInstance.insertLast(200);
    linkedListInstance.insertLast(300);
    linkedListInstance.insertLast(400);
    linkedListInstance.deleteLast();
    linkedListInstance.deleteNthNode(3);
    linkedListInstance.recursiveTraverse(linkedListInstance.head);
//    linkedListInstance.iterativeTraverse();
//    linkedListInstance.reverse();
    return 0;
}