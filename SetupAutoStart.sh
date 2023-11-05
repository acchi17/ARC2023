#!/bin/bash

systemctl stop arc2023
cp arc2023.service /etc/systemd/system/
systemctl daemon-reload
systemctl start arc2023.service
