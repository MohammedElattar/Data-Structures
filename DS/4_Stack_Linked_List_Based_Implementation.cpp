
/*
 * Stack
 *
 * Stack is called LIFO (Last In First Out)
 *
 * all operations of stack happen in constant time O(1)
 *
 * supported operations are :
 * 1- push
 * 2- pop
 * 3- top
 * 4- isEmpty
 *
 *
 * We can implement the stack using linked lists and use insertFirst() function to add each new element of the stack
 *
 * and use deleteLast() to remove an element from the stack
 * */

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



class Stack{
private:
    int count;
    struct Node{
        int value;
        Node *next;
    };
    Node* head;
public:

    Stack(){
        head = nullptr;
        count = 0;
    }

    void push(int value){
        Node* newNode = new Node;

        newNode->value = value;
        newNode->next = head;
        head = newNode;

        count++;
    }

    bool pop(){
        if(head == nullptr){
            return false;
        }

        Node* tmpNode = head;
        head = head->next;

        delete tmpNode;

        count--;
        return true;
    }

    int top(){
        return head->value;
    }
    int size()const{
        return count;
    }

    [[nodiscard]] bool isEmpty() const{
        return ! count;
    }
};
int main(){
    Stack stack = *new Stack();

    stack.push(10);
    stack.push(50);
    stack.push(100);
    stack.pop();// pop 100
    std::cout << stack.top() << std::endl; // 50
    std::cout << stack.isEmpty(); // false
    return 0;
}