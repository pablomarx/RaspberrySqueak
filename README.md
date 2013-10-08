RaspberrySqueak
===============

Bare metal Squeak for Raspberry Pi


With a proper dev environment setup, running make should result in a kernel.img being generated.  
Copy that and an Squeak 2.x onto an SD card, and then setup a config.txt to look like:

initramfs squeak.image 0x00800000

And it *should* load.  And then probably hang and crash.  But there's a watchdog timer setup
to save you from having to power cycle. 
