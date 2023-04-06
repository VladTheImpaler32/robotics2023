#include "Portenta_LittleVGL.h" //7.11.0

static lv_obj_t *label;
static lv_style_t style;

void setup(){ 
  Serial.begin(115200);
  
  // Initialize Portenta's video interface
  portenta_init_video();
    
  // Setting up the label making it a child of the screen
  label = lv_label_create(lv_scr_act(), NULL);
  // Enable label recoloring in text
  lv_label_set_recolor(label, true); 

  // Set the label's text
  lv_label_set_text(label , "#0000ff This# is a #ff0000 test# label");

  // We move it to the center of the screen and align it centered
  lv_obj_align(label, NULL, LV_ALIGN_CENTER, 0, 0);
}

void loop() {
  lv_task_handler();
}
