# My Project


## Project

### Power Analysis

- Pico @ Idle -> 20-30 mA
- Single Keypress current
  - Individually, each switch's one terminal is connected to GND and other to one GPIO on the MCU
  - And the GPIO is pulled up high by default from the software
  - The pullup resistors on the pico range from 50k to 80k ohms
  - Assuming 50k -> Current due to a single key being pressed = V / R = 3.3 / 50k ~= 66uA
  - In the worst case, all 18 keys are being held down -> 1.1mA
- Along with that, the library I am using for sending the keypress requires about 5mA overhead
- Hence, in the worst case, max current consumption will be -> 36.1mA
- Furthermore, the firmware includes a deep sleep mode as well when keys are not pressed for like a minute
  - Due to which the current consumption drops to just 1mA overall
- power = 5 * 36.1 = 180.5mW
- for 2 * 8650 cells -> 5000mAh
  - That means runtime of the keyboard in one charge -> 5000/36.1 hours = 138.5 hours
- Assuming max to max usage -> 5 hours of usage per day
- About 27 days of usage then
- But with wifi -> 80-100mA base

### Raspberry Pi Pico
#### Specs
- Operating Voltage = 5V input lowered down to 3V3
- Operating Frequency = 133MHz

#### Features
- Low cost
- Wide compatibility of software
- Low power consumption (without WiFi)
- number of gpio pins
- very powerful M0 cortex 2 cores processor
- good RAM

### Technical Challenges
- Communication between the two halves
- Wrong footprint used in the PCB design
- Logical error in firmware
  - Not able to implement the feature when we hold down the key and it sends mulitple keypresses
  - After that, not able to reduce the delay between these multiple keypresses 
- 3D Case tolerance issues
- Battery management

##
