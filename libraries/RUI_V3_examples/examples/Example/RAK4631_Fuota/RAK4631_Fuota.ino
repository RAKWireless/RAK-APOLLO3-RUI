#include "service_lora_fuota.h"
 
 

void led_on(uint32_t pin,gpio_dir_t dir,gpio_pull_t pull,gpio_logic_t logic)
{
	udrv_gpio_set_dir(pin, dir);
	udrv_gpio_set_pull(pin, pull);
    udrv_gpio_set_logic(pin, logic);	
}

 
//join_status_handler
 void join_handler(int32_t p_context)
 {
		udrv_serial_log_printf("enter ota update!\r\n");
	    LoraStartTx();  //start timer1
}
 
void setup()
{
    led_on(36,GPIO_DIR_OUT,GPIO_PULL_NONE,GPIO_LOGIC_HIGH);
	service_lora_register_join_cb(join_handler);
}

void loop()
{
  UplinkProcess(); 
  /* Destroy this busy loop and use timer to do what you want instead,
   * so that the system thread can auto enter low power mode by api.system.lpm.set(1); */
}
