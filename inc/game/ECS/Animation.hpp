#ifndef ANIMATION_HPP
#define ANIMATION_HPP

struct Animation
{
   int index;
   int frames;
   int speed;
   Animation() {}
   Animation(int index, int f, int s)
   {
      index = index;
      frames = f;
      speed = s;
   }
};

#endif
