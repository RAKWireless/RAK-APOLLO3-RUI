#include <stdint.h>
#include "am_mcu_apollo.h"
#include "board-config.h"
#include "rtc-board.h"
#include "sx126x-board.h"
#include "board.h"
#include "service_lora.h"

/*!
 * Flag to indicate if the MCU is Initialized
 */
static bool McuInitialized = false;

void BoardCriticalSectionBegin( uint32_t *mask )
{
    *mask = __get_PRIMASK( );
    __disable_irq( );
}

void BoardCriticalSectionEnd( uint32_t *mask )
{
    __set_PRIMASK( *mask );
}

void BoardInitMcu( void )
{
    if( McuInitialized == false )
    {
        RtcInit( );
    }

    SpiInit( &SX126x.Spi, SPI_1, RADIO_MOSI, RADIO_MISO, RADIO_SCLK, RADIO_NSS );
    SX126xIoInit( );

    if( McuInitialized == false )
    {
        McuInitialized = true;
    }
}

void BoardGetUniqueId( uint8_t *id )
{
    service_lora_get_dev_eui(id, 8);
}

uint8_t BoardGetBatteryLevel( void ) {
    return 0;
}
