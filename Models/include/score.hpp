#ifndef SCORE_HPP
#define SCORE_HPP

class Score
{
  public:
    Score();
    void draw();

    void increase();
    void reset();

  private:
    int score;
};

#endif
