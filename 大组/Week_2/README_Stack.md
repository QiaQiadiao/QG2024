# README_Stack

- 本程序仅支持**个位整数的简单四则运算**。（刚开始设计时，没考虑到字符串用来保存运算式的缺点，写到后边才发现问题了...可惜为时已晚，来不及大修了:(  ）同时由于char类型数据的特点，不能计算过大的数字。
- 程序主要由三个模块组成，第一个就是输入中缀表达式，第二个看计算结果，第三清除表达式，用于再次进行输入计算。

- 在输入表达式时，用英文输入法，不用打空格。
- 如果中缀表达式输入错了，那就再重新输入吧，不知道怎么判断中缀表达式是否标准.....