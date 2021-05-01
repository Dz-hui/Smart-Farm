#include "lv_draw_main.h" 

MY_UI_T my_ui; 

void lv_draw_init(void) {

    my_ui.main_src = lv_obj_create(NULL, NULL);
    
}




static void event_popup_draw(const char *text) {

    switch(my_ui.event) {

        case EVENT_TEMP:
        break;

        // ....
    }
}

void lv_draw_home(void) {

    my_ui.ui_list = UI_HOME;

    
}


void my_lv_obj_del(lv_obj_t *obj) {
    lv_obj_clear(obj);
}







