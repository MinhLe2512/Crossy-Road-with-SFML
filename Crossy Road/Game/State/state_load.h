#ifndef _state_load_h
#define _state_load_h
#include<array>
#include"../../Framework/GUI/button.h"
#include"../../Framework/GUI/StackMenu.h"
#include"../../Framework/AssetManager/asset.h"
#include"../../Framework/State/state_base.h"
constexpr auto save_lane = 4;
class SaveInf {
private:
	unsigned						m_level;
	unsigned						m_score;	
	std::array<float, save_lane>	m_speed;
	std::array<int, save_lane>		m_type;
public:
	SaveInf() = default;
	SaveInf(unsigned level, unsigned score, 
	const std::array<int, save_lane>& lane_type, const std::array<float, save_lane>& lane_speed);
	SaveInf(const SaveInf&);
	unsigned	get_level() const;
	unsigned	get_score() const;
	float		get_speed(size_t)	const;
	int			get_type(size_t)	const;
};
//case1
//menu->load(m_change=stateplaying)
//menu->load<->m_change
//menu->stateplaying
//case2
//menu->stateplaying->load
//menu->stateplaying->load(m_change=stateplaying)
//menu->stateplaying->(popped)
//menu->stateplaying<->m_change
//menu->NEW_stateplaying
class state_load :public state_base {
private:
	StackMenu load_menu;
public:
	state_load(Game&);

	void handleEvent(sf::Event e)			override;
	void update(sf::Time delta_time)		override;
	void draw(sf::RenderTarget& renderer)	override;
};
#endif // !_state_load_h