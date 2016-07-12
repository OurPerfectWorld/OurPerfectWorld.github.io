---
layout: post
title: "TestFlight的使用"
subtitle: " \"TestFlight 测试\""
date: 2016-07-11 10:24:38
author: "Minato"
header-img: "img/post-bg-2015.jpg"
tags:
    - Itunes Connect
    - TestFlight
---

## 如何使用 TestFlight 进行 Beta 测试

### 什么是TestFlight

* #### 简介
    * TestFlight是itunes connect中，用于测试和统计的工具，分为内部测试和外部测试

* #### 内部测试
    * 提供内容
        * 测试者的App账号加入到开发组中
    * 审核周期
        * 无需审核，提交后即可选择测试人员的账号进行测试
    * 测试操作
        * 通过TestFlight的App进行下载测试
    * 人员上限
        * 25个账号

* #### 外部测试
    * 提供内容
        * 提供邮箱给开发者
    * 审核周期
        * 正常情况一天
    * 测试操作
        * 通过TestFlight的App进行下载测试
    * 人员上限
        * 1000个邮箱账号

* #### 可以参考使用的测试方式
    1. 注册一个新的Apple账号，加入到开发账号组中，分配测试的职能
    2. 将测试的账号加入到内部测试，并进行测试通知
    3. 测试账号收到通知后第一次在**TestFlight**中，进行输入邮箱验证，就可以进行游戏下载测试
    4. 之后其他app的设备只需要在**TestFlight**中登陆该账号即可下载游戏
    5. 注意：使用**TestFlight**需要ios 8.1版本以上才能支持

* #### 好处
    * 使用外部测试**无需提供设备ID**，提供邮箱按照指引即可下载App进行测试

### 使用流程
* 注册一个开发者账号
* 进入[itunes Connect][url1]首页，进入**My Apps**
* 创建一个App，填写必要信息，关键是**Bundle ID**
* 确认好证书和**Bundle ID**，打出ipa包后，利用**Application Loader**进行上传
* 对上传好的App即可选择内部测试和外部测试，确认好信息后，测试用户会收到邮件
* 用户安装**TestFlight**的App后，输入邮件中提供的**Key**即可下载测试

### 测试的具体操作
* 根据**beta itunes**发的测试邮件，如图
    * ![][pic1]
* 根据指引操作
    * 下载**TestFlight**的App
    * 登陆Apple账号，第一次需要输入邮箱的验证码**key**，之后可以直接下载安装
* 注意
    * 一个账号可以进行多次下载



## 上传App过程中需要注意的地方
* ### 关于证书
    * #### 证书类型
        * dev:开发人员用，xcode在apple机器测试，用mac直接输出到手机用的证书
        * dist:正式使用的证书，提交到appstore上时设置的证书
        * xc:等完善

    * #### 上传iTunes connect时的证书使用
        * 在**Provisioning Profile**选择Dist类型的证书
        * 在**Code Signing Identity**选择Iphone Dist的人员证书
        * 证书选择错误，则上传App Store时，会出现“Invalid Provisioning Profile”的错误，如图
            * ![][pic2]

* ### 关于版本号
    * 版本号填写不规范则会出现以下错误
        * ![][pic3]
    * 后面每一次版本上传，版本号都要递增，否则上传失败
        * ![][pic4]

* ### 关于64位支持的问题
    * app中的Arm必须有arm64位支持
    * 支持64位的设置后，固件版本最低为iOS 5.1.1
    * 出现的错误
        * ![][pic5]
        * ![][pic6]


## 参考
* #### [TestFLight官方描述][url3]
* #### [iOS 平台如何使用 TestFlight 进行 Beta 测试][url2]





[pic1]:../../../../img/post_itunes/pic1.png
[pic2]:../../../../img/post_itunes/pic2.png
[pic3]:../../../../img/post_itunes/pic3.png
[pic4]:../../../../img/post_itunes/pic4.png
[pic5]:../../../../img/post_itunes/pic5.png
[pic6]:../../../../img/post_itunes/pic6.png



[url1]:https://itunesconnect.apple.com/
[url2]:https://blog.coding.net/blog/ios-testFlight
[url3]:https://developer.apple.com/testflight/

---

Copyright 2016 WangLin