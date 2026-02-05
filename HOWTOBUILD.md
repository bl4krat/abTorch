How to build this project:
```
get_idf  		// you follwed the idf install instructions and added this
				// alias to set the evnironment variables, right?
```
Copy this project to a suitable folder and CD to the project root folder:
```
idf.py set-target esp32		// set-target --list to see the options
idf.py menuconfig			// 'This demo uses the default settings'
							// say the install instructions. But the
							// WROOM has 4MB flash, which won't prevent
							// success, but there will be messages about
							// size mismatch and YOU'LL KNOW, so fix that.
idf.py build
idf.py [-p /dev/ttytUSB0] flash  // -p is optional here. 
								 // and it can come after 'flash' if you want.
idf.py monitor -p /dev/ttyUSB0   // to see the output from printf()
								 // -p IS NOT optional here (it should be
								 // but it doesnt connect without it).
								 // Again, order is not important.
```
