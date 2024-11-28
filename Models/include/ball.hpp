#ifndef BALL_HPP
#define BALL_HPP

class Ball
{
  private:
    float Massa;
    float Aceleracao[2];
    float Velocidade[2];
    float Posicao[2];
    float Cor[3];
    float VelocidadeTotal;
    float especularidade[4];

  public:
    Ball();
    void draw();
};

#endif
