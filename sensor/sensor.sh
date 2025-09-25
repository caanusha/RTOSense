#!/bin/bash
USB_DEV="/dev/ttyUSB0"

if [ ! -e "$USB_DEV" ]; then
    echo "Error: $USB_DEV does not exist!"
    exit 1
fi

# Open USB device once
exec 3> "$USB_DEV"

while true; do
    LAT=$(echo "scale=6; 12.97 + $RANDOM/10000" | bc)
    LON=$(echo "scale=6; 77.59 + $RANDOM/10000" | bc)
    MSG="{\"lat\":$LAT,\"lon\":$LON}"
    echo "$MSG" >&3
    echo "Sent: $MSG"
    sleep 10
done
