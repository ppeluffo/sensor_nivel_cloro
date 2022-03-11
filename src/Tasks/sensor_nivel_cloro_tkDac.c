/*
 * File:   tkTerm.c
 * Author: pablo
 *
 * Created on 25 de octubre de 2021, 12:50 PM
 */


#include "sensor_nivel_cloro.h"
#include "dac.h"

//------------------------------------------------------------------------------
void tkDac(void * pvParameters)
{

	// Esta es la primer tarea que arranca.

( void ) pvParameters;
uint16_t dac;

	vTaskDelay( ( TickType_t)( 500 / portTICK_PERIOD_MS ) );
    xprintf("Starting tkDAC..\r\n");

    systemVars.dac = 0;
    dac = 0;
    
	for( ;; )
	{
   
		vTaskDelay( ( TickType_t)( 1000 / portTICK_PERIOD_MS ) );
        
        while ( xSemaphoreTake( sem_SYSVars, ( TickType_t ) 5 ) != pdTRUE )
  			taskYIELD();
        
		if ( systemVars.dac != dac ) {
            dac = systemVars.dac;
            DAC_setVal(dac);
        } 
        
        xSemaphoreGive( sem_SYSVars );
	}
}
//------------------------------------------------------------------------------
