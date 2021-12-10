#ifndef DEF_NODELIST
#define DEF_NODELIST

#include "node.h"

class Element {
    private:
        Node * data;
        Element * nextElement;
        Element * previousElement;
    
    public:
        Element(Node * data, Element * nextElement, Element * previousElement);
        ~Element();

        // Getter
        Node * getData();
        Element * getNextElement();
        Element * getPreviousElement();

        // Setter
        void setNextElement(Element * nextData);
        void setPreviousElement(Element * previousElement)

};

// Définition de la classe Liste
class List {
    private:
        Element * firstElement;
        Element * lastElement;
        int numberElement;

    public:
        List ();
        ~List ();

        // Getter
        Element * getFirstElement ();
        Element * getLastElement ();

        // Other functions
        void insertLast (Element * element);
        void removeLast ();
        void printList ();
        int sizeList ();
        
};



#endif