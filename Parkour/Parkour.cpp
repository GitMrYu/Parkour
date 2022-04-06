#include <iostream>
#include <easy2d/easy2d.h>
using namespace easy2d;
Scene* scene;
void EnterScene() {
	scene = gcnew Scene;//新建场景
	auto background = gcnew Sprite(L"pic//B.png");//新建背景
	background->setPos(Window::getSize() / 2);//生成位置
	background->setScale(1.0f, 1.0f);
	scene->addChild(background);//将背景添加到场景中
	SceneManager::enter(scene);//进入场景
}
void button() {
	auto startbutton = gcnew Button;//开始按钮
	startbutton->setNormal(gcnew Sprite(L"pic//start1.png"));//常态
	startbutton->setSelected(gcnew Sprite(L"pic//start2.png"));//选择时
	startbutton->setPos(Window::getWidth() / 2, Window::getHeight() - 80);//生成位置
	scene->addChild(startbutton);//将按钮加入场景
}
int main() {
	Logger::showConsole(false);//隐藏控制台
	if (Game::init(L"GAME", 640, 480)) {
		std::cout << " Initialize the success!" << std::endl;
		Node::setDefaultAnchor(0.5f, 0.5f);
		EnterScene();
		button();
		//以下是游戏代码
		
		//以上是游戏代码
		Game::start();
	}
	Game::destroy();
	return 0;
}
