#!/bin/bash

# Stop and delete the service
cd /etc/systemd/system
systemctl stop arc2023.service
rm arc2023.service
systemctl daemon-reload

# Create the service unit file
touch arc2023.service
chmod 666 arc2023.service

echo "[Unit]" >> arc2023.service
echo "Description=ARC2023 app" >> arc2023.service
echo "After=multi-user.target" >> arc2023.service
echo "" >> arc2023.service
# Memo:
# multi-user.target is a unit that serves as the base for multi-user environments,
# and many services are associated with this target and started.

echo "[Service]" >> arc2023.service
echo "ExecStart=/usr/bin/python3 /home/pi/ARC2023/source/raspi3/app_main.py" >> arc2023.service
echo "Restart=always" >> arc2023.service
echo "RestartSec=5" >> arc2023.service
echo "" >> arc2023.service

echo "[Install]" >> arc2023.service
echo "WantedBy=multi-user.target" >> arc2023.service
# Memo:
# WantedBy specifies a unit that becomes dependencies on this unit 
# when automatic startup is enable with the systemctl enable command. 

# Enable and start the service
systemctl enable arc2023.service
systemctl start arc2023.service
