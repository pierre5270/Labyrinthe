#pragma once
#include "Vue.hpp"

#define X_RESULT 400
#define Y_RESULT 300

class Vue_R : public Vue {

    private :
        Gtk::Label label ;
    
    public :

        Vue_R(int);
};