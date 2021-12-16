#include <iostream>
#include <queue>
#include <string>
#include "Node.h"
#include "List.h"

using namespace std;

Node __initAdversaryGraph() {
    //Empty for now
    //Create all the graph and return the first node
}

bool isInNodeList (Node node, List * nodesList) {
    Element * currentNode = nodesList->getFirstElement();
    bool found = false;
    for (int i = 0; i < nodesList->sizeList(); i++) {
        if (node.toCompare(*(currentNode->getData()))) {
            found = true;
        }
        currentNode = currentNode->getNextElement();
    }
    return found;
}

void searchFriends(Node mainNode){

    //I create a list to put all the friends of the main node
    List * friendsOfMainNode = new List() ;

    //We add the main Node to the queue
    queue <Node> nodesToStudy ;
    nodesToStudy.push(mainNode) ;

    //We study all nodes of the graph
    //The study is finished when we don't have anymore Node to study in the queue
    while (!(nodesToStudy.empty())) {
        //We take the Node to study
        Node currentNode = nodesToStudy.front() ;
        nodesToStudy.pop() ;

        //We study if is a friend or an adversary of main Node
        bool isFriend = isInNodeList(currentNode, friendsOfMainNode);

        if (isFriend) {
            //We add all the following friends to the list and to the queue
            List * followingFriends = currentNode.getFollowingFriends();
            Element currentElement = *(followingFriends->getFirstElement()); //We create a copy of the first element of the list
            for (int i = 0; i < (currentNode.getNumberFollowingFriends()); i++) {
                // add Node in friendsOfMainNode
                friendsOfMainNode->insertLast(&currentElement);
                // add Node in Queue
                nodesToStudy.push(*(currentElement.getData()));
                // take the next Node
                currentElement = *(currentElement.getNextElement());
            }
            //We add all adversaries only to the queue
            List * followingAdversaries = currentNode.getFollowingAdversaries();
            currentElement = *(followingAdversaries->getFirstElement()); //We create a copy of the first element of the list
            for (int i = 0; i < (currentNode.getNumberFollowingAdversaries()); i++) {
                // add Node in Queue
                nodesToStudy.push(*(currentElement.getData()));
                // take the next Node
                currentElement = *(currentElement.getNextElement());
            }
        } 
        else {
            //We add all the following adversaries to the list and to the queue
            List * followingAdversaries = currentNode.getFollowingAdversaries();
            Element currentElement = *(followingAdversaries->getFirstElement()); //We create a copy of the first element of the list
            for (int i = 0; i < (currentNode.getNumberFollowingAdversaries()); i++) {
                // add Node in friendsOfMainNode
                friendsOfMainNode->insertLast(&currentElement);
                // add Node in Queue
                nodesToStudy.push(*(currentElement.getData()));
                // take the next Node
                currentElement = *(currentElement.getNextElement());
            }
            //We add all friends only to the queue
            List * followingFriends = currentNode.getFollowingFriends();
            currentElement = *(followingFriends->getFirstElement()); //We create a copy of the first element of the list
            for (int i = 0; i < (currentNode.getNumberFollowingAdversaries()); i++) {
                // add Node in Queue
                nodesToStudy.push(*(currentElement.getData()));
                // take the next Node
                currentElement = *(currentElement.getNextElement());
            }
        }

    }

}



int main() {
    
    Node mainNode(8, NULL, NULL);
    cout << "ID : " << mainNode.getID();
    return 1;
}