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
    Node* rootNode;
    int count;
public:
    SinglyLinkedList(){
        rootNode = nullptr;
        count = 0;
    }

    void insertFirst(int value){
        Node* newNode = new Node;

        newNode->value = value;
        newNode->next = rootNode;
        rootNode = newNode;

        count++;
    }

    void insertLast(int value){
        Node* newNode = new Node;
        newNode->value = value;
        newNode->next = nullptr;

        if(rootNode == nullptr){
            rootNode = newNode;

        } else {
            Node* tmpNode = rootNode;

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

            Node* tmpNode = rootNode;

            position-=2;
            while(tmpNode->next && position){
                tmpNode = tmpNode->next;
                position--;
            }

            newNode->next = tmpNode->next;
            tmpNode->next = newNode;
        }
        count++;
    }

    bool deleteFirstNode(){
        if(rootNode == nullptr){
            return false;
        }

       Node* tmpNode = rootNode;
        rootNode = rootNode->next;

        delete tmpNode;

        count--;
        return true;
    }

    bool deleteLast(){
        if(rootNode == nullptr){
            return false;
        } else {
            Node* tmpNode = rootNode;

            if(rootNode->next == nullptr){
                rootNode = nullptr;
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
        if(rootNode == nullptr){
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
            Node* tmpNode = rootNode;
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

    void traverse(){
        if(rootNode == nullptr){
            std::cout << "Your Linked List Is Empty !\n";
        }
        else {
            Node* tmpNode = rootNode;

            while(tmpNode){
                std::cout << tmpNode->value << " ";

                tmpNode = tmpNode->next;
            }

            std::cout << std::endl;
        }
    }

    void reverse(){
        SinglyLinkedList reversedLinkedList = *new SinglyLinkedList();

        if(rootNode == nullptr){
            std::cout << "Your linked list is empty\n";
            return;
        }

        Node* tmpNode = rootNode;

        while (tmpNode){
            reversedLinkedList.insertFirst(tmpNode->value);
            tmpNode = tmpNode->next;
        }

        reversedLinkedList.traverse();
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
    linkedListInstance.traverse();
    linkedListInstance.reverse();

    return 0;
}