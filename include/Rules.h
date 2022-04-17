#pragma once
#include"State.h"

class Rules : public State
{
public:
	Rules();
	~Rules();
	virtual void pollEvents(sf::RenderWindow& window, const sf::Event& event) override;
	virtual void draw(sf::RenderWindow& window) override;
	virtual void update() override {}
};