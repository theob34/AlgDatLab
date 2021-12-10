#ifndef DEF_NODE
#define DEF_NODE
#include "List.h"


class Node {
    private:
        int id;
        List * followingFriends;
        List * followingAdversaries;
        
    public:
        Node(int id, List * followingFriends, List * followingAdversaries);
        ~Node();
        
        // Getter
        int getID();
        List * getFollowingFriends();
        int getNumberFollowingFriends();
        List * getFollowingAdversaries();
        int getNumberFollowingAdversaries();

        // Other functions
        bool hasFriends() ;
        bool hasAdversaries();
        void printNode();

};

#endif