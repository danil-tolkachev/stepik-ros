# 1. Введение

## 1.2 Nodes+Topics

```bash
roscore  # запуск ROS
rosrun turtlesim turtlesim_node  # gui с черепашкой
rosrun turtlesim turtlesim_node __name:=turtlesim_my # gui с черепашкой №2
rosrun turtlesim turtle_teleop_key  # управление
```
```bash
rosnode list  # список нод
rosnode info /teleop_turtle  # информация о ноде
rostopic list  # список топиков
rostopic info /turtle1/cmd_vel  # информация о топике
rosrun rqt_graph rqt_graph  # посмотреть граф
rosservice list  # список сервисов
rosservice info /clear  # информация о сервисе
rosservice call /clear  # вызов сервиса
rossrv show std_srvs/Empty  # информация о типе сервиса
rosservice call /turtle1/teleport_absolute <Tab> # вызов сервиса
```

## 1.3 
```bash
mkdir -p workspace/src
cd workspace/src
catkin_init_workspace
catkin_create_pkg hello_world
```
