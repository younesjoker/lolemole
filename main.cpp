#include<SFML/Graphics.hpp>
#include<iostream>

using namespace sf;
Vector2i Up(0,-1);
Vector2i Down(0,1);
Vector2i Right(1,0);
Vector2i Left(-1,0);
Vector2f offset(184,259);

Vector2i DIR[4] = {Up,Right,Down,Left};

class pipe
{
    public:
  std::vector<Vector2i> dirs;
  int orientation;
  float angle;
  bool on;

  pipe() {angle=0;}

  void rotate()
  {
    for(int i=0;i<dirs.size();i++)
      if (dirs[i]==Up)  dirs[i]=Right;
      else if (dirs[i]==Right) dirs[i]=Down;
      else if (dirs[i]==Down)  dirs[i]=Left;
      else if (dirs[i]==Left)  dirs[i]=Up;
  }
};
pipe grid[4][4];
pipe& cell(Vector2i v) {return grid[v.x][v.y];}
bool isOut(Vector2i v) {return !IntRect(0,0,4,4).contains(v);}



    int main()
    {
srand(time(0));
int ran[4][4];
for(int i=0;i<4;i++)
    for(int j=0;j<4;j++)
{
    ran[i][j]=rand()%3;
}
    Texture t1;
    t1.loadFromFile("images/1.png");
    t1.setSmooth(true);
    Sprite sknees(t1);
    sknees.setOrigin(64,64);
    Texture t2;
    t2.loadFromFile("images/2.png");
    t2.setSmooth(true);
    Sprite ssimple(t2);
    ssimple.setOrigin(64,64);

    Texture t3;
    t3.loadFromFile("images/3.png");
    t3.setSmooth(true);
    Sprite spelas(t3);
    spelas.setOrigin(64,64);
    Texture tb;
    tb.loadFromFile("images/back.png");
    tb.setSmooth(true);
    Sprite backg(tb);
    Texture doresh;
    doresh.loadFromFile("images/door.png");
    doresh.setSmooth(true);
    Sprite sdoresh(doresh);
    sdoresh.setOrigin(25,306);
    Texture tbo;
    Texture dooreshh;
    dooreshh.loadFromFile("images/dor.png");
    dooreshh.setSmooth(true);
    Sprite sdooresh(dooreshh);
    sdooresh.setOrigin(306,25);
    Texture back2;
    back2.loadFromFile("images/back2.png");
    back2.setSmooth(true);
    Sprite back22(back2);
    back22.setOrigin(260,260);
    for(int i=0;i<4;i++)
     for(int j=0;j<4;j++)
       {
         pipe &p = grid[j][i];
         for(int n=0;n<rand()%4;n++)
          {grid[j][i].orientation++; grid[j][i].rotate();}
       }
        RenderWindow app(VideoMode(750, 900), "The Pipe Puzzle!");

    while (app.isOpen()){
    app.draw(backg);
    back22.setPosition(375,450);

        app.draw(back22);

            Event e;
        while(app.pollEvent(e))
        {
            if (e.type == Event::Closed)
                app.close();
                if (e.type == Event::MouseButtonPressed)
				if (e.key.code == Mouse::Left)
                  {
                    Vector2i pos = Mouse::getPosition(app) + Vector2i(64,64) - Vector2i(offset);
                    pos/=128;
                    if (isOut(pos)) continue;
                    cell(pos).orientation++;

                }
    }

    for(int i=0;i<4;i++)
         for(int j=0;j<4;j++)
           {

            pipe &p = grid[j][i];
            int kind = ran[i][j];
            if(kind==0)
            {
            p.angle+=1;
            if (p.angle>p.orientation*90)
            p.angle=p.orientation*90;
            sknees.setRotation(p.angle);
            sknees.setPosition(j*128,i*128);
            sknees.move(offset);
            app.draw(sknees);
            }
            if(kind==1)
            {
            p.angle+=1;
            if (p.angle>p.orientation*90)
            p.angle=p.orientation*90;

            ssimple.setRotation(p.angle);
            ssimple.setPosition(j*128,i*128);
            ssimple.move(offset);
            app.draw(ssimple);
            }
            if(kind==2)
            {
            p.angle+=1;
            if (p.angle>p.orientation*90)
            p.angle=p.orientation*90;
            spelas.setRotation(p.angle);
            spelas.setPosition(j*128,i*128);
            spelas.move(offset);
            app.draw(spelas);
            }

        sdooresh.setPosition(375,731);
        app.draw(sdooresh);
        sdoresh.setPosition(656,450);
        app.draw(sdoresh);
        sdooresh.setPosition(375,169);
        app.draw(sdooresh);
        sdoresh.setPosition(94,450);
        app.draw(sdoresh);




        }
        app.display();
        app.clear();

        }}
