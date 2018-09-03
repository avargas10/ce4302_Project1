//
// Created by kakaroto on 02/09/18.
//

#include "observer.h"
void bus::notify() {
    // 5. Publisher broadcasts
    for (int i = 0; i < views.size(); i++)
        views[i]->update();
}