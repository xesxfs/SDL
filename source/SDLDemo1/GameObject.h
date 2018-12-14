
#ifndef __GameObject__
#define __GameObject__
class GameObject
{
public:
    GameObject() {}
    ~GameObject() {}
    void draw()
    {
        std::cout << "draw game object";
    }
    void update()
    {
        std::cout << "update game object";
    }
    void clean()
    {
        std::cout << "clean game object";
    }
protected:
    int m_x;
    int m_y;
}
#endif
