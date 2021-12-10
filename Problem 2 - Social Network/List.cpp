#include <iostream>
#include "List.h"

using namespace std;

// -- Element -- //

Element::Element(Node * data, Element * nextElement, Element * previousElement) {
    if (data == NULL) {
        cout << "Cannot create an Element with empty datas. Need a non-null node.";
        //Amélioration : lever une erreur et quitter le constructeur
    }
    else {
        this->data = data;
        this->nextElement = nextElement;
        this->previousElement = previousElement;
    }
}

Element::~Element() {
    //Empty for now
}

// Getter

Node * Element::getData() {
    return this->data;
}

Element * Element::getNextElement() {
    return this->nextElement;
}

Element * Element::getPreviousElement() {
    return this->previousElement;
}

// Setter

void Element::setNextElement(Element * nextElement) {
    this->nextElement = nextElement;  
}

void Element::setPreviousElement(Element * previousElement) {
    this->previousElement = previousElement;
}


// -- List -- //

List::List () {
    this->firstElement = NULL ;
    this->lastElement = NULL ;
    this->numberElement = 0 ;
}

List::~List () {
    //Empty for now
}

// Getter

Element * List::getFirstElement () {
    return this->firstElement;
}

Element * List::getLastElement () {
    return this->lastElement;
}

// Other functions

void List::insertLast (Element * element) {
    if (this->sizeList() == 0) {
        this->firstElement = element;
        this->lastElement = element;
    }
    else {
        this->lastElement->setNextElement(element);
        element->setPreviousElement(this->lastElement);
        this->lastElement = element;
    }
    this->numberElement++;
}

void List::removeLast () {
    if (this->sizeList() == 0) {
        cout << "Empty list. No node to remove";
    }
    else if (this->sizeList() == 1) {
        this->firstElement = NULL;
        this->lastElement = NULL;
        this->numberElement--;
    }
    else {
        this->lastElement->getPreviousElement()->setNextElement(NULL);
        this->lastElement = this->lastElement->getPreviousElement();
        this->numberElement--;
        //Amélioration : penser à désallouer le last élément qu'on a supprimé
    }
}

void List::printList () {
    Element * current = this->firstElement;
    for (int i = 0; i < this->sizeList(); i++) {
        current->getData()->printNode();
        current = current->getNextElement();
        cout << " -> ";
    }
    cout << " NULL";
}

int List::sizeList () {
    return this->numberElement;
}