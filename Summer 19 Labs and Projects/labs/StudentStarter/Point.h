#ifndef POINT_H
#define POINT_H
class Point
{
    private:

        int x, y;
    
    public:
        /*Point Constructor*/
        Point(int x = 0, int y = 0);
        /*setters and getters used by the circle class to assess the x and y 
         *variaables*/
        void setX(int x);
        void setY(int y);

        int getX() const;
        int getY() const;

    
};




#endif