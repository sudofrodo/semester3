#!/usr/bin/python3
import socket
import subprocess
from time import sleep

# Socket configuration
SOCKET_PATH = "/tmp/probook-socket"

def get_temp():
    """Reads CPU temp via sensors."""
    try:
        out = subprocess.check_output("sensors", shell=True).decode()
        for line in out.splitlines():
            if "Package id 0" in line or "Physical id 0" in line:
                # Extract digits between '+' and '.'
                return int(line.split('+')[1].split('.')[0])
    except:
        return 50 # Default safe value
    return 50

def send_cmd(cmd):
    """Sends command to unix socket."""
    try:
        with socket.socket(socket.AF_UNIX, socket.SOCK_DGRAM) as s:
            s.sendto(cmd.encode(), SOCKET_PATH)
    except Exception as e:
        print(f"Socket Error: {e}")

# Thresholds (temp, hex_speed)
LEVELS = [
    (95, 0x00), (90, 0x19), (85, 0x29), (80, 0x39),
    (75, 0x49), (70, 0x59), (65, 0x70), (60, 0x80)
]

while True:
    temp = get_temp()
    speed = 0xFF # Default off

    # Determine speed based on highest threshold
    for threshold, val in LEVELS:
        if temp > threshold:
            speed = val
            break

    if speed == 0xFF:
        send_cmd("fanoff")
        print(f"Temp: {temp}°C | Fan: OFF")
    else:
        msg = f"setfan 0x{speed:02x}"
        send_cmd(msg)
        print(f"Temp: {temp}°C | Fan: {msg}")

    sleep(1)
