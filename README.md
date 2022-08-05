# MIT Racecar HDL Graph SLAM

### Seting Up the repository with Docker
```
docker pull vishrutk/rover_slam:latest
```
### Running the repository with Docker
```
docker run -it --net=host vishrutk/rover_slam:latest bash
```
### Inside the Docker Image
```
source /root/rover_slam/devel/setup.bash
roslaunch hdl_graph_slam rover.launch
```
