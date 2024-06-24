import serial
import csv
import time

# Establish serial connection
ser = serial.Serial('COM8', 115200)  

# Open CSV file for writing
with open('sensor_data.csv', 'w', newline='', encoding='utf-8') as csvfile:
    fieldnames = ['Timestamp', 'mq2', 'mq3', 'mq5', 'mq6', 'mq8', 'mq9', 'mics_Vred', 'mics_Vnox','mq214']
    writer = csv.DictWriter(csvfile, fieldnames=fieldnames)
    
    writer.writeheader()

    # Read and write data indefinitely
    try:
        while True:
            # Read data from serial port
            line = ser.readline().decode('utf-8').strip()
            sensor_data = line.split()

            # Get current timestamp
            timestamp = time.strftime('%Y-%m-%d %H:%M:%S')

            # Write data to CSV file
            writer.writerow({'Timestamp': timestamp,
                             'mq2': sensor_data[0].replace(',', ''), # Use correct keys
                             'mq3': sensor_data[1].replace(',', ''),  
                             'mq5': sensor_data[2].replace(',', ''),
                             'mq6': sensor_data[3].replace(',', ''),
                             'mq8': sensor_data[4].replace(',', ''),
                             'mq9': sensor_data[5].replace(',', ''),
                             'mics_Vred': sensor_data[6].replace(',', ''),
                             'mics_Vnox': sensor_data[7].replace(',', ''),
                             'mq214': sensor_data[8]
                            })
            csvfile.flush()  # Ensure data is written immediately

            # Print data to console
            print("Data written to CSV:", timestamp, sensor_data)

    except KeyboardInterrupt:
        print("Exiting...")
        ser.close()  # Close serial connection when exiting
