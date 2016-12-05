#include "Ball.hpp"
#include "Bounce.hpp"
#include <cstdlib>

Ball::Ball(SDL_Renderer *renderer, const Pad &pad)
    : x_(100)
    , y_(200)
    , action_(Action::Move)
    , pad_(pad)
    , isLost_(false)
{
    loadTexture(renderer, "ball.png");
    timer_.start(Timer::Miliseconds(5));
    setAngle(280);
}

void Ball::setAngle(int angle)
{
    angle_ = angle;
    radian_ = (angle_ * 0.0174532925);
}

SDL_Rect Ball::getRect() const
{
    return
    {
        static_cast<int>(x_),
        static_cast<int>(y_),
        width_,
        height_
    };
}

void Ball::updatePosition()
{
    while (timer_.pop())
    {
        do
        {
            x_ += std::cos(radian_);
            y_ += std::sin(radian_);
        }
        while (checkCollisions());
    }
}

bool Ball::checkCollisions()
{
    const SDL_Rect &ball = getRect();

    if (checkArenaCollisions(ball))
        return true;
    if (checkPadCollision(ball))
        return true;

    return false;
}

bool Ball::checkArenaCollisions(const SDL_Rect &ball)
{
    Bounce bounce{angle_};
        
    if (ball.x < 0)
    {
        setAngle(bounce.hitToLeft());
        return true;
    }
    else if (ball.x + ball.h > 400)
    {
        setAngle(bounce.hitToRight());
        return true;
    }
    else if (ball.y < 0)
    {
        setAngle(bounce.hitToTop());
        return true;
    }
    else if (ball.y + ball.h > 500)
    {
        isLost_ = true;
    }

    return false;
}

bool Ball::checkPadCollision(const SDL_Rect &ball)
{
    const SDL_Rect &pad = pad_.getRect();
    SDL_Rect collision;

    if (SDL_IntersectRect(&ball, &pad, &collision))
    {
        Bounce bounce{angle_};
        setAngle(bounce.hitToPad(ball, pad));
        return true;
    }
    return false;
}
