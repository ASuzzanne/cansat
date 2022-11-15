# CANSAT


## Table of Content
* [About us](#About-us)
* [INTRODUCTION](#INTRODUCTION)
* [POWER SYSTEM](#POWER-SYSTEM)
* [GROUND STATION](#GROUND-STATION)
* [TECHNOLOGIES](#TECHNOLOGIES)









# About us
We are the team AATHREYA from Anurag University ,
Hyderabad , Telangana , INDIA . Our motto is to build a CANSAT with the
objectives given by WCRC SERBIA . We are a batch of 5 members who are
specialized in various departments .
Sakshi venepally : Works on parachute design .
Vinushna lakkakula : Works on building Can .
Aamena Suzzanne : Works on Ground station .
Saripalli Shelsi : Works on Ground station .
Ramya Jakka : Works on payload , EPS , Communication .
The team Aathreya have started working on this project since one month in our
college . We have undergone many testings on various aspects and came up with
many innovative ideas . Our outreach for this project has gone through many
decisions and considerations of our team . On 25-09-2022 Aathreya was launched
by a rocket to an altitude of approximately 500m. During the descent the CANSAT
measures the required parameters and gives the data . This phenomenon was
carried away by the team Aathreya with many no.of trails. The team was
succeded in implementing the launch precisely .

# INTRODUCTION
 The main objective of the cansat is that using all the required
subsystems , the limitations made by wcrc must be satisfied . Therefore the
primary mission of the Aathreya’s cansat is that , as the cansat when inserted in
the sounding rocket and launched and deployed after reaching an altitude of
500m , the cansat descents and needs to measure the air pollution . Where as the
secondary mission is that when we send an uplink command to the can while
descenting it must be able to deploy unwanted antennas or the national flag etc.
these were the two main objectives of the cansat .
First of all looking into the primary mission while the can is being descented the
sensors integrated on the pcb calculate the data of air pollution which calculates
the air quality index and also some other parameters such as humidity and
temperature etc. And coming into the secondary mission the pcb is mounted with
the servo meter to implement it for deploying unwanted cloth piece etc. While
descenting down the can must be able to read the real time data and analyse the
data for every two seconds and transmit to the ground station .


# POWER SYSTEM 
The Arduino nano and all the other components except the LoRa Ra – 02 RF
module works on 5V where as the LoRa works on 3.3V . Hence the power supply
from battery was first given to boost and buck converters through battery to all
the components in order to operate in the acceptable ranges . The serial protocol
was given to all the components with the selected interfaces which operate in the
required ranges .
MQ7 – Measures the carbon monoxide CO .
MQ 135 – Measures the air quality .
DHT 11 – Measures the humidity and temperature .
LoRa Ra – 02 – Transmits and receives the data while descenting in the longer
distances

# GROUND STATION 
The main purpose of Ground-Station software is to visualize and observe how the
sensors’ values are changing in real-time, during descend of CanSat. Previously,
freeware – Terminal software tool was used to display and log the received
data. But it was difficult to visualize and observe the sensors’ values from the
string of data. Thus, the authors decided to develop a new software tool for
ground-station, under the guidance of ORION Space. The aim of the new
software tool at the ground station is to give real-time visualization of sensors’
data in graphical and tabular manner in human readable format, and log those
data in the ground-station computer.
GROUND STATION HARDWARE COMPONENTS
The radio communication board in the Ground-Station consists of an lora Ra-02
RF receiver module. It receives the data sent by Ra-02 RF transmitter module
connected with an On-Board Computer (OBC) in the Cansat. Ra-02 RF receiver is
connected to a Personal Computer via Universal Serial Port (USB). Ra-02 RF
receiver board communicates with computer serially. The data is received by the
Ground Station software as a string.
# TECHNOLOGIES 
Project is created with:
• numpy==1.22.4
• matplotlib
• json==3.1
• pandas os
• pyserial==3.5
How does it work?How does it sample?
Every 500 ms takes a sample, this number comes from the data rate that the
Arduino has if you don't have the Arduino and Sensors, the GUI still works, it
graphs random data . Every 2 sec it recieves the data, this number comes from
the data rate that the Arduino has if you don't have the Arduino and Sensors, the
GUI still works, it graphs random data .
What values uses?
The update() function updates the graphics and text of the interface. The first
thing it does is get a list of the information to be updated, this list is noted as
a The values it receives are: 0. Logging time
• height
• altitude
• Temperature
• Atmospheric pressure
• Load
The information which is been received from the receiver will be automatically
stored in a csv file .as we have return the code the main loop which is used to
store the information .
