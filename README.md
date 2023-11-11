# Arduino-Password-Based-Circuit-Breaker (PBCB)
A password-based circuit breaker or PBCB is an electrical switch operated through a user-defined password, providing a secure and controlled means of activating or deactivating an electronic circuit. Built on the Arduino Uno platform, this project seamlessly integrates hardware and software to deliver a reliable solution for circuit protection

Below is a diagram of the circuit:
![Circuit Diagram](https://github.com/THEWILDONE4ALL/Arduino-Password-Based-Circuit-Breaker/assets/86284683/9d7e7aa7-a516-453e-9b27-80f49cf18d56)

# Modularity
This diagram showcases the circuit setup without the use of a breadboard however, it is recommended to use one if you testing the circuit before making the final project. With this PBCB System, you can further modify this depending on your needs, you can replace the light bulb with any hardware that requires an electrical output to function for example the use of an electric motor. This system can be used for various applications such as password-based door locks etc with only minor adjustments needed to the code.

# Note You Can Change The Electrical Source On The Diagram
You can also replace the battery in the diagram and use an AC or DC load depending on the project you are working on, meaning you can freely use a live wire connected to an electrical outlet for its functionality and for controlling multiple hardware you can replace the single channel relay being used with dual channel or more. However major changes need to be made to the code for independent control per channel on the relay.

You will need 5 of its core components:
1. Arduino Uno (Well obviously)
2. 16x2 LCD
3. I2C (This usually comes with your LCD)
4. 4X4 Matrix Keypad (or whatever keypad you wish)
5. Relay Module (If your only going to be connecting this to one hardware get a signle channel relay any more will depend on you)

Feel free to use this project however you wish, modify it if needed. If you have any questions feel free and contact me and ill try to help.
