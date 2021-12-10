#include <iostream>
#include "node.h"

using namespace std;

Node::Node(int id, List * followingFriends, List * followingAdversaries) {
    this->id = id;
    this->followingFriends = followingFriends;  
    this->followingAdversaries = followingAdversaries; 
}

Node::~Node() {
    //Désallouer la mémoire des variables allouées dynamiquement
}

// Getter

int Node::getID() {
    return this->id;
}

List * Node::getFollowingFriends() {
    return this->followingFriends;
}

int Node::getNumberFollowingFriends() {
    return (*this->followingFriends).sizeList();
}

List * Node::getFollowingAdversaries() {
    return this->followingAdversaries;
}

int Node::getNumberFollowingAdversaries() {
    return (*this->followingAdversaries).sizeList();
}

// Other functions

bool Node::hasFriends() {
    return (this->getFollowingFriends() == 0);
}

bool Node::hasAdversaries() {
    return (this->getFollowingAdversaries() == 0);
}

void Node::printNode() {
    cout << this->getID();
}