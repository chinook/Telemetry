import serial

# Open the serial port (replace ttyAMA0 with the correct port if needed)
ser = serial.Serial('/dev/ttyAMA0', 115200, timeout=1)

while True:
    if ser.in_waiting > 0:
        data = ser.read(4)  # Read 4 bytes of data (adjust this based on your expected data)
        print(f"Received data: {data}")


"""
import serial
import struct
import time

def open_serial():
    #Attempts to open the serial port with retry logic.
    while True:
        try:
            # Attempt to open the serial port
            ser = serial.Serial(
                port='/dev/ttyAMA0',  # Change if necessary
                baudrate=115200,
                bytesize=serial.EIGHTBITS,
                parity=serial.PARITY_NONE,
                stopbits=serial.STOPBITS_ONE,
                timeout=1  # Timeout for reading (1 second)
            )
            print("Serial port opened successfully.")
            return ser
        except serial.SerialException:
            print("Serial port not available. Retrying in 3 seconds...")
            time.sleep(3)

# Open the UART serial port
ser = open_serial()

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
    time.sleep(0.1)"
"""