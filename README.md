这是湖工大高频电子课设开源原理图以及ad9833模块的代码驱动库（stm32f1），作者用的是hal库，如果需要标准库需要自己移植
下面是原理图部分
<img width="1190" height="845" alt="SCH_MCU_1-P1_2025-12-11" src="https://github.com/user-attachments/assets/927a397c-6841-42dd-ba10-690d0dc96f5d" />
代码在上面的库里面 可直接下载
作者提供了2khz的基础代码 包括正弦波，三角波，方波等等，也可以不使用该模块，
而改用dac或者用定时器pwm二阶滤波之后傅里叶变换得到直流分量(dac)也可以得到这些波形。
不过作者只用过cw32构建过，stm32需要各位自己尝试。
下面是ad9833模块驱动，供各位参考
<img width="899" height="791" alt="image" src="https://github.com/user-attachments/assets/c0f13db3-133e-480c-bf4a-272fde33c27a" />
<img width="837" height="764" alt="image" src="https://github.com/user-attachments/assets/187f03f8-ae38-436f-901e-28dee7b7af66" />
