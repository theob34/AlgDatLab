#include <iostream>
#include <queue>
#include <string>
#include "node.h"
#include "nodeList.h"

using namespace std;

Node __initAdversaryGraph() {
    //Empty for now
    //Create all the graph and return the first node
}

bool isInNodeList (Node node, NodeList * nodesList) {
    //Amélioration : implémenter une liste chaînée pour les amis
    //Utiliser alors cette fonction
    return true;
}

void searchFriends(Node mainNode){

    //I create a list to put all the friends of the main node
    NodeList * friendsOfMainNode ;

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
        bool isFriend;
        if (isInNodeList(currentNode, friendsOfMainNode)) {
            isFriend = true;
        }
        else {
            isFriend = false;
        }

        if (isFriend) {
            //We add all the following friends to the list and to the queue
            for (int i = 0; i < (currentNode.getNumberFollowingFriends()); i++) {
                // add Node in friendsOfMainNode
                // add Node in Queue
            }
            //We add all adversaries only to the queue
            // for all Node in followingAdversaries array
                // add Node in Queue
        } 
        else {
            //We add all the following adversaries to the list and to the queue
            // for all Node in followingAdversaries array
                // add Node in friendsOfMainNode
                // add Node in Queue
            //We add all friends only to the queue
            // for all Node in followingFriends array
                // add Node 
        }

    }

}



int main() {
    
    Node mainNode(8, NULL, 0, NULL, 0);
    cout << "ID : " << mainNode.getID();
    return 1;
}