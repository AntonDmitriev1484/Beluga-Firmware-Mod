ros2 run beluga beluga \
	--ros-args \
	--param ranges_name:=uwb_ranges \
	--param exchange_name:=uwb_exchanges \
	--param port:=/dev/ttyACM0 \
	--param config:=/home/admi3ev/Beluga-2.0/ROS/config.json
