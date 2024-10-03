# import serial
# import csv
# import time

# # Establish serial connection
# ser = serial.Serial('COM5', 9600)  # Change 'COM1' to match your serial port

# # Open CSV file for writing
# with open('sensor_data.csv', 'w', newline='') as csvfile:
#     writer = csv.writer(csvfile)
#     writer.writerow(['Timestamp', 'Sensor0', 'Sensor1', 'Sensor2'])  # Write header

#     # Read and write data indefinitely
#     try:
#         while True:
#             # Read data from serial port
#             line = ser.readline().decode().strip()
#             sensor_data = line.split()

#             # Get current timestamp
#             timestamp = time.strftime('%Y-%m-%d %H:%M:%S')

#             # Write data to CSV file
#             writer.writerow([timestamp, sensor_data[0], sensor_data[1], sensor_data[2]])
#             csvfile.flush()  # Ensure data is written immediately
#             print("Data written to CSV:", timestamp, sensor_data)

#     except KeyboardInterrupt:
#         print("Exiting...")
#         ser.close()  # Close serial connection when exiting


import serial
import csv
import time

# Establish serial connection
ser = serial.Serial('COM5', 9600)  # Change 'COM1' to match your serial port

# Open CSV file for writing
with open('sensor_data.csv', 'w', newline='') as csvfile:
    fieldnames = ['Timestamp', 'Sensor0', 'Sensor1', 'Sensor2']
    writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
    
    writer.writeheader()

    # Read and write data indefinitely
    try:
        while True:
            # Read data from serial port
            line = ser.readline().decode().strip()
            sensor_data = line.split()

            # Get current timestamp
            timestamp = time.strftime('%Y-%m-%d %H:%M:%S')

            # Write data to CSV file
            writer.writerow({'Timestamp': timestamp, 
                             'Sensor0': sensor_data[0], 
                             'Sensor1': sensor_data[1], 
                             'Sensor2': sensor_data[2]})
            csvfile.flush()  # Ensure data is written immediately
            print("Data written to CSV:", timestamp, sensor_data)

    except KeyboardInterrupt:
        print("Exiting...")
        ser.close()  # Close serial connection when exiting
