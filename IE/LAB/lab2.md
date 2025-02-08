# BJT Biasing
- Fixed Bias
- Emitter Feedback Bias
- Voltage Divider Bias

# Quotient Point
- We need this to be constant (not varying)

# AIM
- which circuit provides the best stability
- How much is Q fluctuating

# CIRCUITS
- Since beta is >>> 1 -> Approximation -> I_C ~= I_E

## First Circuit
- -12 + I_B * R_B + V_BE = 0
- I_B = (12 - V_BE) / R_B
- V_CE = 12 - I_C * R_C
- I_C = (beta) * I_B

## Second Circuit
- I_B = (12 - V_BE - I_E * R_E) / R_B
- V_CE = 12 - I_C * R_C + I_E * R_E

## Third Circuit
- Transform the circuit using Thevenin's Equivalent
- R_Th = R_1 || R_2
- V_Th is V_BB which can be found using voltage divider circuit
- V_Th = R2 / (R1+R2) * 12V
