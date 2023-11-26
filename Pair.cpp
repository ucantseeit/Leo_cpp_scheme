#include "Pair.h"
#include <iostream>
#include <assert.h>

namespace Pair_{
    Pair::Pair(const Pair &source) {
        const Pair *track_s = &source;
        Pair *track_d = this;
        for (; track_s->next != nullptr; 
            track_s = track_s->next) {
            track_d->type = track_s->type;
            if (track_s->type == SUBEXPR) {
                track_d->item.subexpr = new Pair(*track_s->item.subexpr);
            } else {
                track_d->item = track_s->item;
            }
            track_d->next = new Pair();
            track_d = track_d->next;
        }
    }

    void Pair::help_display() const {
        using std::cout;

        int count = 0;
        const Pair *track = this;
        
        while (track->next != nullptr) {
            cout << "Pair(";
            switch (track->type) {
                case NIL:
                    cout << "NIL, ";
                    break;
                case OPERATOR:
                    cout << track->item.opr << ", ";
                    break;
                case LITERAL:
                    cout << track->item.literal << ", ";
                    break;
                case SUBEXPR:
                    track->item.subexpr->help_display();
                    cout << ", ";
                    break;
            }
            count++;
            track = track->next;
        }

        assert(NIL == track->type);
        cout << "NIL";
        void insert(int);
        for (int i = 0; i < count; i++) {
            cout << ')';
        }
    }

    void Pair::display() const {
        this->help_display();
        std::cout << std::endl;
    }
}