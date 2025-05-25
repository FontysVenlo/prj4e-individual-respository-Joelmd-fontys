# Motor Comparison for Smart Radiator Thermostat

This document compares several common motor types to determine the best fit for controlling a radiator valve with a focus on precision, control, and integration with embedded systems.

| Motor Type   | Pros                                                                 | Cons                                                                  | Notes on Use Case                                 |
|--------------|----------------------------------------------------------------------|-----------------------------------------------------------------------|---------------------------------------------------|
| DC Motor     | - Simple to control<br>- Compact<br>- Affordable                    | - No precise position control<br>- Needs encoder for feedback         | Not ideal for valve positioning without feedback  |
| Servo Motor  | - Easy to control angle (via PWM)<br>- Integrated feedback loop     | - Limited rotation range (typically 0–180°)<br>- Can be noisy         | Could work but may lack required torque or range  |
| Stepper Motor| - Precise position control<br>- Open-loop control possible<br>- Good torque at low speeds | - More complex driving logic<br>- Higher power draw                   | Chosen for this project due to precision needs    |

## Conclusion

After comparing available options, we selected the **Stepper Motor** for its ability to accurately control position without requiring additional sensors. This aligns well with our need to open/close the valve in controlled steps, offering better repeatability and control than DC or servo motors in this context.

