import serial
import struct

import serial
import struct
import time

# Open the UART serial port (on the Raspberry Pi)
ser = serial.Serial(
    port='/dev/serial0',  # This is for GPIO 14 (TX) and GPIO 15 (RX)
    baudrate=115200,
    bytesize=serial.EIGHTBITS,
    parity=serial.PARITY_NONE,
    stopbits=serial.STOPBITS_ONE,
    timeout=1  # Timeout for reading (1 second)
)

print("Waiting for data...")

while True:
    # Check if data is available to read
    if ser.in_waiting > 0:
        # Read 4 bytes (size of uint32_t)
        data = ser.read(4)
        
        if len(data) == 4:
            # Convert the 4 bytes into a uint32_t (little-endian assumed)
            live_counter = struct.unpack('<I', data)[0]  # <I means unsigned int (32-bit)
            print(f"Received live_counter value: {live_counter}")
        else:
            print("Incomplete data received or error.")
    else:
        print("No data received yet...")
    
    # Optional: Sleep to avoid constant polling and reduce CPU usage
    time.sleep(0.1)