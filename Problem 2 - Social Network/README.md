# Data structure use : 
- STL Queue
- Node :    -> int id;
            -> Node * followingFriends;
            -> Node * followingAdversaries;

# Pseudo-code algorithm :
//The main node is the people for who we want to know who are his/her friends

//I create an list to put all the friends of the main node
friendsOfMainNode

//We add the main Node to the queue
Push mainNode in Queue

//We study all nodes of the graph
//The study is finished when we don't have anymore Node to study in the queue
while (Queue is not empty)
    //We take a Node to study
    currentNode = first Node in Queue

    //We study if is a friend or an adversary of main Node
    if currentNode is in friendsOfMainNode array
        isFriend = true
    else
        isFriend = false


    if (isFriend)
        //We add all the following friends to the list and to the queue
        for all Node in followingFriends array
            add Node in friendsOfMainNode
            add Node in Queue
        //We add all adversaries only to the queue
        for all Node in followingAdversaries array
            add Node in Queue
    else
        //We add all the following adversaries to the list and to the queue
        for all Node in followingAdversaries array
            add Node in friendsOfMainNode
            add Node in Queue
        //We add all friends only to the queue
        for all Node in followingFriends array
            add Node in Queue
        

