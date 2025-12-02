### RGB82 - RGBA8888 to RGBA2222 file converter

A useful tool for use on your Agon or in the emulator for making smaller _RGBA2222_ format files.

These are a smaller format for use when loading graphics into your games or applications, but still use all 64 colours available on the Agon.

Converts all files in current working directory.

Converts from RGBA888 to RGBA2222 format with closest match to Agon palette.

Source files need to be in the RGBA8888 format.

_RGBA8888_ files can be created in many graphics packages, such as `GIMP`. Export your image files as `RAW` or `DATA`, ensuring that the are 4 channels, RGB & A. 

For example, a 16x16 pixel bitmap will take exactly 1024 bytes (16 x 16 x 4 RGBA bytes = 1024) in full RAW RGBA8888 format. When converted to _RGBA2222_ it will be 1/4 size - 256 bytes.

There is no loss in colour quality as the Agon can only display 64 colours, and only 1bit for transparency (on or off, no blending)

Make sure the `RGB82.bin` is in the `BIN` directory on your SD card (or emulator).

Navigate to a folder of raw RGBA8888 files.

Run the command `RGB82` and all valid files in that folder will be converted.

New files will be created with the _.RGB2_ extension.

NOTE. Although this program will try to picke the closest value for each of RGB channels in the source image, when creating graphics assets to be used in your applications, it is best to convert to the Agon palette first, so you know exatly what colours you will end up with. For larger images, dithering can be used in most graphics propgrams to give a better overall result.

