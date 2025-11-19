### Trapping Keyboard Event Data Packets

Captures keyboard event data packets and displays info.

Keyboard events are passed to MOS by VDP. This example illustrates how to capture those packets of data for use within our own programs.

4 bytes of data are sent for each key event, which include:
    1. asciiCode
    2. modifier
    3. fabGLCode
    4. upDownState

this example uses global variables shared between C and ASM code.
Variables demonstrate:
    1. global uint8_t variables
    2. global array variable
    3. copying global array into an event struct
