#ifndef BALL_HPP
#define BALL_HPP

class Ball
{
  private:
    float mass;
    float acceleration[2];
    float velocity[2];
    float position[2];
    float color[3];
    float totalVelocity;
    float especularity[4];

  public:
    Ball();
    void draw();
};

#endif
