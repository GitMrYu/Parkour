#include <iostream>
#include <easy2d/easy2d.h>
using namespace easy2d;

Scene* scene;

void EnterScene() {
	scene = gcnew Scene;//新建场景
	auto background = gcnew Sprite(L"res//Pic//B.png");//新建背景
	background->setPos(Window::getSize() / 2);//生成位置
	background->setScale(1.0f, 1.0f);
	scene->addChild(background);//将背景添加到场景中
	SceneManager::enter(scene);//进入场景
}
bool game() {
	auto game = gcnew Scene;//新建场景
	SceneManager::enter(game);//进入场景
	auto gameBackGround = gcnew Sprite(L"res//Pic//B.png");//新建背景
	scene->addChild(gameBackGround);//将背景添加到场景中
	gameBackGround->setPos(Window::getSize() / 2);//生成位置

	auto ground1 = gcnew Sprite(L"res//Pic//ground.png");
	scene->addChild(ground1);
	return true;
}
int main() {
	MusicPlayer::preload(L"res//Mus//Aasee.wav");//预加载音乐

	Logger::showConsole(1);//隐藏控制台
	
	if (Game::init(L"DUNKIRK", 640, 480)) {
		Node::setDefaultAnchor(0.5f, 0.5f);
		//以下是游戏代码
		EnterScene();
		MusicPlayer::play(L"res//Mus//Aasee.wav", -1);//播放音乐
		auto startbutton = gcnew Button;//开始按钮
		startbutton->setAnchor(0.5f, 0.5f);//设置中心点
		startbutton->setNormal(gcnew Sprite(L"res//Pic//start1.png"));//常态
		startbutton->setSelected(gcnew Sprite(L"res//Pic//start2.png"));//选择时
		startbutton->setPos(Window::getWidth() / 2, Window::getHeight() - 150);//生成位置
		auto Pcallback = []() {
			game();
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
