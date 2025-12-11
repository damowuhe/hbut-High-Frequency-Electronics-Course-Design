#include "ao9833.h"

/*Author:   @朱一凡（damo）
 *time:     2025.12.11
 *version:  V1.0
 *library:  ad9833_moudle        */
 
//向AD9833写16位数据
//---------------------------------------------------//
void write_ad9833_d16(unsigned int data)
{
    uint8_t i;
    uint16_t write_data = (uint16_t)data;
    HAL_GPIO_WritePin(GPIOB, SCLK_Pin, GPIO_PIN_SET);
    HAL_GPIO_WritePin(GPIOB, FSYNC_Pin, GPIO_PIN_SET);
    HAL_Delay(1);
    HAL_GPIO_WritePin(GPIOB, FSYNC_Pin, GPIO_PIN_RESET);
    //写16位数据
    for(i=0;i<16;i++)
    {
    // 设置SDATA引脚电平（取当前最高位）
        if(write_data & 0x8000)  // 0x8000是16位数据的最高位掩码
        {
            HAL_GPIO_WritePin(GPIOB, SDATA_Pin, GPIO_PIN_SET);
        }
        else
        {
            HAL_GPIO_WritePin(GPIOB, SDATA_Pin, GPIO_PIN_RESET);
        }
        // SCLK产生下降沿+上升沿，锁存当前位数据
        HAL_GPIO_WritePin(GPIOB, SCLK_Pin, GPIO_PIN_RESET);
        HAL_Delay(1);  // 可选：延时保证时钟宽度（根据AD9833时钟频率调整，如无需可删）
        HAL_GPIO_WritePin(GPIOB, SCLK_Pin, GPIO_PIN_SET);
        HAL_Delay(1);  // 可选：延时保证时钟宽度

        // 数据左移，准备下一位
        write_data <<= 1;
    }
     HAL_GPIO_WritePin(GPIOB, FSYNC_Pin, GPIO_PIN_SET);
     HAL_GPIO_WritePin(GPIOB, SCLK_Pin, GPIO_PIN_RESET);
}

void ao9833_init(void)
{
    HAL_Delay(50);
    //寄存器频率0输出1KHz波形
    write_ad9833_d16(0x0100); //复位AD9833
    write_ad9833_d16(0x2100); //选择数据一次写入
    write_ad9833_d16(0x69F1); //L14
    write_ad9833_d16(0x4000); //H14 频率寄存器0为1KHz
    write_ad9833_d16(0x93E3); //L14
    write_ad9833_d16(0x8001); //H14 频率寄存器1为2KHz
    write_ad9833_d16(0x2000); //芯片进入工作状态,寄存器频率0输出1KHz波形
}

//寄存器频率1输出2KHz波形
void wave_out(void)
{
    HAL_Delay(50);
    write_ad9833_d16(0x2800);
}

//寄存器频率0输出1KHz三角波波形
void triangle_wave_out(void)
{
    HAL_Delay(50);
    write_ad9833_d16(0x2002);
}
//寄存器频率0输出1KHz方波波形
void square_wave_out(void)
{
    HAL_Delay(50);
    write_ad9833_d16(0x2020);
}


