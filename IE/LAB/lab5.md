# Single Stage Common Emitter BJT Amplifier with Voltage Divider Bias 2025-02-20 15:36

- To find R4 -> DC Analysis
    - AC src -> short ckt
    - Capacitor -> open ckt

    - Rth = (R1 || R2) = (R1 * R2) / (R1 + R2) = 5.1k / 6.1 = 0.836k ohm
    - Vth = (R2 / R1 + R2) * Vcc = 12 * 1000 / 6100 = 1.96V
    - Vbe = 0.7V
    - -Vcc + R3 * IC + VCE + IE * RE = 0
    - -Vth + IB * RTH + VBE + IE * RE = 0



- To find R3 -> Small signal model
    - DC src -> short ckt
    - Capacitor -> short ckt

- Ic = 1.5mA
