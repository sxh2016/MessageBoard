# sunxiaohua
# Run with:     python msgclient.py

import socket
import sys
try:
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    if(len(sys.argv) != 4): print"Illegal input, please input like <ip> <name> <message>"
    hostname = sys.argv[1];
    #port = int(sys.argv[2]);
    name = sys.argv[2]
    message = sys.argv[3]
    s.connect((hostname,5555))
    s.send(name + " " + message)
    s.close();
    
except ValueError, e:
    print("Please enter the command again")
except socket.erroe as msg:
    s.close()
    s = None
print("Sent message to server!")

