### Bring local area network (LAN) online via smartphone.
* I have a iPhone (any recent smartphone works) and a public SSH server
* Smartphone has a cellular data plan, a WiFi LAN, and SSH client (Termius on iOS)
### Plot
* I connect my phone to cellular network so it is on the internet.
* However, I must manually setup my WiFi network so my phone will connect to the WiFi router but not use it as the gateway. (Smartphone alway prefer WiFi as default gateway)
* My WiFi network settings only cover the right IP (say 192.168.1.222) and subnet mask so the smart phone is in LAN. 
* On smartphone, I can access the SSH server on the internet and LAN source at the same time.
* Connect to SSH server use software (Termius on iOS) and setup a dynamic port forwarding, which is listening on 192.168.1.222:8888
* Then other device in WiFi LAN can access internet via a sock port at 192.168.1.222:8888
*   
