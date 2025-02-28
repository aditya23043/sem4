# 2025-02-25 12:38

## Embedded System

- Performs Specific tasks unlike general purpose computers within a larger system
- Low power consumption
- Generally, remotely deployed
- Battery powered
- Tightly integrated
- Compact
- May run RTOS
- Limited resources / performance
- Might not have a user interface
- Equipped with communication interfaces specific for the task eg: UART, SPI, I2C
- Limited scalability

## Neumann vs Harvard Architecture

| Neumann                                                    | Harvard                                        |
| ---------------------------------------------------------- | ---------------------------------------------- |
| Single bus for memory for both instruction and data        | Separate data busses for instruction and data  |
| Sequential access to memory space for instruction and data | Parallel Access to instruction and data memory |
| Complex                                                    | Simple                                         |
| Lower Performance                                          | Higher Performance                             |
| Used in laptops / desktops                                 | Used in embedded systems / mcu / DSPs          |

## Block Diagram Tips

- Input / Output
- Computer (mcu / mpu) -> Low Power
- Display for interfacing
- Input with buttons / pots
- Battery Management System (BMS)
- Driver for external peripherals

## Embedded System Ecosystem

- The comprehensive suit of the software, hardware, services, tools offered by a semiconductor company
- Provided to developers to facilitate design and development
- Aims to streamline the process of creating embedded solutions
- Wide range of Hardware platforms. Eg: STM32 mcu/mpu family
- Software development tools. Eg: STM32CubeMX or STM32CubeIDE
- Operating Systems and Middleware

## Tips regarding semiconductor companies

- Siemens -> Mentor Graphics
- Nvidia -> Hyderabad
- AMD -> Hyderabad and Bangalore

## Noida Semiconductor companies

- Qualcomm
- Synopsys
- Cadence
- NXP
- STM
- Samsung
- ARM

## Short range communication

- NFC : range -> ~5cm
- BLE : range -> ~100m

## Standard Ratings

- Customer
- Industry
- Military
- Space

## Phases of Embedded System Design

- Conceptualization
- Feasability Analysis
- Hardware Design
- Firmware / SW design
- Integration & Packaging

## MCU Info

- Datasheet contains electrical characteristics with a basics of peripherals along with booting info
- Reference manual contains detailed peripheral info (no electrical reference)

## BOM

- Bill of Material
- Used for analyzing cost
- Source of part
- Part number
- Reference Designator
- Pricing

> Items with 0 qty are proposed but not used

### Symbol

| Device Type        | Symbol |
| ------------------ | ------ |
| Active Devices     | U      |
| Transistor         | T      |
| Jumper             | J      |
| Crystal Oscillator | X/Y    |
| Connectors         | CON    |

> Time Sensor is preferred over the HCSR04 ultra sonic sensor because SPEED(light) > SPEED(sound) and consumes very less current

## HMI

- Human Machine Interface
- Eg: used in a 7 segment display to enter "data" and it displays the "data" on the display
- Generally, refers to a screen/display

## Persistence of vision

- "Trick" used in 7 seg displays to display with low power consumption than regular method
- Utilizes the fact that a human eye's refresh rate is capped at a certain limit (16hz)

## MCU specification: bit

- 32 bit mcu means the data bus width is 32bits
- But the number of pins per port is only 16
- In case of the 8051, both were 8

## Slew Rate

- Time taken to toggle a digital signal
- Upto 56MHz in stm32
- Every signal acts as an antenna, releasing radiation
- Higher the slew rate, lower the emitted radiation

## STM32: Output modes

- Push-Pull config
- Open Drain config
- Disabled

## STM32: Input modes

- Floating
- With pullup / pull down resistor

> Input pins can be multiplexed to achieve multiple peripheral compatibility

## STM32: GPIO

- Directly connected to the CPU (higher frequency)
- Some are 5V tolerant even for input
- Fully configurable

### Open Drain

- Remove PMOS
- For doing basic circuitry, like driving an LED, we don't necessarily need a dedicated PMOS
- We can connect the anode of the LED to 3V3 and cathode to the gpio pin (with only NMOS), which is internally grounded
- To turn on the LED, switch on the NMOS and close if you want to switch it off (no current will flow because open ckt)
- Cost effective &#x2713;
- pullup resistor required because with the GPIO can only pull to low using the NMOS

> True open drain circuit -> no pullup resistor

## Schmitt Trigger

- Detects if voltage is high or low
- can be considered as a 1 bit ADC
- prevents noise in input signal
- circuit protection

## ADC

- Input, not through a schmitt trigger
- V_IL = Lowest voltage to get a digital HIGH ~0.3 x V_DD
- V_IH = Highest voltage to get a digital LOW
- I_LKG = leakage current
  - when input connected to V src
  - when NMOS and PMOS are off
  - not needed
  - goes into opamp (~infinite resistance)
- GPIO pins can only take in limited current ~ +- 6ma
- Source Current - Output (through PMOS)
- Sink Current - Input (through NMOS)
- SAR ADC - Successive Approximation Resistance ADC
  - Cheap (num of gates)
  - Fast
  - Reliable
- LDR - Light dependent resistor
- Thermistor - resistor charges with change in temperature

## Quantization Error

- If we have an ADC with steps at every 11.7mV, we cannot determine what we will get at ~5mV

## Oversampler

- helps in increasing resolution
- takes value around the current and gives avg

## Analog Watchdog

- Handles Out of bound conditions
- Sends an interrupt if so

> Conversion Time: time it takes an ADC to convert analog -> digital

- 3 internal ADC
  - Voltage reference
  - Temperature Sensitivity
  - monitoring external V_BAT power supply
- Sample and Hold circuit
  - samples and then holds on to the last value until the input signal is sampled again
- Sequencer

  - Used to choose which channel to sample currently

- V_REF+

  - high reference voltage for ADC
  - if not given, its internally shorted to V_DD

```
if(V_DD > 2){
  V_REF+ = [2, V_DD];
}
else {
  V_REF+ = V_DD;
}
```
