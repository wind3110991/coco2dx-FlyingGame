# coco2dx-FlyingGame
My BigProject before vacation，a small game of airplane
##一个基于cocos2dx 3.6的飞行式跑酷小游戏，用c++实现

###开发环境：
集成于 Xcode 6.1
Mac OS 10.10 Yotemise

###开发语言
c++

游戏名称	
<< Look ! Airplane >>

美工：me myself
程序：me myself
设计：me myself


一．游戏概要
《Look！Airplane》是一款基于cocos-2dx引擎的横版过关游戏。
游戏的设定相当简单，玩家通过控制飞机在空中不断飞行来躲过地图中的怪物，并且飞机一定程度会自由落体。玩家不仅要想方法躲过怪物，还要想方法控制飞机不落地。游戏整体风格很萌，有较强的可玩性。

二．开发环境
    1.开发框架：cocos-2dx 3.6

2.开发语言：c++

3.开发环境：Mac OS 10.10 

4.编译环境：Xcode 6.1.1
    
5.模拟器：Mac模拟器

6.版本控制：github for Mac


三．开发流程
    1.开发周期：10天

    2.开发具体流程：（见github log信息）：
 
 



四．游戏类设计
1.GameScene
 
（1）GameLoadingScene类
 GameLoadingScene类用来生成进入游戏前的加载场景，预加载游戏音乐和音效，缓冲用户数据等。
 

（2）WelcomeScene类
 WelcomeScene类用来承载WelcomeLayer，生成游戏欢迎界面，场景中三个可供用户选择按钮，开始游戏、帮助或关于按钮。
 
（3）GameScene类
GameScene类是进行游戏的主要类，创建一个带有物理引擎的物理世界。
在开始游戏后，WelcomeScene切换到GameScene。GameScene类初始化的时候生成GameLayer、GameBackgroundLayer、GameOptionLayer和GameStatusLayer四个最重要的Layer，并在GameLayer、GameOptionLayer和GameStatusLayer三个类之间生成delegate委托，场景准备好所有与游戏有关的数据后游戏开始运行，直到用户退出游戏。
 

















2.GameLayer
 


（1）GameLayer类
GameLayer类是进行游戏的主要类。
在开始游戏后，GameLayer中生成GameAirplaneObj对象，也就是游戏的主角，其物理世界是GameScene场景的物理世界。并用来监听物理碰撞和用户点击事件。对应类中的gameStatus，判断游戏的进行状态。处理游戏的暂停状态，pause后关闭物理世界重力效果，恢复后resume。左上角显示用户目前的得分。在游戏结束后，若用户的得分超越最高分，并会刷新纪录提示。
  
（2）GameBackgroundLayer类
GameBackgroundLayer类用来加载背景图片，并实现背景的无限滚动效果，并承载怪物类的实例随机生成。实现随时间迁移滚动速度不断上升，使游戏产生“随时间迁移飞机速度变快”的感觉。

（3）GameStatusLayer类
GameStatusLayer类主要处理游戏的状态。
监听游戏目前的进行状态，在游戏结束后，加载重新开始按钮，使游戏重新开始，切换场景工作。

（4）GameOptionLayer类
     GameOptionLayer类负责处理点击事件，并响应点击事件的类型和操作。

（5）WelcomeLayer类
WelcomeLayer类生成欢迎界面，三个按钮以及对应按钮的触发事件。

（6）HelpLayer类
HelpLayer类生成帮助界面。
 

（7）AboutLayer类
AboutLayer类生成关于界面。
 



















3.GameObj
 

（1）GameMonsterObj类
抽象类，抽象游戏中的三种敌人类。

（2）GameAirplaneObj类
用来封装飞机的类，绘制飞机的帧动画，设定其物理特性，设置碰撞类型，初始位置，封装飞机的跳跃动作和正常状态。
 
（3）RocketMonsterObj类
用来封装火箭敌人的类，设置其贝塞尔曲线运动，设定其物理特性，设置碰撞类型，初始位置。
                           

（3）AircraftMonsterObj类
     用来封装飞碟敌人的类，设置其往返运动，设定其物理特性，设置碰撞类型，初始位置。
                     

（4）BirdMonsterObj类
     用来封装猫头鹰敌人的类，设定其物理特性，设置碰撞类型，初始位置。

 



