# 📌📌 Basic Network Stack
## What's Network?
Network is the way how two devices are communicating, The data sent between the two devices are called `packets`

![alt text](image-5.png)


## Communication protocol:
It's the way that the two devices are using to communicate with each others, we will use `SomeIp` it's a protocol used in the automotive industry.
- **Remote Process Communication:** Communication between two machines.
- **Inter-Process Communication:** Communication between two processes on the same machine.


## Communication Types:
![alt text](image-8.png)

## TCP/IP Layers and Protocols
1. **Application Layer**
Communication Protocol installed over that layer to be communicated with:
`http` , `https`, `SOMEIP`, `ssh`.

2. **Transport Layer**
Communication Protocol installed over that layer to be communicated with:
`TCP`, `UDP`.

3. **Network Layer**
Communication Protocol installed over that layer to be communicated with:
`IP-protocol`.

4. **Network Access Layer**
Communication Protocol installed over that layer to be communicated with:
`Ethernet`, `Wifi`, `Bluetooth`.




## The Ethernet Frame stages:
1. When a two Network cards are communicating they send Ethernet frames to each ohters, The receiver one start By comparing the Destination address with it's own MacAdress,If matched it start analysing the data and take the subFrame to another stage.

![alt text](image-1.png)
<br>


2. Then the subFrame goes to the network stack Layes as shown in fig

![alt text](image-7.png)



## ❗ Useful Commands and Tools

1. **`ifconfig -a`:** Displays all network interfaces and their MAC addresses.
    
    - ***NIC Information***:
        - **MAC Address:** A unique identifier for each NIC, assigned at the factory.
        - ![alt text](imageedit_2_5285483377.png)
        - **IP Address:** Can be dynamically assigned by the router.

    - ***NIC Status***:

        - **Up:** The NIC is ready to transmit data.
        - **Down:** The NIC is disabled and cannot transmit data.
        - ![alt text](image-4.png)
        - The `enp4s0` ,`lo` (Virtual NIC) ,`wlp0s20f3` all of them are network interfaces cards.

    -   The `mtu` (Maximum Transmission Unit) defines the largest packet size that can be transmitted over the NIC.

2. **`ethtool`:** Displays current NIC settings.
3. **`ping`:** Verifies connectivity between two IP addresses, utilizing the `ICMP` protocol.
4. **`tcpdump`:** Captures network traffic and saves it for analysis.








## Wireshark
We are going to use the wireshark to analyse the data, The layers in the wireshark are ordered from the physical layer up to the application layer
![alt text](image-3.png)




## Ping and ICMP Protocol
The `ping` command uses the `ICMP` protocol to check if two machines can communicate. It sends an echo request and listens for an echo reply, verifying connectivity.

## Capturing and Analyzing Traffic
For systems without GUI tools like rasperryPi ,We Use `tcpdump` To capture network traffic and save it to file called pcap. The captured data can be transferred to another system for analysis with Wireshark.

---

# 📌📌 Advanced Network Stack
> In this part ana h3ml network so8aira a apply fiha el concepts ely 3arfinha 
### ⚙️ Create a simple Network
![alt text](image-9.png)
1. Identify Interface cards using `ifconfig -a`.
2. Connect Wirless/Wired to router (Sending Hidden Frame to the router to get the IP address) Using protocol called `DHCP -> Dynamic Host Configuration protocol`.
    - **DHCP**:
        - **Client:** Requests an IP address from the DHCP server.
        - **Server:** Assigns an IP address to the client.
        - **Router:** Manages the DHCP server.
    - To see the DHCPclient file go to ```/etc/dhcp/dhclient.conf```   
3. We have to configurations of the IP address:
    - **Static IP:** Manually assign an IP address to the interface *Which we are going to use*.
        - **Advantages:**
            - The IP address is always the same.
            - Easier to connect to the machine.
            - The assignation of it depends on the init process of the system you are using , in Out case we are using `systemd`. for more info -> [ ClickHere ](https://docs.google.com/document/d/1LoyayCG_EtRMXx-MLnoz4udPM-HQbzcM1bn-JBzJ5Ns/edit?usp=sharing)
    - **Dynamic IP:** Automatically assign an IP address using DHCP.

4. Assign static IP address.
5. Make sure that the machine is connected


---
### Inside the System-D :
- Network manager :
    - To show all the connections you did in the machine , use `nmcli connection show`
    - To show more details about the connections and from where this command get the data go to `etc/NeworkManager/system-connections/` *(law 3ayz tshof details aktar)*
    - To change the IP to be static use `nmcli connection modify <name of the connection> ipv4.method manual ipv4.addresses "IP address"` We use ipv4.method manual to make the IP static cuz it's dynamic by default ,also *Don't forget to restart the service using systemctl restart Networkmanager*. 

### Debugging Commands:
- **`ping`:** Check if the Other IP is working successfully and can recieve and send  .
- **`ip addr show`:** Displays the IP address of the network interfaces.
- **`ip route show`:** Displays the routing table.
- **`traceroute`:** Displays the path packets take to reach a destination.
- **`netstat`:** Displays network connections, routing tables, and interface statistics.
- **`ss`:** Displays socket statistics.
- **`arp`:** Displays the ARP cache.
- **`dig`:** Queries DNS servers.
- **`host`:** Resolves hostnames to IP addresses.
- **`nslookup`:** Queries DNS servers.
- **`ifconfig`:** Displays network interfaces and their configurations.
- **`iwconfig`:** Displays wireless network interfaces and their configurations.
- **`iwlist`:** Displays wireless network interfaces and their configurations.
- **`iw`:** Displays wireless network interfaces and their configurations.
- **`ethtool`:** Displays NIC settings.






