#pragma once
class Layer
{
public:
	Layer();

	virtual void render() = 0;
	virtual void update() = 0;
protected:
	virtual~Layer();
};

