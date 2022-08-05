FROM arm64v8/ros:noetic

RUN apt-get update && apt-get install -y --no-install-recommends \
  && apt-get install -y --no-install-recommends \
  libgtest-dev libopencv-dev python3-opencv libomp-dev \
  wget nano build-essential libomp-dev lld git \
  ros-noetic-robot-state-publisher \
  ros-noetic-geodesy ros-noetic-pcl-ros ros-noetic-nmea-msgs ros-noetic-eigen-conversions \
  ros-noetic-rviz ros-noetic-tf-conversions ros-noetic-libg2o \
  && apt-get clean \
  && rm -rf /var/lib/apt/lists/*

# RUN mkdir -p /root/catkin_ws/src
WORKDIR /root
# RUN /bin/bash -c '. /opt/ros/noetic/setup.bash; catkin_init_workspace'
RUN git clone https://github.com/vishrutskaushik/rover_slam.git

WORKDIR /root/rover_slam
RUN /bin/bash -c '. /opt/ros/noetic/setup.bash; catkin_make'

WORKDIR /

# ENTRYPOINT ["/root/rover_slam/src/ros_entrypoint.sh"]
CMD ["bash"]
