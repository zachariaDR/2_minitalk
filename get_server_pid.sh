#!/bin/bash

echo "$(ps)" | grep -w "./server" | tr -s ' ' | cut -d ' ' -f 1 | tr '\n' ' ' | cut -d ' ' -f 1
