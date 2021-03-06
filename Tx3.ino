// Include RadioHead Amplitude Shift Keying Library
#include <RH_ASK.h>
//#include <RadioHead.h>
// Include dependant SPI Library 
#include <SPI.h> 
 
// Create Amplitude Shift Keying Object
//RH_ASK rf_driver;
RH_ASK rf_driver(2000, 11, 12, 0);  
void setup()
{
     Serial.begin(9600);
    // Initialize ASK Object
    rf_driver.init();
}

int value = 0;
const char* outTopic = "#";

void loop()
{
    char outMessage[100] = "";
    sprintf(outMessage, "[%s]%d", outTopic, value);
    //const char *msg = "#";// + (char)value;
    Serial.println(outMessage);
    delay(200);
    rf_driver.send((uint8_t *)outMessage, strlen(outMessage));
    rf_driver.waitPacketSent();
    
    delay(1000);
    value=value+1;
}
