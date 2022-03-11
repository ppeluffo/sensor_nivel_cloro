/*
 * File:   tk03.c
 * Author: pablo
 *
 * Created on 25 de octubre de 2021, 12:50 PM
 */


#include "sensor_nivel_cloro.h"

//------------------------------------------------------------------------------
void tkSensor(void * pvParameters)
{


( void ) pvParameters;
bool acgen_running;

	vTaskDelay( ( TickType_t)( 500 / portTICK_PERIOD_MS ) );
    xprintf("Starting tkSensor..\r\n");
    
    acgen_running = false;
    acgen_stop();
    
	for( ;; )
	{
        
        while ( xSemaphoreTake( sem_SYSVars, ( TickType_t ) 5 ) != pdTRUE )
  			taskYIELD();

        if ( systemVars.dac != dac ) {
            dac = systemVars.dac;
            DAC_setVal(dac);
        }
        
        xSemaphoreGive( sem_SYSVars );
        
		vTaskDelay( ( TickType_t)( 1000 / portTICK_PERIOD_MS ) );
        
	}
}
//------------------------------------------------------------------------------
