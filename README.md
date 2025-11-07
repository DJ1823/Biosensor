Biosensors combine a biological sensing element with electronic components to detect biological parameters and convert them into measurable signals. Temperature is one of the key variables influencing biological and biochemical reactions, especially enzyme activity. Enzymes exhibit optimal activity at a specific temperature (commonly near 37 °C for human enzymes), beyond which their efficiency declines due to denaturation.
Several studies have explored temperature-sensitive biosensors using thermistors, infrared sensors, or microcontrollers for biomedical and environmental monitoring. The TMP36 analog temperature sensor is widely used for accurate, low-cost temperature measurement. Arduino-based biosensor simulations offer a platform for demonstrating biosensor behavior without requiring physical biological materials. Simulating enzyme activity in response to temperature provides a simple model for understanding enzyme kinetics and the role of biosensors in diagnostics.


Methodology
Hardware/Simulation Components:
	Arduino UNO (virtual, Tinkercad Circuits)
	TMP36 Temperature Sensor
	16×2 LCD Display
	Potentiometer (for LCD contrast)
	Breadboard, jumper wires, LEDs (4)
	Tinkercad Circuits online simulation platform



Procedure:
	Sensor Setup:
The TMP36 sensor is connected to Arduino’s analog input (A0). It outputs a voltage proportional to temperature.
	Data Acquisition:
Arduino reads analog signals using its ADC (Analog-to-Digital Converter). The voltage is converted into temperature (°C) using:
T(°C)= (V_{out} - 0.5)× 100
	Enzyme Activity Modeling:
A Gaussian model is applied in code to simulate enzyme activity as a function of temperature:
Activity = e^(-(((T - T_{opt}  )^2 ))/(〖(2σ〗^2))  X 100)

where σ=5and optimal temperature = 37 °C.
	Display System:
The temperature and enzyme activity are displayed on the LCD. LEDs indicate different levels of activity.
	Simulation Environment:
The circuit and program are implemented virtually in Tinkercad Circuits. No physical components are required.
