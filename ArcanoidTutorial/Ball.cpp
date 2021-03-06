#include "stdafx.h"
#include "Ball.h"


Ball::Ball(float t_X, float t_Y)		///konstruktor
{
	shape.setPosition(t_X, t_Y);
	shape.setRadius(this->ballRadious);
	shape.setFillColor(Color::White);
	shape.setOrigin(this->ballRadious, this->ballRadious);		/// ust domyslnie lewy gorny rog , obracanie 
}

void Ball::draw(RenderTarget& target, RenderStates state) const
{
	target.draw(this->shape, state);
}

void Ball::update()
{
	shape.move(this->velocity);

	if (this->left() < 0)		   ///kolizje kulki ze scianami
	{
	velocity.x = ballVelocity;
	}
	else if (this->right() > 800)
	{
		velocity.x = -ballVelocity;
	}

	if (this->top() < 0)		   
	{
	velocity.y = ballVelocity;
	}
	else if (this->bottom() > 600)
	{
		velocity.y = -ballVelocity;
	}
}

float Ball::left()
{
	return this->shape.getPosition().x - shape.getRadius();		//od kulki odejmujemy jej promien
}
float Ball::right()
{
	return this->shape.getPosition().x + shape.getRadius();
}
float Ball::top()
{
	return this->shape.getPosition().y - shape.getRadius();
}
float Ball::bottom()
{
	return this->shape.getPosition().y + shape.getRadius();
}