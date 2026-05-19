//DNode.h

class CircleDLinkedList;    

class DNode {
    private:
        Song elem;             
        DNode* next;            
        DNode* prev;            

        friend class CircleDLinkedList;

        DNode(const Song& e, DNode* p = nullptr, DNode* n = nullptr)
            : elem(e), next(n), prev(p) {
            activeNodes++;
        }

    public:
        static int activeNodes;  

        ~DNode() {
            activeNodes--;
        }
};