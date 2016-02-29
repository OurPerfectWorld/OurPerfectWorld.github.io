---
layout: post
title: "Instrument & IOS & 性能优化"
subtitle: " \"Instrument的使用\""
date: 2014-12-26 10:42:42
author: "Minato"
header-img: "img/post-bg-2015.jpg"
tags:
    - Instrument 
    - IOS 
    - 性能优化
---

# Instrument的使用

<!-- create time: 2014-12-26 10:42:42  by wanglin -->

##How to use Time Profiler
###配置的设置
#####Hide Missing Symbols
	1. 隐藏没有符号的方法调用    
	2. xcode的build setting中可以设置Debug时的符号文件dSYM，有该文件才能看到函数名等数据信息，否则只显示为地址调用，对缺少符号文件的内容无查找意义；
#####Hide System Libraries
	隐藏系统相关的调用，一般稳定不存在问题
#####Invert Call Tree
	倒置函数的堆栈调用
#####Flatten Recursion
	将递归调用的方法显示成一次调用

###使用的方法
+ 通过暂停后点击模块的方式，测试打开模块需要的时间和函数调用分析   
+ 通过运行整段的战斗模块游戏过程，圈起有效范围内各调用在过程中占用的百分比；
+ 函数占用的时间较多时的方案考虑：     
  1. 设计上是否合理   
  2. 技术上考虑预加载，异步加载，图片缩小优化等
