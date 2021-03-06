#ifndef _STATE_SAVE_H
#define _STATE_SAVE_H
#include"state_load.h"
#include<fstream>
#include"../../Framework/GUI/button.h"
#include"../../Framework/GUI/StackMenu.h"
#include"../../Framework/AssetManager/asset.h"
#include"../../Framework/State/state_base.h"
#include"../../Framework/GUI/TextBox.h"
constexpr auto SAVE_FILE_NAME = "D:\\";
class state_save :public state_base {
private:
	StackMenu save_menu;
	SaveInf _info;
	std::string _name;
public:
	state_save(Game&,SaveInf& _save);
	void handleEvent(sf::Event e)			override;
	void update(sf::Time delta_time)		override;
	void draw(sf::RenderTarget& renderer)	override;
	void WritetoFile(std::string name);
};
#endif // !_STATE_SAVE_H
