#include <iostream>
#include <easy2d/easy2d.h>
using namespace easy2d;

Scene* game;

void Ground() {
	auto ground1 = gcnew Sprite(L"res//Pic//ground.png");
	ground1->setPos(320, 410);
	game->addChild(ground1);
	auto ground2 = gcnew Sprite(L"res//Pic//ground.png");
	ground2->setPos(960, 410);
	game->addChild(ground2);
	auto moveBy = gcnew MoveBy(3, Vector2(-640, 0));
	auto tpBy = gcnew MoveBy(0, Vector2(640, 0));
	auto sequence = gcnew Sequence({ moveBy,tpBy });
	auto loop = gcnew Loop(sequence);
	auto loop2 = gcnew Loop(sequence);
	ground1->runAction(loop);
	ground2->runAction(loop2);
}

bool RunGame() {
	game = gcnew Scene;//新建场景
	SceneManager::enter(game);//进入场景
	
	auto rotateBy = gcnew RotateBy(1, 10);//创建旋转动画
	auto alwaysRB = gcnew Loop(rotateBy);//创建一直旋转动画

	auto gameBackGround = gcnew Sprite(L"res//Pic//B.png");//新建背景
	gameBackGround->runAction(alwaysRB);
	game->addChild(gameBackGround);//将背景添加到场景中
	gameBackGround->setPos(Window::getSize() / 2);//生成位置
	Ground();
	return true;
}
int main() {
	Logger::showConsole(1);//隐藏或显示控制台
	Renderer::showFps(1);
	Window::setIcon(100);

	MusicPlayer::preload(L"res//Mus//Aasee.wav");//预加载音乐
	
	if (Game::init(L"DUNKIRK", 640, 480)) {
		Node::setDefaultAnchor(0.5f, 0.5f);
		//以下是游戏代码

		auto scene = gcnew Scene;//新建场景
		auto background = gcnew Sprite(L"res//Pic//B.png");//新建背景
		background->setPos(Window::getSize() / 2);//生成位置
		background->setScale(1.0f, 1.0f);
		scene->addChild(background);//将背景添加到场景中
		SceneManager::enter(scene);//进入场景

		MusicPlayer::play(L"res//Mus//Aasee.wav", -1);//播放音乐
		auto startbutton = gcnew Button;//开始按钮
		startbutton->setAnchor(0.5f, 0.5f);//设置中心点
		startbutton->setNormal(gcnew Sprite(L"res//Pic//start1.png"));//常态
		startbutton->setSelected(gcnew Sprite(L"res//Pic//start2.png"));//选择时
		startbutton->setPos(Window::getWidth() / 2, Window::getHeight() - 150);//生成位置
		auto Pcallback = []() {
			RunGame();
		};
		startbutton->setClickFunc(Pcallback);//设置回调函数
		scene->addChild(startbutton);// 将按钮加入场景

		auto exitbutton = gcnew Button;//退出按钮
		exitbutton->setAnchor(0.5f, 0.5f);//设置中心点
		exitbutton->setNormal(gcnew Sprite(L"res//Pic//exit1.png"));//常态
		exitbutton->setSelected(gcnew Sprite(L"res//Pic//exit2.png"));//选择时
		exitbutton->setPos(Window::getWidth() / 2, Window::getHeight() - 50);//生成位置
		auto Ecallback = [](){
			Game::quit();
		};
		exitbutton->setClickFunc(Ecallback);//设置回调函数
		scene->addChild(exitbutton);// 将按钮加入场景

		auto starttext = gcnew Text(L"D U N K I R K");// 开始文本
		starttext->setAnchor(0.5f, 0.5f);// 设置中心点
		starttext->setPos(Window::getWidth() / 2, Window::getHeight() / 2 - 100);//设置位置
		auto font = Font(L"System", 72, Font::Weight::Bold, true);//创建字体
		auto fadeIn = gcnew FadeIn(2);//创建渐入动画
		starttext->setFont(font);//设置字体
		scene->addChild(starttext);// 将文字加入场景
		starttext->setOpacity(0);//将透明度设为0
		starttext->runAction(fadeIn);//执行渐入动画

		//以上是游戏代码
		Game::start();
	}
	Game::destroy();
	return 0;
}