#include <iostream>
#include "node.h"

using namespace std;

Node::Node(int id, Node * followingFriends, int numberFollowingFriends, Node * followingAdversaries, int numberFollowingAdversaries) {
    this->id = id;
    this->followingFriends = followingFriends;  // Amélioration : utiliser une liste chaînée plutôt qu'un tableau avec un nombre d'éléments connus
    this->numberFollowingFriends = numberFollowingFriends;
    this->followingAdversaries = followingAdversaries; // Amélioration : utiliser une liste chaînée plutôt qu'un tableau avec un nombre d'éléments connus
    this->numberFollowingAdversaries = numberFollowingAdversaries;
}

Node::~Node() {
    //Désallouer la mémoire des variables allouées dynamiquement
}

// Getter

int Node::getID() {
    return this->id;
}

Node * Node::getFollowingFriends() {
    return this->followingFriends;
}

int Node::getNumberFollowingFriends() {
    return this->numberFollowingFriends;
}

Node * Node::getFollowingAdversaries() {
    return this->followingAdversaries;
}

int Node::getNumberFollowingAdversaries() {
    return this->numberFollowingAdversaries;
}

// Other functions

bool Node::hasFriends() {
    return (this->numberFollowingFriends == 0);
}

bool Node::hasAdversaries() {
    return (this->numberFollowingAdversaries == 0);
}

void Node::printNode() {
    cout << this->getID();
}