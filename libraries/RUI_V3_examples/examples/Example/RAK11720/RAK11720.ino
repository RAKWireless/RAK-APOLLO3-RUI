
void setup()
{
    uint32_t baudrate = Serial.getBaudrate();
    Serial.begin(baudrate);
    Serial6.begin(baudrate, RAK_AT_MODE);
      
    Serial.println("RAKwireless RAK11720");
    Serial.println("------------------------------------------------------");
    Serial.printf("Version: %s\r\n", api.system.firmwareVersion.get().c_str());
  
    // Start BLE UART advertisement for 30 seconds
    api.ble.settings.blemode(RAK_BLE_UART_MODE);
    api.ble.advertise.start(30);
}

void loop()
{
    /* Destroy this busy loop and use timer to do what you want instead,
     * so that the system thread can auto enter low power mode by api.system.lpm.set(1); */
    api.system.scheduler.task.destroy();
}
