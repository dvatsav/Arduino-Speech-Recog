import bluetooth
import subprocess
target_name = "Vishaal Udandarao"
target_address = None
nearby_devices = bluetooth.discover_devices()
for i in nearby_devices:
    print(bluetooth.lookup_name(i))
#print(nearby_devices)
for bdaddr in nearby_devices:
    print (bdaddr)
    if target_name == bluetooth.lookup_name( bdaddr ):
    	print ("lol")
    	target_address = bdaddr
    	break
if target_address is not None:
    print("found target bluetooth device with address ", target_address)
    name = target_name     # Device name
    addr = target_address      # Device Address
    port = 1         # RFCOMM port
    passkey = "1234" # passkey of the device you want to connect
    
    # kill any "bluetooth-agent" process that is already running
    subprocess.call("kill -9 `pidof bluetooth-agent`",shell=True)
    
    # Start a new "bluetooth-agent" process where XXXX is the passkey
    status = subprocess.call("bluetooth-agent " + passkey + " &",shell=True)
    
    # Now, connect in the same way as always with PyBlueZ
    try:
        s = bluetooth.BluetoothSocket(bluetooth.RFCOMM)
        s.connect((addr,port))
    except bluetooth.btcommon.BluetoothError as err:
        # Error handler
        pass
    s.recv(1024)
    s.send("Hello World!")
else:
    print("could not find target bluetooth device nearby")

