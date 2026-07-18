# MSPM0G3507 MPU6050

## 功能

使用 I2C读取 MPU6050 六轴数据，并调用dmp读取四元数计算得到俯仰角，翻滚角，偏航角，数据显示在OLED屏幕上。



## 硬件

MCU:
MSPM0G3507

Sensor:
MPU6050



## 接线

MPU6050：
SCL -> PA31
SDA -> PA28

###### INT ->PB1



OLED:
SCL -> PB2
SDA -> PB3

## 测试结果

读取成功并显示:

ACC:
X Y Z

GYRO:
X Y Z

Pitch，Roll，Yaw

注：一开始Yaw会剧烈增长，约十秒后稳定下来进入正常状态。

## 开发环境

keil\_v5



TI MSPM0 SDK 2.10.00.04



sysconfig\_1.27.0



注：如果编译报错，大概率是SDK的路径没有重新配置成你自己的，具体方法参考嘉立创天猛星keil使用手册。

