#!/usr/bin/env bash

colcon clean packages -y
colcon build
source install/setup.bash
