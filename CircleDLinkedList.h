//CircleDLinkedList.h

#include "Song.h"
#include "DNode.h"
#include <iostream>

class CircleDLinkedList {
    private:
        DNode* cursor;      
        int n;                  
        
    public:
        CircleDLinkedList() : cursor(nullptr), n(0) {
        }

        ~CircleDLinkedList() {
            while (!empty()) {
                remove();
            }
        }

        bool empty() const {
            return cursor == nullptr;
        }

        int size() const {
            return n;
        }

        void add(const Song& e) {
            DNode* newNode = new DNode(e);
            if (empty()) {
                newNode->next = newNode;
                newNode->prev = newNode;
            } else {
                DNode* nextNode = cursor->next;
                newNode->prev = cursor;
                newNode->next = nextNode;
                cursor->next = newNode;
                nextNode->prev = newNode;
            }
            cursor = newNode;
            n++;
        }

        void remove() {
            DNode* oldNode = cursor;
            if (n == 1) {
                cursor = nullptr;
            } else {
                DNode* prevNode = oldNode->prev;
                DNode* nextNode = oldNode->next;
                prevNode->next = nextNode;
                nextNode->prev = prevNode;
                cursor = nextNode;
            }
            delete oldNode;
            n--;
        }

        void advance() {
            cursor = cursor->next;
        }

        void retreat() {
            cursor = cursor->prev;
        }

        Song getCurrentSong() const {
            return cursor->elem;
        }

        void print(bool forward = true) const {
            if (empty()) {
                std::cout << "Playlist is empty." << std::endl;
                return;
            }
            DNode* temp = cursor;
            for (int i = 0; i < n; i++) {
                std::cout << temp->elem;
                if (forward) {
                    temp = temp->next;
                } else {
                    temp = temp->prev;
                }
            }
            std::cout << std::endl;
        }
};
