vnc with tight vnc on pi
https://forums.raspberrypi.com/viewtopic.php?t=176408
So I did an update today on my Pi 3 running Raspbian. 
Now when I try to connect to it using VNC from my PC, the VNC viewer goes "No matching security types". 
That's with RealVNC. I get the same error when running vncviewer in Solaris 10. 
If I try TightVNC on the PC, I get "No security types supported". 
Oddly enough, the VNC Viewer app for Android works fine

From there I opened the VNC server window. From there I went to the Options menu, 
set Authentication to "VNC password" and Encryption to "Prefer off". I then clicked OK and that was that. I can now log into the Pi using RealVNC and TightVNC from my PC's again.



REFERENCES

https://bob.cs.sonoma.edu/IntroCompOrg-RPi/sec-gpio-mem.html  Introduction to Computer Organization: ARM Assembly Language Using the Raspberry PiRobert G. Plantz (really good)

ARM code in github https://github.com/rgplantz/itco_ARM/tree/main

Thank you, Jobutex, for the kind words about my book. It's being used in the classroom for the first time this semester at Sonoma State University and Santa Rosa Jr. College. I'm sure there will be changes as I receive feedback from the students. :-) And I would very much like to hear comments from any readers, especially errors or suggested improvements. I maintain a log of changes under the "Errata" tab on my main web page.

Note that the last chapter is an assembly language introduction to programming the GPIO. The intent of my explanation is to help the reader to understand how to read the Broadcom datasheet, and the reasons for using /dev/mem and the mmap function. I think this chapter would be useful even for those who will be programming the GPIO in higher level languages.

Enjoy, Bob Plantz https://bob.cs.sonoma.edu/index.html  Robert G. Plantz

https://bob.cs.sonoma.edu/IntroCompOrg-RPi/sec-gdb1.html  2.11 Examining Memory With a Debugger

https://en.wikipedia.org/wiki/Mmap  In computing, mmap(2) is a POSIX-compliant Unix system call that maps files or devices into memory

cisco binary game 
https://learningnetwork.cisco.com/s/binary-game
https://learningcontent.cisco.com/games/binary/index.html

hex game https://studio.code.org/projects/applab/q5Mw0Zhs58a_Chr-zn75thpwnjMTw6n2hh_2aN1hwSE  Enter the hexadecimal value in the green box. If you see a hexadecimal number on the right, click the bits to make the binary number match.

ip subnet calculator
https://www.calculator.net/ip-subnet-calculator.html?cclass=any&csubnet=30&cip=192.168.1.1&ctype=ipv4&x=Calculate


https://www.reddit.com/r/computerscience/comments/uhappo/best_logic_gate_simulation_digital_logic_circuit/

https://github.com/hneemann/Digital   igital is an easy-to-use digital logic designer and circuit simulator designed for educational purposes. in java 

logigator https://logigator.com/en/community/project/8a738598-3e90-4be8-bd02-50e892f4c488  16-Bit General Purpose CPU.A somewhat better documentation can be found here: https://docs.google.com/spreadsheets/d/1MG44B5RzTul4EMDJowlx4hgNE3XYFRoyR7EFi6A0o3M/edit?usp=sharing

https://logigator.com/
https://www.youtube.com/watch?v=tX7HT_0MZRo  Logigator tutorial - The Editor 


doesnt work https://timesofindia.indiatimes.com/gadgets-news/how-to-use-your-android-phone-as-a-webcam-on-windows-11/articleshow/108155734.cms

github docs - https://docs.github.com/en/communities/documenting-your-project-with-wikis/about-wikis

github markdown cheatsheet https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet
Every repository on GitHub comes equipped with a section for hosting documentation, called a wiki. You can use your repository's wiki to share long-form content about your project, such as how to use it, how you designed it, or its core principles. A README file quickly tells what your project can do, while you can use a wiki to provide additional documentation. For more information, see "About READMEs."


really good raspberry pi connect – screen sharing
https://forums.raspberrypi.com/viewtopic.php?t=359880  Raspberry Pi OSCan't get wayland running on Pi3B+
To summarise, you can get it working by adding `wayland=on` to the end of the `/boot/firmware/cmdline.txt` file
This works to enable Wayland on my Raspberry Pi 2 :^)

https://connect.raspberrypi.com/devices  raspberry pi connect
https://www.raspberrypi.com/documentation/services/connect.html
https://www.raspberrypi.com/news/raspberry-pi-connect-remote-shell-access-and-support-for-older-devices/


eduroam pi
solent https://students.solent.ac.uk/studying/wireless-networks
https://www.southampton.ac.uk/isolutions/students/connecting-to-eduroam.page
eduroam assistant tool https://cat.eduroam.org/
eduroam-linux-SUS.py 

https://www.electronicshub.org/setup-wifi-raspberry-pi-2-using-usb-dongle/



https://forums.raspberrypi.com/viewtopic.php?t=359999  Official Docker images of Raspberry Pi OS?

https://github.com/dtcooper/raspberrypi-os-docker/tree/main  Raspberry Pi OS Docker Base Images 
https://hub.docker.com/r/balenalib/raspberry-pi  This image is part of the balena.io base image series for IoT devices.
https://github.com/balena-io-library

https://github.com/mrhavens/pidoc
An autoconfiguring stack to build simple, scalable, and fully binary ARM compatible Raspberry Pi clusters on Intel or AMD architecture.
https://gcore.com/learning/raspberry-pi-cluster-emulation-with-docker-compose/  Raspberry Pi Cluster Emulation With Docker Compose
https://itnext.io/raspberry-pi-cluster-emulation-with-docker-compose-2d5583cd645

balina based images qemu https://github.com/search?q=repo%3Abalena-io-library%2Fbase-images%20qemu&type=code


https://forums.raspberrypi.com/viewtopic.php?t=117790&sid=b22e4e41b8bed2d5706c784cdafb18d9  Using GPIO from Command Line (Shell)Mon Aug 10, 2015 12:53 pmHi,Thus far I have discovered 3 ways to access GPIO pins on Pi,a. Using the Python lib RPi.GPIOb. Using the C lib WiringPic. Using the command line

https://elinux.org/RPi_GPIO_Code_Samples  RPi GPIO Code Samples  REALLY GOOD

http://webiopi.trouch.com/   The Raspberry Pi Internet of Things Toolkit - Now in two flavorsCayenne - The Spicy one 
WEB API FOR PI


VERY GOOD https://www.youtube.com/watch?v=N_GleyvoS3I
CPUlator%20Tutorial


Arm Emulator https://cpulator.01xz.net/?sys=arm-de1soc
CPUlator includes a web interface to the GNU assembler (gas) running on the server. T

https://github.com/ascholerChemeketa/armTutorial  ARM Toutorial

ARM Assembly language processing http://www.mwftr.com/416F22/416F22_Chapter2_POST.pdf

https://github.com/priyyanshi/Grapher-VGA-Graphing-Calculator-

https://developer.arm.com/documentation/dui0802/b/A32-and-T32-Instructions/MOV-and-MVN


REally good https://computerscience.chemeketa.edu/armTutorial/index.html   This reader introduces the basics of ARM v7 assembly. The primary goal is to help students who already know how to program in a high level language learn about the form their programs take after compiling - the kinds of instructions a computer really processes information. These materials provide examples of basic ARM instructions, assembly programming constructs, and how high level languages constructs are represented in assembly.

https://kevinboone.me/pi-asm-00_introduction.html  ARM assembly-language programming for the Raspberry Pi

https://www.cl.cam.ac.uk/projects/raspberrypi/tutorials/os/ok01.html Department of Computer Science and Technology
The OK01 lesson contains an explanation about how to get started and teaches how to enable the 'OK' or 'ACT' LED on the Raspberry Pi board near the RCA and USB ports. This light was originally labelled OK but has been renamed to ACT on the revision 2 Raspberry Pi boards. 

https://www.cl.cam.ac.uk/projects/raspberrypi/tutorials/rpii/cintro.html   C.1 Introductions to C ProgrammingThis is a short and quick introduction to programming in C. This section is aimed at anybody who is interested new to programming and may wish to exploring the libRPii source files. The examples and exercise are designed to provide enough references and experience such that even complete beginners can still make the most out of the exploring libRPii tools. All of the source code examples (with prefix ExS.) can be found in the libRPii example source packages. See section GS.2 about how to get these resources. 


http://www.macs.hw.ac.uk/~hwloidl/Courses/F28HS/Essentials_C_v1.pdf   WELCOMETO LEARN TOCODE WITH C  on raspberry pi

https://personal.utdallas.edu/~pervin/RPiA/RPiA.pdf   RASPBERRY PI ASSEMBLER

submission 10th JAN AE1






https://www.halvorsen.blog/documents/programming/python/resources/Raspberry%20Pi%20and%20Python.pdf


https://github.com/ascholerChemeketa/armTutorial?tab=readme-ov-file

This is the source code for an interactive ARM v7 assembly tutorial. A live version of the tutorial can be found here: http://computerscience.chemeketa.edu/armTutorial/index.html

The goal of the tutorial is to understand assembly well enough to understand how high level code and data are implemented and develop familiarity with working with assembly and with binary representations of data.





