#include "Pair.h"
#include <iostream>
#include <assert.h>

namespace Pair_{
    Pair::Pair(const Pair &source) {
        const Pair *track_s = &source;
        Pair *track_d = this;
        for (; track_s->next != nullptr; 
            track_s = track_s->next) {
            if (track_s->get_type() == SUBEXPR) {
                track_d->item = new Pair(*std::get<Pair*>(track_s->item));
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
            switch (track->get_type()) {
                case NIL:
                    cout << "NIL, ";
                    break;
                case OPERATOR:
                    cout << std::get<string>(track->item) << ", ";
                    break;
                case LITERAL:
                    cout << std::get<float>(track->item) << ", ";
                    break;
                case SUBEXPR:
                    std::get<Pair*>(track->item)->help_display();
                    cout << ", ";
                    break;
            }
            count++;
            track = track->next;
        }

        cout << "NIL";
        for (int i = 0; i < count; i++) {
            cout << ')';
        }
    }

    void Pair::display() const {
        this->help_display();
        std::cout << std::endl;
    }
}