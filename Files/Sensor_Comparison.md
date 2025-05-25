# Sensor Comparison Document

This document compares several temperature sensors considered for the Smart Radiator Thermostat project.

| Sensor               | Type                      | Temp. Range      | Accuracy            | Advantages                                   | Disadvantages                            | Notes                                    |
|----------------------|---------------------------|------------------|---------------------|----------------------------------------------|------------------------------------------|------------------------------------------|
| Honeywell HIH-4030   | Capacitive Humidity & Temp | -40°C to 85°C    | ±0.5°C (temp), ±3.5% RH | Integrated humidity & temp, compact size     | Limited temp accuracy, requires calibration | Original sensor; less suited for precise temp control |
| DS18B20 Waterproof   | Digital Temp Sensor         | -55°C to +125°C  | ±0.5°C typical      | High accuracy, waterproof, easy 1-Wire interface | Slightly larger, more costly               | Selected for project due to robustness and accuracy |
| TMP36                | Analog Temp Sensor          | -40°C to 125°C   | ±2°C typical        | Simple, low cost                              | Lower accuracy, analog read needed         | Considered for simplicity                  |
| LM35                 | Analog Temp Sensor          | -55°C to 150°C   | ±0.5°C at room temp | Accurate, low cost                            | Analog, requires ADC calibration            | Possible alternative                      |
| SHT31                | Digital Temp & Humidity     | -40°C to 125°C   | ±0.3°C temp         | High accuracy, combined sensors                | More expensive, I2C complexity               | Advanced option with humidity sensing    |

## Conclusion

The waterproof DS18B20 sensor was chosen for its high accuracy and durability, particularly the protection against moisture exposure critical in the thermostat environment. While the non-waterproof DS18B20 offers similar accuracy, it lacks environmental protection, making it less suitable for this application. Analog sensors like TMP36 and LM35 were considered but ruled out due to lower precision and more complex calibration needs. The Honeywell HIH-4030 remains useful for humidity sensing but is insufficiently precise for temperature control in this project.