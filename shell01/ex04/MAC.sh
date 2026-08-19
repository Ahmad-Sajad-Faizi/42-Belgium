#!/bin/sh

ifconfig | grep -E 'ether |HWaddr' | awk '{print $NF}'

# ifconfig output contains MAC addresses after ether (Linux) or HWaddr (BSD)
# grep -E 'ether |HWaddr' picks the lines.
# awk '{print $NF}' prints the last field (the MAC)
# ifconfig | grep 'ether' | awk '{print $2}'
