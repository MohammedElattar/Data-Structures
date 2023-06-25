#include <iostream>

/*
 * array is a data structure of Abstract Data Types (ADT) which is not important to know it's implementation
 * All the items of the array must have the same type
 * array has a fixed size
 * accessing an element in an array is O(1)
 * insertion and deletion operation both occurs in O(n) as a worst case
 *
 * but how does the compiler knows what element we want to access ?!
 *
 * array_address + element_size * (index - first item index)
 *
 * of course the worst cast is to insert at the first element of the array
 * that will shift all other elements one index to fit the new element
 *
 * same thing with deletion from the first index
 *
 * but what if we want to insert new element after the array is full ?
 * ans => we will create another array with double size of the previous one and copy old elements to it
 * and insert the new element
 *
 * of course that is a cost of time and it's inefficient and memory
 *
 * we will talk about a data structure that is good at dynamic allocation of memory
 * which is (`Linked List`) in the next lesson
 *
 * */
