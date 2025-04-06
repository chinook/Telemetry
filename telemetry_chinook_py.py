import serial
import struct

# Open the UART serial port
ser = serial.Serial(
    port="/dev/serial0",  # This is GPIO14/15 (TX/RX)
    baudrate=115200,
    bytesize=serial.EIGHTBITS,
    parity=serial.PARITY_NONE,
    stopbits=serial.STOPBITS_ONE,
    timeout=1  # 1 second timeout
)

print("Listening for uint32_t values...")

while True:
    # Wait until 4 bytes are available
    data = ser.read(4)
    
    if len(data) == 4:
        # Convert 4 bytes into uint32_t (little-endian assumed)
        value = struct.unpack('<I', data)[0]  # <I = little-endian unsigned int
        print("Received uint32_t:", value)
    else:
        print("Incomplete data received")