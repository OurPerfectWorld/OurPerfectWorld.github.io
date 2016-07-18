---
layout: post
title: "DragonBone 3.0 & Flash"
subtitle: " \"DragonBone 3.0\""
date: 2016-07-07 4:24:24
author: "Minato"
header-img: "img/post-bg-2015.jpg"
tags:
    - Dragonbone
    - Flash制作规范
---

## DragonBone和Flash制作模型的规范

<!-- create time: 2016-07-07 11:24:24  -->
-----

### DragonBone的简介


    DragonBones是一套开源的 2D骨骼动画框架和工具，它包含了基于Flash Pro的骨骼动画编辑面板DragonBonesDesignPanel及骨骼动画ActionScript框架。
    它可以让开发者运用熟悉的Flash Pro元件及时间轴编辑方式，快速创建2D骨骼动画，并运用到Flash或其他技术的应用中。

### Dragonbone的下载和安装设置
+ [开源项目地址][url7]
+ 必须使用**Adobe Flash Pro 5.5**或以上版本
+ 下载最新的**DragonBones release** 包，安装支持Flash Pro的骨骼面板扩展插件SkeletonDesignPanel.zxp （注：此插件目前仅支持Flash Pro5.5及以上版本）， 获取骨骼动画ActionScript库SkeletonAnimationLibrary。

### DragonBone在Flash上的使用
+ [制作参考][url8]

### 使用DB导出的Flash制作规范

* #### 图片资源的规范
    * 人物模型的图片目录名不能出现重复（应该与文件名一致）
    * 骨骼动画的图片必须包裹元件，元件是用图形元件
    * 原图片的引用次数不能超过1
    * 只有在使用混合模式的情况下才能使用影片剪辑，而且使用影片剪辑前，先和程序确认能否在软件中实现该效果    
    * ![][pic2]

* #### 模型的原点位置
    * 人物的脚的X,Y坐标应该在（0，0）

* #### 攻击帧事件
    * 关键帧命名：@gongji
    * ![][pic3]
    
* #### 关于武器
    * 同一职业的武器图尺寸要相同大小，并且武器的握柄位置要在同一水平线（建议同一职业用同一张武器图进行调动作）       
    * 出现第二个武器图层叫wuqi_shang
    * 武器的消失可以用透明关键帧的方式解决
    
* #### 关于动作
    * ##### 冲刺动作
        * 效果描述：制作一个向前冲的准备动作
        * 制作
            1. 当进入冲刺动作时，人物模型产生一定位移
            2. 在装备动作结束时，添加攻击的帧事件@gongji
            3. 该动作属于技能动作，会通过技能配置表配置位移的长度和时间，根据配置表表现冲刺效果
        * ![][pic5]
        * ![][pic6]
        
    * ##### 循环动作
        * 效果描述：一个唱歌的吟唱循环动作
        * 制作
            1. 循环动作的第一帧加入帧事件（@xunhuan）
            2. 程序通过检测该循环事件，让动作循环，循环的长度由模型配置表控制
            3. 循环动作相关的特效，特效单次循环的帧数需要比循环动作长一帧至少

* #### 关于特效
    * ##### 特效帧
        * 命名规范
            * @effect_fileName_actionName_depth
            * fileName对应特效的文件名，actionName对应特效的动作名
            * depth表示深度，在人物下方则是texiao_fileName_actionName_1，而texiao_fileName_actionName_2则表示在上方
        * 放置位置
            * 特效应该在特效层，特效层需要有图片不能空着（可放一个透明元件）
        * 注意问题
            * 在特效最后需要补上空白关键帧
        * 如图
            * ![][pic1]
        
    * ##### 普通技能和buff类型的特效
        * 普通需要单独做成个特效文件，该文件的命名应该和特效里面的动作命名保持一致，一个动作对应一个文件的形式
        * 特效文件一般就一个动作，特效名要跟文件名一致
        
    * ##### 远程类型的特效
        * 如果特效是静态图片，比如是刀光，在fla中必须添加空白帧，即最少必须有两帧
        
    * ##### 特效的制作
        * 在制作特效的时候是特效和动作一起制作的，所以他们共用一个fla
        * 最后要分别输出动作fla和特效fla交给程序，提取特效的时候必须把多余的空白帧删了，删除的部分如下图。        * 不删除会出现特效播放延迟或无法播放
        * ![][pic7]
        
* #### 关于高级效果
    * 在Cocos2d-x 3.2引擎中
        * 只有叠加和增加两个模式可以用，其他不行
        * 高级可以加色，但只能偏白图的加色


### 其他问题
* #### 人物模型跑位的问题
    * 现象
        * pic1
    * 解决方法
        * 采用连续关键帧解决
    * 参考图片
        * pic2
* #### 导出文件时错误1
    * ![][pic4]
    * 原因
        * 使用的图片中有分辨率过大的图片，导致打包图片时范围超出
* #### 导出文件时错误2
    * ![][pic8]
    * 原因
        * 使用的图片和元件中，图片的引用不能超过1（绿色图标的），不能出现图片有as连接的情况
        * 图片损坏和异常
        * ![][pic9]
* #### 导出文件时错误3
    * ![][pic10]
    * 原因
        * 帧事件的命名@gongji，没有加入@时出现的错误


[url1]:http://dragonbones.effecthub.com/getting_started_cn.html
[url2]:https://github.com/DragonBones/DragonBonesCPP
[url3]:https://github.com/DragonBones/DesignPanel
[url4]:http://www.litefeel.com/how-to-do-lua-bindings-for-dragonbones-vs/
[url5]:http://www.litefeel.com/how-to-do-lua-bindings-for-dragonbones-android/
[url6]:http://www.litefeel.com/how-to-use-dragonbones-in-lua/
[url7]:http://dragonbones.github.com
[url8]:http://dragonbones.github.io/getting_started_cn.html


[pic1]:../../../../img/post_db_flash/po1.png
[pic2]:../../../../img/post_db_flash/po2.png
[pic3]:../../../../img/post_db_flash/po3.png
[pic4]:../../../../img/post_db_flash/po4.png
[pic5]:../../../../img/post_db_flash/po5.png
[pic6]:../../../../img/post_db_flash/po6.png
[pic7]:../../../../img/post_db_flash/po7.png
[pic8]:../../../../img/post_db_flash/po8.png
[pic9]:../../../../img/post_db_flash/po9.png
[pic10]:../../../../img/post_db_flash/po10.png


----
Copyright 2016 WangLin



