
/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * Jeroen Domburg <jeroen@spritesmods.com> wrote this file. As long as you retain 
 * this notice you can do whatever you want with this stuff. If we meet some day, 
 * and you think this stuff is worth it, you can buy me a beer in return. 
 * ----------------------------------------------------------------------------
 */

#include "ets_sys.h"
#include "c_types.h"
#include "user_interface.h"
#include "espconn.h"
#include "mem.h"
#include "osapi.h"
#include "gpio.h"
#include "config.h"

#include "espmissingincludes.h"
#define BTNGPIO 0

static ETSTimer resetBtntimer;

 char currGPIO5State=0;

void ICACHE_FLASH_ATTR ioGPIO(int ena, int gpio) {
    GPIO_OUTPUT_SET(gpio, ena);
}

static void ICACHE_FLASH_ATTR resetBtnTimerCb(void *arg) {
	static int resetCnt=0;
	if (!GPIO_INPUT_GET(BTNGPIO)) {
		resetCnt++;
	} else {
		if (resetCnt>=6) { //3 sec pressed
			wifi_station_disconnect();
			wifi_set_opmode(0x3); //reset to AP+STA mode
			os_printf("Reset to AP mode. Restarting system...\n");
			system_restart();
		}
		resetCnt=0;
	}
}

void ICACHE_FLASH_ATTR ioInit() {

	gpio_init();
	PIN_FUNC_SELECT(PERIPHS_IO_MUX_GPIO5_U, FUNC_GPIO5); // relay
	PIN_FUNC_SELECT(PERIPHS_IO_MUX_GPIO0_U, FUNC_GPIO0); // button

	//set GPIO to init state
 	GPIO_OUTPUT_SET(0,(1<<0));

	if( sysCfg.relay_latching_enable) {
	
	os_printf("Relay latching is %d, Relay1=%d\n\r",(int)sysCfg.relay_latching_enable,(int)sysCfg.relay_1_state);
	
		currGPIO5State=(int)sysCfg.relay_1_state;
		ioGPIO((int)sysCfg.relay_1_state,5);

	}
	
	else {
		ioGPIO(0,5);
	}

	os_timer_disarm(&resetBtntimer);
	os_timer_setfn(&resetBtntimer, resetBtnTimerCb, NULL);
	os_timer_arm(&resetBtntimer, 500, 1);
}
