#include <iostream>
#include <queue>
using namespace std;
class Node
{
public:
    Node(int x, int y, int step = 0) : m_x(x), m_y(y), m_step(step)
    {
    }
    Node(const Node &node)
    {
        if (this != &node)
        {
            m_x = node.m_x;
            m_y = node.m_y;
            m_step = node.m_step;
        }
    }
    int GetX()
    {
        return m_x;
    }
    void SetX(int x)
    {
        m_x = x;
    }
    int GetY()
    {
        return m_y;
    }
    void SetY(int y)
    {
        m_y = y;
    }
    int GetStep()
    {
        return m_step;
    }
    void SetStep(int step)
    {
        m_step = step;
    }

private:
    int m_x;
    int m_y;
    int m_step;
};
int PommelHorse(Node &start, Node &end)
{
    queue<Node> q;
    start.SetStep(0);
    q.push(start);
    int board[8][8] = {0};
    board[start.GetX()][start.GetY()] = 1;
    int direction[8][2] = {{1, 2}, {2, 1}, {1, -2}, {-2, 1}, {-1, 2}, {2, -1}, {-2, -1}, {-1, -2}};
    while (!q.empty())
    {
        Node current = q.front();
        q.pop();
        if (current.GetX() == end.GetX() && current.GetY() == end.GetY())
        {
            return current.GetStep();
        }
        for (int i = 0; i < 8; i++)
        {
            Node next(current.GetX() + direction[i][0], current.GetY() + direction[i][1], current.GetStep() + 1);
            if (next.GetX() < 1 || next.GetX() > 8 || next.GetY() < 1 || next.GetY() > 8)
            {
                continue;
            }
            if (board[next.GetX()][next.GetY()] == 1)
            {
                continue;
            }
            q.push(next);
        }
    }
    return -1;
}
int main()
{
    string sourcePoint = "";
    string destinationPoint = "";
    while (cin >> sourcePoint >> destinationPoint)
    {
        Node start(sourcePoint[1] - '0', sourcePoint[0] - 'a' + 1);
        Node end(destinationPoint[1] - '0', destinationPoint[0] - 'a' + 1);
        cout << sourcePoint << "==>" << destinationPoint << ": " << (sourcePoint == destinationPoint ? 0 : PommelHorse(start, end)) << " moves" << endl;
    }
    return 0;
}