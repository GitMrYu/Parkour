#include <iostream>
#include <easy2d/easy2d.h>
using namespace easy2d;
Scene* scene;
void EnterScene() {
	scene = gcnew Scene;//�½�����
	auto background = gcnew Sprite(L"pic//B.png");//�½�����
	background->setPos(Window::getSize() / 2);//����λ��
	background->setScale(1.0f, 1.0f);
	scene->addChild(background);//��������ӵ�������
	SceneManager::enter(scene);//���볡��
}
void button() {
	auto startbutton = gcnew Button;//��ʼ��ť
	startbutton->setNormal(gcnew Sprite(L"pic//start1.png"));//��̬
	startbutton->setSelected(gcnew Sprite(L"pic//start2.png"));//ѡ��ʱ
	startbutton->setPos(Window::getWidth() / 2, Window::getHeight() - 80);//����λ��
	scene->addChild(startbutton);//����ť���볡��
}
int main() {
	Logger::showConsole(false);//���ؿ���̨
	if (Game::init(L"GAME", 640, 480)) {
		std::cout << " Initialize the success!" << std::endl;
		Node::setDefaultAnchor(0.5f, 0.5f);
		EnterScene();
		button();
		//��������Ϸ����
		
		//��������Ϸ����
		Game::start();
	}
	Game::destroy();
	return 0;
}
