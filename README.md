* A simple IOT Network *

Description :
Client ( or Node ) will send data to Gateway . Gateway will recieve and send this data to server MQTT (MQTT protocol)
In this example i use 2 ESP32 to describe : 1 for cilent and 1 for Gateway. The Server MQTT I run in Raspberry PI 4 (4G)

* If this helpful , pls give me a star . Thank you *

-----------------------------------------------------------------------------------------------------------
SOME COMMON MISTAKE YOU MAY HAVE WHEN YOU DEPLOY THE SYSTEM
-----------------------------------------------------------------------------------------------------------
* With Raspberry PI 4 :

ssh: connect to host raspberrypi port 22: Connection timed out ( You can't connect SSH from your computer to raspberrypi 4 . Even
though it's working. You still can connect through VNC viewer )

- Open terminal in raspberry pi
- Type this command to open SSH :
sudo systemctl enable ssh
sudo systemctl start ssh
- Check the ssh status :
sudo systemctl status ssh

Step to install MQTT correctly on raspberry pi :
- Update your system :
sudo apt update
- Install Mosquitto broker and clients :
sudo apt install -y mosquitto mosquitto-clients
- Enable Mosquitto to start on boot :
sudo systemctl enable mosquitto
- Check status : sudo systemctl status mosquitto (You should see something like active (running))



