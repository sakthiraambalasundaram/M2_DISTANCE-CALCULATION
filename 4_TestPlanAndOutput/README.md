# DISTANCE METER:

## TEST CASE :

| Sl.No | Test scenario| Test data |
|:----|:------------|:--------|
|1.|HCSR04Init|setting the trigger pin as output as it will generate ultrasonic sound wave.|
|2.|HCSR04Trigger|It will generate ultrasonic sound wave for 15 microseconds send a 10uS pulse on trigger line.|
|2.a.|uint16_t GetPulseWidth|It will be used to measure the pulse duration. When the ultra sound echo back after hitting an object the microcontroller will read the pulse using the echo pin of the ultrasonic sensor connected to it.|
|2.b.|initialize |this will set the LCD pins connected on the microcontroller as output|
|3.|lcd_command|in order to send command to the lcd first we need to write the command on the data pins. then set the RS pin to zero and enable pin to high.|


## EXPECTED OUTCOMES: -

|Sl.no| EXPECTED RESULT|
|:----|:---------------|
|1.|Setting the trigger pin as output as it will generate ultrasonic sound wave.|
|2.|It will generate ultrasonic sound wave for 15 microseconds send a 10uS pulse on trigger line.|
|3.|It will be used to measure the pulse duration. When the ultra sound echo back after hitting an object the microcontroller will read the pulse using the echo pin of the ultrasonic sensor connected to it.|
|4.|This will set the LCD pins connected on the microcontroller as output.|
|5.|In order to send command to the lcd first we need to write the command on the data pins. then set the RS pin to zero and enable pin to high.|
