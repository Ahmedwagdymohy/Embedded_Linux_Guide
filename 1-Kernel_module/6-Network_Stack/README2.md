Here's an updated version of the README file with the provided information, formatted and structured for clarity:

---

# Network Communication Overview

## What's a Network?
A network is a system that enables communication between two devices. The data exchanged between these devices is called `packets`.

## Communication Protocol
A communication protocol defines the rules and conventions for data exchange between devices. In this context, we'll focus on `SOME/IP`, a protocol commonly used in the automotive industry.

- **Remote Process Communication:** Communication between two machines.
- **Inter-Process Communication:** Communication between two processes on the same machine.

## Common Commands

- **`ifconfig`:** Configures network interfaces and brings interface cards up.
- **`ip`:** Displays routing, network devices, and interfaces.

Each network interface card (NIC) has a unique identifier called the `MAC address`.

![Network Interface Example](imageedit_2_5285483377.png)

## Ethernet Frame Stages
1. **Frame Reception:** When two NICs communicate, they exchange Ethernet frames. The receiving NIC checks if the destination address matches its own MAC address. If matched, it processes the data.
2. **Network Stack Layers:** The data then moves through the network stack layers.

![Network Stack Layers](image-1.png)

3. **Transport Layer:** Manages sockets and ports.

### Additional Tools
- **`ethtool`:** Checks the NIC for driver or hardware issues.
- **`ifconfig`:** Displays information like `MTU` (Maximum Transmission Unit), which defines the maximum size of packets that can be transmitted.

## Layered Protocols in Wireshark
The layers in Wireshark are ordered from the physical layer up to the application layer. The `ping` command can check connectivity between two devices. In Wireshark, this is associated with the `ICMP` protocol, which shows echo ping requests.

## Data Analysis Tools
- **`tcpdump`:** A command-line tool to capture frames and packets coming to the NIC. It saves the captured data in a file (e.g., `file.pcap`) for later analysis with tools like Wireshark.

## Network Communication Concepts

### Definition
Network communication involves two machines exchanging data, often using protocols like Ethernet or SOME/IP. Data must pass through the OSI model, a theoretical framework, or the TCP/IP model, which is practically implemented in the kernel.

### OSI and TCP/IP Models
- **OSI Model:** A conceptual model for understanding network interactions.
- **TCP/IP Model:** The practical implementation in systems, detailing protocols used at each layer.

### TCP/IP Layers and Protocols
1. **Application Layer:** Contains protocols for process-to-process communication.
2. **Transport Layer:** Manages data transfer between systems, using protocols like TCP or UDP.

### Ethernet Frame Structure
- **Source Address:** The MAC address of the sender's NIC.
- **Destination Address:** The MAC address of the receiver's NIC.

The frame progresses through various layers, each adding headers and processing data.

### Inter-Process Communication
Inter-process communication occurs when processes on the same machine exchange data, such as piping output from one program to another.

### SOME/IP Protocol
SOME/IP can be used for both external communication between machines and inter-process communication on the same machine.

## Useful Commands and Tools

1. **`ifconfig -a`:** Displays all network interfaces and their MAC addresses.
2. **`ethtool`:** Displays current NIC settings.
3. **`ping`:** Verifies connectivity between two IP addresses, utilizing the `ICMP` protocol.
4. **`tcpdump`:** Captures network traffic and saves it for analysis.

### NIC Information
- **MAC Address:** A unique identifier for each NIC, assigned at the factory.
- **IP Address:** Can be dynamically assigned by the router.

### NIC Status
- **Up:** The NIC is ready to transmit data.
- **Down:** The NIC is disabled and cannot transmit data.

The `mtu` (Maximum Transmission Unit) defines the largest packet size that can be transmitted over the NIC.

## Ping and ICMP Protocol
The `ping` command uses the `ICMP` protocol to check if two machines can communicate. It sends an echo request and listens for an echo reply, verifying connectivity.

## Capturing and Analyzing Traffic
For systems without GUI tools like Wireshark, `tcpdump` can capture network traffic. The captured data can be transferred to another system for analysis with Wireshark.

