#ifndef DEF_NODE
#define DEF_NODE


class Node {
    private:
        int id;
        Node * followingFriends; // Amélioration : utiliser une liste chaînée plutôt qu'un tableau avec un nombre d'éléments connus
        int numberFollowingFriends;
        Node * followingAdversaries; // Amélioration : utiliser une liste chaînée plutôt qu'un tableau avec un nombre d'éléments connus
        int numberFollowingAdversaries;

    public:
        Node(int id, Node * followingFriends, int numberFollowingFriends, Node * followingAdversaries, int numberFollowingAdversaries);
        ~Node();
        
        // Getter
        int getID();
        Node * getFollowingFriends();
        int getNumberFollowingFriends();
        Node * getFollowingAdversaries();
        int getNumberFollowingAdversaries();

        // Other functions
        bool hasFriends() ;
        bool hasAdversaries();
        void printNode();

};

#endif