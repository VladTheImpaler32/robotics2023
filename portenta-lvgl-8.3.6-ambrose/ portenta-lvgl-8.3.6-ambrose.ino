#include "Portenta_lvgl.h" //Version 8.3.6

void setup() {
  Serial.begin(115200);

  portenta_init_video(); 

  lv_obj_set_style_bg_color(lv_scr_act(), lv_color_hex(0xd956e8), LV_PART_MAIN); //Set background color

  lv_obj_t * label = lv_label_create(lv_scr_act());     /*Add a label to the button*/
  lv_label_set_text(label, "Hello World");                /*Set the labels text*/
  lv_obj_center(label);                                 // Center the label
}

void loop() {
  lv_task_handler();
}
