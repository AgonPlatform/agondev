### Example of i2c on Agon - ADC1115

Displays analog values from i2c ADC1115 interface module.

Illustrates example of a small external ASM library to:
1. Open i2c bus (standrd MOS call).
2. Configure i2c module (external ASM library).
3. Read i2c data (external ASM library).
4. Close i2c bus (standrd MOS call).

This routine only reads input 1 of the 4 channel ADC module. Feel free to modify to your own requirements.

Press ESC to exit the program.

From Agon, connect +3.3v, Gnd, SCL and SDA to the ADC1115 module. This can be via the i/o bus, or via the UEXT connector (Agon Light 2).

This example can be tested by placing a potentionmeter connected across Gnd and +3.3v, with centre pin connected to input 1 of the i2c ADC1115 module.


