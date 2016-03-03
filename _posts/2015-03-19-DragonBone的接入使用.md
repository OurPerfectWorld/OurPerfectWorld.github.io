---
layout:     post
title:      "DragonBone 3.0 & Cocos2d-X"
subtitle:   " \"DragonBone 3.0\""
date:       2015-03-19 20:54:24
author:     "Minato"
header-img: "img/post-bg-2015.jpg"
tags:
    - Cocos2d-x
---

# DragonBone 3.0 的接入使用

<!-- create time: 2015-03-19 20:54:24  -->
-----

## DragonBone的简介


        DragonBones是一套开源的 2D骨骼动画框架和工具，它包含了基于Flash Pro的骨骼动画编辑面板DragonBonesDesignPanel及骨骼动画ActionScript框架。
        它可以让开发者运用熟悉的Flash Pro元件及时间轴编辑方式，快速创建2D骨骼动画，并运用到Flash或其他技术的应用中。

## Dragonbone的下载和安装设置
+ [开源项目地址][url7]
+ 必须使用Adobe Flash Pro 5.5或以上版本
+ 下载最新的DragonBones release 包，安装支持Flash Pro的骨骼面板扩展插件SkeletonDesignPanel.zxp （注：此插件目前仅支持Flash Pro5.5及以上版本）， 获取骨骼动画ActionScript库SkeletonAnimationLibrary。

## DragonBone在Flash上的使用
+ [制作参考][url8]

## DragonBone在代码上的使用（主要在Cocos2dx中的使用）
+ 加载导出资源

        local factory = db.DBCCFactory:getInstance()
    	factory:loadDragonBonesData("assets/skeleton.xml", "smithy_effect_2")
    	factory:loadTextureAtlas("assets/texture.xml", "smithy_effect_2")

+ 创建动画对象并进行播放

        local dbnode = factory:buildArmatureNode("smithy_effect_2")        
        dbnode:getAnimation():gotoAndPlay("f",-1,-1,0)

+ 播放动作的函数解析说明

        gotoAndPlay(    
            const std::string &animationName,
            float fadeInTime = -1.f,
            float duration = -1.f,
            int playTimes = -1,
            int layer = 0,
            const std::string &group = "",
            AnimationFadeOutMode fadeOutMode =  AnimationFadeOutMode::SAME_LAYER_AND_GROUP,
            bool pauseFadeOut = true,
            bool pauseFadeIn = true
        );
        默认参数为-1，表示根据flash中制作的参数进行播放
        playTimes为0时表示循环播放

+ 帧事件的注册和触发

        dbnode:registerFrameEventHandler(function (event)
    		-- body
        		print("帧事件参数列表")
    		print(event.armature)
    		print(event.armatureNode)
    		print(event.type)             对应于dragonbones::EventData::EventType
    		print(event.boneName)         图层名
    		print(event.animationName)    动作名
    		print(event.frameLabel)
    		print(event.isLastAnimation)       
        end)

+ 完成事件的注册和触发，也叫动画事件

        dbnode:registerAnimationEventHandler(function (event)
    		-- body
    		print("完成事件参数列表")
    		print(event.armature)
    		print(event.armatureNode)
    		print(event.type)
    		print(event.animationName)
    		print(event.isLastAnimation)
        end)
        
+ 更换骨骼图层

        local bone = dbnode:getCCSlot(boneName)
        if not bone then
            return
        end
        local displayNode = bone:getCCDisplay()
        if not displayNode then
            return
        end
        local resourePath = ResConfig.getPathByPng(resoureName)
        if not resourePath then
            print("没有找到资源",resoureName)
            return
        end

        --设置新资源
        local resourcePng = cc.Sprite:create(resourePath)
        local oldResPos = displayNode:getPosition()
        local oldResApos = displayNode:getAnchorPoint()
        resourcePng:setPosition(oldResPos)
        resourcePng:setAnchorPoint(oldResApos)
        --更换资源
        bone:setDisplayImage(resourcePng)   

+ 特效表现，xml文件中对应的blendMode字段
    - 拥有叠加和增加效果、高级效果
        
            在 XMLDataParser::parseSlotData 中对xml的数据进行解析
            在 DBCCSlot::updateDisplayBlendMode 中对模式进行渲染

+ Lua接口绑定的问题
    - 需要开启 DRAGON_BONES_ENABLE_LUA 的宏才能对帧事件和完成事件的回调进行注册
    
## DragonBone的优点
- 跟Cocostudio相比，美术人员的上手成本低，Flash的制作方式+dragonbone的导出面板即可完成
- 增加美术人员的开发效率，自转和弧形移动不需要使用密集关键帧来解决
- 增加美术的表现
    + 和低版本的Dragonbone相比，3.0版本可以使用元件套元件的movieClip来表现
    + 做人物动作时，各动作间形成自动补间动画，可以更细腻表现
    
## Dragonbone的缺点
- 依赖于Flash，Flash制作上存在的缺点和局限都会直接影响Dragonbone的效果
- Flash的制作上，特效表现的图片位移大时，导出的Dragonbone的自动补间处理可能会导致错位。解决办法一种是修改表现，一种是打关键帧，并且需要修改Dragonbone的源码，取消相邻两帧是关键帧时不做自动补间的处理
- Flash使用的混合模式，部分Dragonbone不支持，影响一定的特效表现

## 注意事项
+ Dragonbone的setRenderMode需要重写才有效果
+ 使用movieClip进行循环播放时，不会触发完成事件
+ 人物模型的帧事件触发特效文件时，会出现第一次播放走位的问题，需要在fla中设定帧事件在动作第一帧存在，但到需要播放时才出现，或者修改Bone.cpp的代码，在帧事件传位置出来时，调用位置更新的方法，如图[!pic]
+ 模型在完成事件中调用stop时，会停在fla的第一帧上
+ dragonbone仍然会出现边间位置的错误性，需要修改代码

## DragonBone参考
* [DragonBone的入门介绍][url1]
* [DragonBone的库和demo][url2]
* [对应的Flash导出插件][url3]
* [库工程加入到Cocos2d及Lua接口绑定][url4]
* [DragonBone在Android接口上的绑定][url5]
* [Lua上对DragonBone的接口调用][url6]

[url1]:http://dragonbones.effecthub.com/getting_started_cn.html
[url2]:https://github.com/DragonBones/DragonBonesCPP
[url3]:https://github.com/DragonBones/DesignPanel
[url4]:http://www.litefeel.com/how-to-do-lua-bindings-for-dragonbones-vs/
[url5]:http://www.litefeel.com/how-to-do-lua-bindings-for-dragonbones-android/
[url6]:http://www.litefeel.com/how-to-use-dragonbones-in-lua/
[url7]:http://dragonbones.github.com
[url8]:http://dragonbones.github.io/getting_started_cn.html


[pic]:d_p1

----
Copyright 2015 WangLin



