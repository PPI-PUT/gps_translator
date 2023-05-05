# gps_translator
Simple message translator from gps_msgs to sensor_msgs.

## Installation
Clone the package to your ROS 2 workspace and build it uisng the colcon build system.
```bash
rosdep install --from-paths src --ignore-src -y

colcon build --symlink-install --cmake-args -DCMAKE_BUILD_TYPE=Release -DCMAKE_EXPORT_COMPILE_COMMANDS=On --packages-up-to gps_translator
```

## Usage
The package can be launched using command below.
```bash
ros2 launch gps_translator gps_translator.launch.py
```

## API

### Input

| Name         | Type                  | Description  |
| ------------ | --------------------- | ------------ |
| `/gps_top/gps` | gps_msgs::msg::GPSFix | Input topic before translation. Can be modified using parameters. |

### Output

| Name         | Type                  | Description  |
| ------------ | --------------------- | ------------ |
| `/gps_top/gps/translated` | sensor_msgs::msg::NavSatFix | Output topic after translation. Can be modified using parameters. |

### Parameters

| Name         | Type | Description  |
| ------------ | ---- | ------------ |
| `gps_sub_topic` | std_msgs::msg::String  | Name of the input topic to be translated. |
| `gps_pub_topic` | std_msgs::msg::String  | Name of the output topic after translation. |
