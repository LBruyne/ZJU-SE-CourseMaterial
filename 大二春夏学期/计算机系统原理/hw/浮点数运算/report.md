## 浮点数运算

- 程序介绍

  本次实验实现了要求的六个子程序。用户通过在控制台输入两个浮点数字符串，可以首先通过atof函数得到浮点数，然后进行四则运算，最后得到ftoa的结果。

  因为C语言内置有atof函数，这里我把名字改成了myAtof。



- 运算算法和证明

  - 基本程序结构

    ```c
    union fd;
    typedef union fd FloatUnion;
    typedef unsigned int word;	 //16-bit
    typedef unsigned long dwrd;	 //32-bit
    
    union fd{
        float f;
        dwrd d;c
    };
    
    char* ftoa(dwrd); 
    dwrd myAtof(char* str); 
    dwrd fadd(dwrd, dwrd); 
    dwrd fsub(dwrd, dwrd); 
    dwrd fmul(dwrd, dwrd); 
    dwrd fdiv(dwrd, dwrd);
    int isZero(dwrd);
    ```

    定义并利用联合体union储存数据。

  - fadd

    首先检测两个数字是否为0的情况。这一部分较容易处理。

    然后进行加法运算。首先要进行对阶进行处理，将指数较小的通过移位把指数变大，之后根据符号位的异或结果，将尾数相加或相减，如果相减，还要在小数减大数时，将符号位变号。另外，还需要检查是否为非规格化，以及是否为无穷和NaN。

    最后进行尾数规格化。首先检测尾数是否超过24位，如果超过24位，需要进行右规，由于右规会损失精度，所以采取舍0进1的舍入策略，当然，有些简单粗暴，以后优化。如果不足24位，进行左规。

  - fsub

    减法把减数的符号位取反，调用fadd再相加即可。

  - fmul

    先处理存在0的情况，直接返回0.

    然后指数相加，尾数进行无符号数乘法。计算结果的二进制位数，将它的移位到32+24=56位，之后再左规右规规格化，还是简单粗暴的0舍1入策略。

  - fdiv

    首先判断被除数与除数是否同时为0，如果同时为0则返回nan，如果被除数为0，返回0，如果除数为0，返回对应符号的无穷大。

    之后首先指数作差，尾数将被除数拓展为64位并左移32位做定点小数除法，由于是C语言模拟，可以使用恢复除数除法。然后对商移位成24位，然行规格化就运算完成了。



- 示例

  - Sample

    ![image-20200407002738494](C:\Users\Dell\AppData\Roaming\Typora\typora-user-images\image-20200407002738494.png)

    这里我们既显示了我们自己计算的结果，也显示了浮点计算的结果，进行对比，发现还是很准确的。

  - 大数

    ![image-20200407002908168](C:\Users\Dell\AppData\Roaming\Typora\typora-user-images\image-20200407002908168.png)

    大数据的计算结果较为准确

  - 小数

    ![image-20200407003013714](C:\Users\Dell\AppData\Roaming\Typora\typora-user-images\image-20200407003013714.png)

    可以看出这里的计算也较为准确。但是数字输入过于小的时候，会直接当作0进行处理，即把尾数忽略。

