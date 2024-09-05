vnc with tight vnc on pi
https://forums.raspberrypi.com/viewtopic.php?t=176408
So I did an update today on my Pi 3 running Raspbian. 
Now when I try to connect to it using VNC from my PC, the VNC viewer goes "No matching security types". 
That's with RealVNC. I get the same error when running vncviewer in Solaris 10. 
If I try TightVNC on the PC, I get "No security types supported". 
Oddly enough, the VNC Viewer app for Android works fine

From there I opened the VNC server window. From there I went to the Options menu, 
set Authentication to "VNC password" and Encryption to "Prefer off". I then clicked OK and that was that. I can now log into the Pi using RealVNC and TightVNC from my PC's again.
