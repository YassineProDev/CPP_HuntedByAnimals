#ifndef POSITION_H
#define POSITION_H

class position
{
public:
    position();
    position(int x, int y);
    position (const position &p);
    int getX() const;
    int getY() const;
    void setX(int x);
    void setY(int y);
    position& operator=(const position& p);
    bool operator==(const position& other) const;

private:
    int d_x, d_y;
};



#endif // POSITION_H
