### Example of Large Buffered RGBA2222 Bitmaps

Loads a large colour bitmap's data from memory into a buffer in chunks. 

Displays bitmap on screen using the Plot Bitmap function.

Rotate or flip image, horizontally or vertically.

Press ESC to exit the program.


Image is stored in an array as raw binary data. Although this means the data is stored within the bianry, it makes the binary bigger. If it is important to ship one binary file, then this method works well. 

However, to make the binary smaller, bitmaps could be loaded from disk instead. That method is in a seperate example project.