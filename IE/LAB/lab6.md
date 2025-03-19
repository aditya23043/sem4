# 2025-03-07 14:41

- MOSFET
  - Characteristic graph: I_D vs V_DS
  - As compared to BJT where it was: I_C vs V_CE
    - We got V_GS from the graph as compared to I_B
  - BJT was current controlled
- FET is voltage controlled

$$
I_d = K_n * (V_gs - V_t)^2
$$

- K_n and V_t are transistor dependent
- For a known value of I_d and V_gs, we need 2 equations to get the other params
- let, I_d = 1mA and 4mA
- V_gs = V_DD because there isnt anything besides ammeter which has ~0 resistance
- Characteristic params figured out

- We want mode = saturation
- The beta equivalent in a MOSFET is transconductance g_m = delta(I_d) / delta(V_gs)
- let I_d = 6mA
- vary I_d about +- 0.5mA
- find g_m
- find V_gs at 6mA
- note: no resistance at S, so V_g = V_gs

- for MOSFET, gate current is always = 0
- V_g = R/(R+100k) \* V_DD

- Av = -gm _\*\* R_D = -gm _ 1k
- replace 1k with 680 ohm

- 4ma at 4.5V
- 1ma at 2.6V
- Vt = 0.7V
- kn = 277 micro
- gm = 3 / 1.9 = 1.578 milli
