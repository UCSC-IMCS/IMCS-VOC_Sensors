import serial

# Define the serial port and baud rate
serial_port = 'COM3'  # Change this to the appropriate serial port
baud_rate = 9600

# Open a serial connection
ser = serial.Serial(serial_port, baud_rate)

# Open a file to write the data
file_name = 'serial_data.txt'
file = open(file_name, 'w')

try:
    while True:
        # Read a line from the serial port
        line = ser.readline().decode('utf-8').strip()
        print(line)  # Print the line to the console
        
        # Write the line to the file
        file.write(line + '\n')
        
except KeyboardInterrupt:
    print('Keyboard Interrupt detected. Closing the serial connection and file.')
    ser.close()
    file.close()
